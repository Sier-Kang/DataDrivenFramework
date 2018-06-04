// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Common/DDCommon.h"
#include "CoreMinimal.h"



class UObject;
class UDDModule;
/**
 *
 */
class DATADRIVEN_API DDBaseObject
{

public:

	//ͨ�������ModName�Ƿ�Ϊ�����ж��Ƿ��Զ�ע��
	void RegisterToModule(UObject* ObjectBody, FString ModName);

	//���ⲿָ��ģ��
	void AssignModule(UDDModule* Mod);

	//��ȡObejct����
	UObject* GetObjectBody() const;

	//��ȡģ��Index
	int32 GetModuleIndex() const;

	//��ȡ��������
	FString GetObjectName() const;

	//��ȡ�������
	FString GetClassName() const;

	//DDBaseObject��Tick����
	virtual void ObjectTick(float DeltaSeconds);

	//������������,����ɹ���ʱ�򷵻�true,ֹͣ����
	bool ActiveLife();

	//������������,���ٳɹ��󷵻�true,���Ҵ�ģ��ע��
	bool DestroyLife();

	//���б���ģ�鷽��
	void ExecuteLocalFunction(FDDModuleAgreement* Agreement, FDDParam* Param);
	//���б��ض��󷽷�
	void ExecuteLocalFunction(FDDObjectAgreement* Agreement, FDDParam* Param);
	//�������ģ�鷽��
	void ExecuteRemoteFunction(FDDModuleAgreement* Agreement, FDDParam* Param);
	//������ض��󷽷�
	void ExecuteRemoteFunction(FDDObjectAgreement* Agreement, FDDParam* Param);

public:

	//�Ƿ�����֡����,���Ҫ����֡������Ҫ�ڹ��캯������BeginPlay����,��UE4��Ĭ��Ϊfalse
	bool IsAllowTickEvent;

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

	//����״̬
	EBaseObjectLife LifeState;

};
