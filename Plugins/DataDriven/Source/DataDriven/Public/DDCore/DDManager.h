// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Common/DDCommon.h"
#include "DDManager.generated.h"

class UDDModule;
class DDBaseObject;
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
	void RegisterObject(DDBaseObject* Object);

	//ִ�е������󷽷�
	void ExecuteSelfObject(FDDObjectAgreement* Agreement, FDDParam* Param);
	//ִ��������󷽷�
	void ExecuteOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param);
	//֧����ͬ���������󷽷�
	void ExecuteClassOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param);
	//ִ�������ķ���
	void ExecuteSelfClass(FDDObjectAgreement* Agreement, FDDParam* Param);
	//ִ�����������ķ���
	void ExecuteOtherClass(FDDObjectAgreement* Agreement, FDDParam* Param);

	////ע�Ḹ��ģ��
	//void RegisterSuperModule(UDDModule* SuperMod);

	////ע�ᵥ������ģ��
	//void RegisterChildModule(UDDModule* ChildMod);

	//�����������������ĳ�ʼ��,���Ҫ�Զ����������д�������
	virtual void InitManagerComponent();

	//ִ�ж��󷽷�
	void ExecuteObjectFunction(FDDObjectAgreement* Agreement, FDDParam* Param);

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



