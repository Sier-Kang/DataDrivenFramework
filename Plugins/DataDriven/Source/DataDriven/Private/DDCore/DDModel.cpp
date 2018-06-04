// Fill out your copyright notice in the Description page of Project Settings.

#include "DDModel.h"
#include "DDBaseObject.h"
#include "DDModule.h"



//void UDDModel::RegisterSuperModule(UDDModule* SuperMod)
//{
//	SuperModule = SuperMod;
//}
//
//void UDDModel::RegisterChildModule(UDDModule* ChildMod)
//{
//	//��ӵ���ģ��
//	ChildModule.Add(ChildMod->ModuleIndex, ChildMod);
//}

void UDDModel::RegisterObject(DDBaseObject* ObjectInst)
{
	//������ظ�����ӵ�ģ�����
	if (!ObjectGroup.Contains(ObjectInst->GetObjectName()))
	{
		ObjectGroup.Add(ObjectInst->GetObjectName(), ObjectInst);
		//��ӵ�ģ�������
		FString ObejctClassName = ObjectInst->GetClassName();
		if (ObjectClassGroup.Contains(ObejctClassName))
		{
			ObjectClassGroup.Find(ObejctClassName)->Add(ObjectInst);
		}
		else {
			TArray<DDBaseObject*> ObejctArray;
			ObjectClassGroup.Add(ObejctClassName, ObejctArray);
			ObjectClassGroup.Find(ObejctClassName)->Add(ObjectInst);
		}
		//��Ӷ�������������
		ObjectLifeGroup.Add(ObjectInst);
	}
	else {
		//������ظ��ľ������Bug
		DDHelper::Debug(FString("Object Repeated --> ") + ObjectInst->GetObjectName(), 120.f);
	}
}

void UDDModel::ModelTick(float DeltaSeconds)
{
	//����������������������ں���
	TArray<DDBaseObject*> TempObjectGroup;
	for (int i = 0; i < ObjectLifeGroup.Num(); ++i)
	{
		//�������ɹ�
		if (ObjectLifeGroup[i]->ActiveLife()) {
			TempObjectGroup.Add(ObjectLifeGroup[i]);
		}
	}
	//���������������ڵĶ����Ƴ�����������,���ҽ�����Tick���еĶ�����ӵ�Tick��
	for (int i = 0; i < TempObjectGroup.Num(); ++i)
	{
		ObjectLifeGroup.Remove(TempObjectGroup[i]);
		if (TempObjectGroup[i]->IsAllowTickEvent)
		{
			ObjectTickGroup.Add(TempObjectGroup[i]);
		}
	}
	//����Tick���Tick����
	for (int i = 0; i < ObjectTickGroup.Num(); ++i)
	{
		ObjectTickGroup[i]->ObjectTick(DeltaSeconds);
	}


	//�����ͷŶ�������ͷź���,�����������ͷŶ�����,��Ϊ��Щָ����ͷ�,����Ҫ�ٱ���
	for (int i = 0; i < ObjectReleaseGroup.Num(); ++i) {
		ObjectReleaseGroup[i]->OnRealse();
	}
	ObjectReleaseGroup.Empty();


	//�����ʱ����
	TempObjectGroup.Empty();
	//����Ԥ����,������ȶ�״̬,��ת����ʱ������
	for (int i = 0; i < PreObjectDestroyGroup.Num(); ++i)
	{
		if (PreObjectDestroyGroup[i]->RunState == EBaseObjectState::Stable)
		{
			//����ȶ�����״̬�Ķ�����ʱ������
			TempObjectGroup.Add(PreObjectDestroyGroup[i]);
			//����ȶ�����״̬�Ķ������ٽ�����
			ObjectDestroyGroup.Add(PreObjectDestroyGroup[i]);
		}
	}
	//��Ԥ����������������ȶ�״̬������
	for (int i = 0; i < TempObjectGroup.Num(); ++i)
	{
		PreObjectDestroyGroup.Remove(TempObjectGroup[i]);
	}
	//�������ٶ���������ٺ���
	for (int i = 0; i < ObjectDestroyGroup.Num(); ++i) {
		//����Ѿ����е��ͷ�״̬
		if (ObjectDestroyGroup[i]->DestroyLife()) {
			//��ӵ��ͷŶ�����
			ObjectReleaseGroup.Add(ObjectDestroyGroup[i]);
			//��ObjectGroup��ObjectClassGroup�Ƴ�����
			ObjectGroup.Remove(ObjectDestroyGroup[i]->GetObjectName());
			if (ObjectClassGroup.Contains(ObjectDestroyGroup[i]->GetClassName())) ObjectClassGroup.Find(ObjectDestroyGroup[i]->GetClassName())->Remove(ObjectDestroyGroup[i]);
		}
	}

}

