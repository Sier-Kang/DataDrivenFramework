// Fill out your copyright notice in the Description page of Project Settings.

#include "DDManager.h"
#include "DDMessage.h"
#include "DDModel.h"
#include "DDBaseObject.h"



UDDManager::UDDManager()
{
	//�������
	InitManagerComponent();
}

void UDDManager::ManagerBeginPlay()
{

}

void UDDManager::ManagerTick(float DeltaSeconds)
{
	//�������ݵ�Tick����
	Model->ModelTick(DeltaSeconds);
}

void UDDManager::InitManagerComponent()
{
	//�������,������Ҫ��д
	Model = NewObject<UDDModel>();
	Message = NewObject<UDDMessage>();
}

void UDDManager::ExecuteObjectFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	switch (Agreement->AgreementType)
	{
	case EAgreementType::SelfObject:
		ExecuteSelfObject(Agreement, Param);
		break;
	case EAgreementType::OtherObject:
		ExecuteOtherObject(Agreement, Param);
		break;
	case EAgreementType::ClassOtherObject:
		ExecuteClassOtherObject(Agreement, Param);
		break;
	case EAgreementType::SelfClass:
		ExecuteSelfClass(Agreement, Param);
		break;
	case EAgreementType::OtherClass:
		ExecuteOtherClass(Agreement, Param);
		break;
	}
}

void UDDManager::DestroyObject(ECallResult& Result, EAgreementType Agreement, TArray<FString> ObjectNameGroup)
{
	Model->DestroyObject(Agreement, &ObjectNameGroup);
}

void UDDManager::RegisterObject(DDBaseObject* Object)
{
	//ע������������
	Model->RegisterObject(Object);
}

void UDDManager::ExecuteSelfObject(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//����洢Ŀ��������
	TArray<DDBaseObject*> TargetObjectGroup;
	//�����������ȡ������
	Model->GetSelfObject(&Agreement->ObjectGroup, TargetObjectGroup);
	//ѭ�������¼�
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//��ȡ����
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//ִ�з���
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//���û�з��������õ��ý��Ϊû�ж�Ӧ����
			Param->Result = ECallResult::NoFunction;
		}
	}
	//�����ȡ�Ķ����봫��Ķ��������������,������ȼ����
	if (TargetObjectGroup.Num() != Agreement->ObjectGroup.Num()) Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//����洢Ŀ��������
	TArray<DDBaseObject*> TargetObjectGroup;
	//�����������ȡ������
	int32 TotalObjectNum = Model->GetOtherObject(&Agreement->ObjectGroup, TargetObjectGroup);
	//ѭ�������¼�
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//��ȡ����
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//ִ�з���
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//���û�з��������õ��ý��Ϊû�ж�Ӧ����
			Param->Result = ECallResult::NoFunction;
		}
	}
	//��������Ͳ���ͬ˵�����ݲ�ƥ��
	if (Agreement->ObjectGroup.Num() + TargetObjectGroup.Num() != TotalObjectNum)Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteClassOtherObject(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//����洢Ŀ��������
	TArray<DDBaseObject*> TargetObjectGroup;
	//�����������ȡ������
	int32 TotalClassNum = Model->GetClassOtherObject(&Agreement->ObjectGroup, TargetObjectGroup);
	//ѭ�������¼�
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//��ȡ����
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//ִ�з���
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//���û�з��������õ��ý��Ϊû�ж�Ӧ����
			Param->Result = ECallResult::NoFunction;
		}
	}
	//��������Ͳ���ͬ˵�����ݲ�ƥ��
	if (Agreement->ObjectGroup.Num() + TargetObjectGroup.Num() != TotalClassNum)Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteSelfClass(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//����洢Ŀ��������
	TArray<DDBaseObject*> TargetObjectGroup;
	//�����������ȡ������
	Model->GetSelfClass(&Agreement->ObjectGroup, TargetObjectGroup);
	//ѭ�������¼�
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//��ȡ����
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//ִ�з���
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//���û�з��������õ��ý��Ϊû�ж�Ӧ����
			Param->Result = ECallResult::NoFunction;
		}
	}
	//�������Ϊ0
	if (TargetObjectGroup.Num() == 0) Param->Result = ECallResult::LackObject;
}

void UDDManager::ExecuteOtherClass(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//����洢Ŀ��������
	TArray<DDBaseObject*> TargetObjectGroup;
	//�����������ȡ������
	Model->GetOtherClass(&Agreement->ObjectGroup, TargetObjectGroup);
	//ѭ�������¼�
	for (int i = 0; i < TargetObjectGroup.Num(); ++i) {
		//��ȡ����
		UFunction* ExeFunc = TargetObjectGroup[i]->GetObjectBody()->FindFunction(FName(*Agreement->FunctionName));
		if (ExeFunc) {
			//ִ�з���
			TargetObjectGroup[i]->GetObjectBody()->ProcessEvent(ExeFunc, Param);
		}
		else {
			//���û�з��������õ��ý��Ϊû�ж�Ӧ����
			Param->Result = ECallResult::NoFunction;
		}
	}
	//�������Ϊ0
	if (TargetObjectGroup.Num() == 0) Param->Result = ECallResult::LackObject;
}

//void UDDManager::RegisterSuperModule(UDDModule* SuperMod)
//{
//	//ע�Ḹģ�鵽���ݲ�
//	Model->RegisterSuperModule(SuperMod);
//}
//
//void UDDManager::RegisterChildModule(UDDModule* ChildMod)
//{
//	//ע������ģ�鵽���ݲ�
//	Model->RegisterChildModule(ChildMod);
//}

template<typename ModelClass>
ModelClass* UDDManager::GetModel()
{
	ModelClass* Result = Cast<ModelClass>(Model);
	if (Result) return Result;
	return NULL;
}

template<typename MessageClass>
MessageClass* UDDManager::GetMessage()
{
	MessageClass* Result = Cast<MessageClass>(Message);
	if (Result) return Result;
	return NULL;
}


