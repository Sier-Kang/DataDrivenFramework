// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DDCommon/DDCommon.h"
#include "DDOO.generated.h"

class UDDModule;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDDOO : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class DATADRIVEN_API IDDOO
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//ͨ�������ModName�Ƿ�Ϊ�����ж��Ƿ��Զ�ע��
	void RegisterToModule(FString ModName, FString ObjectName = FString(), FString ClassName = FString());

	//���ⲿָ��ģ��
	void AssignModule(UDDModule* Mod);
	
	//��ȡ����
	UWorld* GetDDWorld() const;

	//��ȡObejct����
	UObject* GetObjectBody() const;

	//��ȡģ��Index
	int32 GetModuleIndex() const;

	//��ȡ��������,������д,�Լ��趨��ʽ
	virtual FString GetObjectName() const;

	//��ȡ�������
	virtual FString GetClassName() const;

	//DDOO��Tick����
	virtual void ObjectTick(float DeltaSeconds);

	//������������,����ɹ���ʱ�򷵻�true,ֹͣ����
	bool ActiveLife();

	//������������,���ٳɹ��󷵻�true,���Ҵ�ģ��ע��
	bool DestroyLife();

	//��������
	void ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param);
	//��������
	void ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param);
	//�����ͷź���
	virtual void OnRealse();
	//�������
	virtual void OnEnable();
	//ʧ�����
	virtual void OnDisable();

public:

	//�Ƿ�����֡����,���Ҫ����֡������Ҫ�ڹ��캯������BeginPlay����,��UE4��Ĭ��Ϊfalse
	bool IsAllowTickEvent;

	//����״̬
	EBaseObjectLife LifeState;

	//����״̬
	EBaseObjectState RunState;

protected:

	//��������,��ģ�����������
	virtual void DDInit();//��ʼ��
	virtual void DDLoading();//���ذ󶨵���Դ
	virtual void DDRegister();//ע�����ݻ����¼�
	virtual void DDEnable();//�������
	virtual void DDDisable();//ʧ�����
	virtual void DDUnRegister();//ע�����ݻ����¼�
	virtual void DDUnLoading();//���ٰ���Դ
	virtual void DDRelease();//�ͷ��Լ�

protected:

	//��������UObject
	UObject* Body;

	//�����Ӧ��ģ��
	UDDModule* Module;

	//����GameMode
	ADDGameMode* DDGameMode;

	//�����Ӧģ���Index
	int32 ModuleIndex;

	//��Ʒ������,�����Ϊ��,��ȡ��Ʒ���ͷ������,���Ҵ���Ʒ�ڶ�Ӧ��ModuleΨһ
	FString IObjectName;

	//����,����ڳ�ʼ��ʱһ��Ҫָ��
	FString IClassName;


};