void UDDModel::GetSelfObject(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	for (int i = 0; i < (*ObjectNameGroup).Num(); ++i)
	{
		if (ObjectGroup.Contains((*ObjectNameGroup)[i])) TargetObjectGroup.Add(*ObjectGroup.Find((*ObjectNameGroup)[i]));
	}
}

int32 UDDModel::GetOtherObject(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	//�Ѷ��������봫��������鲻��ͬ�Ķ���ȫ���浽TargetObjectGroup
	for (TMap<FString, DDBaseObject*>::TIterator It(ObjectGroup); It; ++It) {
		bool IsSame = false;
		for (int i = 0; i < (*ObjectNameGroup).Num(); ++i)
		{
			//ֻҪ������ͬ�ľ���������
			if ((*ObjectNameGroup)[i].Equals(It->Key)) { IsSame = true; break; }
		}
		if (!IsSame) TargetObjectGroup.Add(It->Value);
	}
	//����ȫ�����������
	return GetObjectGroupNum();
}

int32 UDDModel::GetClassOtherObject(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	//�ֻ�ȡ����
	FString ObjectClassName = (*ObjectGroup.Find((*ObjectNameGroup)[0]))->GetClassName();
	//�����������
	for (TArray<DDBaseObject*>::TIterator It(*ObjectClassGroup.Find(ObjectClassName)); It; ++It)
	{
		bool IsSame = false;
		for (int i = 0; i < (*ObjectNameGroup).Num(); ++i)
		{
			//����洢�Ķ�����ͬ������
			if (*It == *ObjectGroup.Find((*ObjectNameGroup)[i])) { IsSame = true; break; }
		}
		if (!IsSame) TargetObjectGroup.Add(*It);
	}
	//���������Ķ�������
	return GetClassObjectGroupNum(ObjectClassName);
}

void UDDModel::GetSelfClass(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	for (int i = 0; i < (*ObjectNameGroup).Num(); ++i) {
		//��������������,ֱ��������һ��ѭ��
		if (!ObjectClassGroup.Contains((*ObjectNameGroup)[i])) continue;
		//ѭ�������ȥ����TargetObjectGroup
		for (TArray<DDBaseObject*>::TIterator It(*ObjectClassGroup.Find((*ObjectNameGroup)[i])); It; ++It)
		{
			TargetObjectGroup.Add(*It);
		}
	}
}

void UDDModel::GetOtherClass(TArray<FString>* ObjectNameGroup, TArray<DDBaseObject*>& TargetObjectGroup)
{
	for (TMap<FString, TArray<DDBaseObject*>>::TIterator It(ObjectClassGroup); It; ++It) {
		bool IsSame = false;
		for (int i = 0; i < (*ObjectNameGroup).Num(); ++i) {
			if ((*ObjectNameGroup)[i].Equals(It->Key)) { IsSame = true; break; }
		}
		//�������������������봫���������ͬ,������һ��ѭ��
		if (IsSame) continue;
		//�������������������봫�����������ͬ,��ӵ�TargetObjectGroup
		for (TArray<DDBaseObject*>::TIterator Ih(It->Value); Ih; ++Ih) {
			TargetObjectGroup.Add(*Ih);
		}
	}
}

