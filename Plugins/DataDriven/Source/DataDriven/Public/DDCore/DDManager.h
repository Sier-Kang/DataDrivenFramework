// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDCommon/DDCommon.h"
#include "DDManager.generated.h"

class UDDModule;
class IDDOO;
class UDDMessage;
class UDDModel;

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDManager : public UObject
{
	GENERATED_BODY()

public:

	UDDManager();

	//Manager��BeginPlay����
	virtual void ManagerBeginPlay();

	//Manager��Tick����
	virtual void ManagerTick(float DeltaSeconds);

	//��Ӷ���
	void RegisterObject(IDDOO* Object);

	//ִ�е������󷽷�
	void ExecuteSelfObject(DDObjectAgreement Agreement, DDParam* Param);
	//ִ��������󷽷�
	void ExecuteOtherObject(DDObjectAgreement Agreement, DDParam* Param);
	//֧����ͬ���������󷽷�
	void ExecuteClassOtherObject(DDObjectAgreement Agreement, DDParam* Param);
	//ִ�������ķ���
	void ExecuteSelfClass(DDObjectAgreement Agreement, DDParam* Param);
	//ִ�����������ķ���
	void ExecuteOtherClass(DDObjectAgreement Agreement, DDParam* Param);
	//ִ�����ж���ķ���
	void ExecuteAll(DDObjectAgreement Agreement, DDParam* Param);

	////ע�Ḹ��ģ��
	//void RegisterSuperModule(UDDModule* SuperMod);

	////ע�ᵥ������ģ��
	//void RegisterChildModule(UDDModule* ChildMod);

	//�����������������ĳ�ʼ��,���Ҫ�Զ����������д�������
	virtual void InitManagerComponent();

	//ִ�ж��󷽷�
	void ExecuteObjectFunction(DDObjectAgreement Agreement, DDParam* Param);

	//���ٶ��󷽷�,���������Э�����ͺ����ٶ���
	UFUNCTION()
		void DestroyObject(EAgreementType Agreement, TArray<FString> ObjectNameGroup);

	//������󷽷�,���������Э�����ͺͼ���Ķ���
	UFUNCTION()
		void EnableObject(EAgreementType Agreement, TArray<FString> ObjectNameGroup);

	//������󷽷�,���������Э�����ͺͼ���Ķ���
	UFUNCTION()
		void DisableObject(EAgreementType Agreement, TArray<FString> ObjectNameGroup);


public:



protected:

	//ģ���ȡ���,��Ϊ�Ǹ���ת����,���ܻ�������,���Բ������ô������
	template<typename ModelClass>
	ModelClass* GetModel();

	template<typename MessageClass>
	MessageClass* GetMessage();

protected:

	//��������ָ��
	UDDModel* Model;
	//������Ϣָ��
	UDDMessage* Message;


};