void UDDModel::DestroyObject(EAgreementType Agreement, TArray<FString>* ObjectNameGroup)
{
	TArray<DDBaseObject*> TargetObjectGroup;
	switch (Agreement)
	{
	case EAgreementType::SelfObject:
		GetSelfObject(ObjectNameGroup, TargetObjectGroup);
		break;
	case EAgreementType::OtherObject:
		GetOtherObject(ObjectNameGroup, TargetObjectGroup);
		break;
	case EAgreementType::ClassOtherObject:
		GetClassOtherObject(ObjectNameGroup, TargetObjectGroup);
		break;
	case EAgreementType::SelfClass:
		GetSelfClass(ObjectNameGroup, TargetObjectGroup);
		break;
	case EAgreementType::OtherClass:
		GetOtherClass(ObjectNameGroup, TargetObjectGroup);
		break;
	}
	//������������ӵ�PreObjectDestroyGroup����ObjectDestroyGroup
	for (int i = 0; i < TargetObjectGroup.Num(); ++i)
	{
		if (!ObjectDestroyGroup.Contains(TargetObjectGroup[i]) && !PreObjectDestroyGroup.Contains(TargetObjectGroup[i]))
		{
			//������ȶ�״̬����ӵ�ObjectDestroyGroup,����Ǽ���״̬����ӵ�PreObjectDestroyGroup
			switch (TargetObjectGroup[i]->RunState)
			{
			case EBaseObjectState::Active:
				PreObjectDestroyGroup.Add(TargetObjectGroup[i]);
				break;
			case EBaseObjectState::Stable:
				ObjectDestroyGroup.Add(TargetObjectGroup[i]);
				break;
			}
		}
	}
}

int32 UDDModel::GetObjectGroupNum() const
{
	return ObjectGroup.Num();
}

int32 UDDModel::GetClassObjectGroupNum(FString ObjectClassName) const
{
	if (ObjectClassGroup.Contains(ObjectClassName)) return (*ObjectClassGroup.Find(ObjectClassName)).Num();
	return 0;
}

void UDDModel::RemoveObject(FString ObjectName)
{
	//���û���������,ֱ�ӷ���
	if (!ObjectGroup.Contains(ObjectName)) return;
	//�Ȼ�ȡ����ָ��
	DDBaseObject* TargetObject = *ObjectGroup.Find(ObjectName);
	//���������Ƴ�����
	ObjectLifeGroup.Remove(TargetObject);
	//��֡���Ƴ�����
	ObjectTickGroup.Remove(TargetObject);
	//�������Ƴ�����
	ObjectClassGroup.Find(TargetObject->GetClassName())->Remove(TargetObject);
	//�Ӷ������Ƴ�����
	ObjectGroup.Remove(ObjectName);
}

void UDDModel::RemoveObjectClass(FString ObjectClassName)
{
	//���û�����������,ֱ�ӷ���
	if (!ObjectClassGroup.Contains(ObjectClassName)) return;
	//��ȡ���������
	TArray<DDBaseObject*>* TargetClassGroup = ObjectClassGroup.Find(ObjectClassName);
	//�����Ƴ�����
	for (int i = 0; i < (*TargetClassGroup).Num(); ++i) {
		//����������֡���Ƴ�����
		ObjectLifeGroup.Remove((*TargetClassGroup)[i]);
		ObjectTickGroup.Remove((*TargetClassGroup)[i]);
		//�Ӷ������Ƴ�����
		ObjectGroup.Remove((*TargetClassGroup)[i]->GetObjectName());
	}
	//���������Ƴ�
	ObjectClassGroup.Remove(ObjectClassName);
}
