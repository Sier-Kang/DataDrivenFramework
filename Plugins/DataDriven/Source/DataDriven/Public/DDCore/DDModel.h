// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDModel.generated.h"

class UDDModule;
class IDDOO;

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDModel : public UObject
{
	GENERATED_BODY()

public:

	////ע�Ḹ��ģ��
	//void RegisterSuperModule(UDDModule* SuperMod);
	////ע�ᵥ������ģ��
	//void RegisterChildModule(UDDModule* ChildMod);
	//ע�����
	void RegisterObject(IDDOO* ObjectInst);
	//���ݵ�Tick����
	virtual void ModelTick(float DeltaSeconds);
	//�������ֻ�ȡ����
	void GetSelfObject(TArray<FString> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������ֻ�ȡ��������,����ȫ�����������
	int32 GetOtherObject(TArray<FString> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������������ȡ��ͬ�����������,���������Ķ��������
	int32 GetClassOtherObject(TArray<FString> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������ֻ�ȡ��Ķ���
	void GetSelfClass(TArray<FString> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	//�������ֻ�ȡ���������Ķ���
	void GetOtherClass(TArray<FString> ObjectNameGroup, TArray<IDDOO*>& TargetObjectGroup);
	
	//���ٶ���
	void DestroyObject(EAgreementType Agreement, TArray<FString> ObjectNameGroup);

	//����ȫ�����������
	int32 GetObjectGroupNum() const;
	//����ĳ����Ķ��������
	int32 GetClassObjectGroupNum(FString ObjectClassName) const;

protected:

	//��������ɾ������
	void RemoveObject(FString ObjectName);
	//��������ɾ���༯��
	void RemoveObjectClass(FString ObjectClassName);

protected:

	////����ģ��
	//UDDModule* SuperModule;
	////�Ӽ�ģ��
	//TMap<int32, UDDModule*> ChildModule;
	//ģ�����
	TMap<FString, IDDOO*> ObjectGroup;
	//ģ�������
	TMap<FString, TArray<IDDOO*>> ObjectClassGroup;

	//�ȴ��������ڵĶ���
	TArray<IDDOO*> ObjectLifeGroup;
	//����Tick�����Ķ���
	TArray<IDDOO*> ObjectTickGroup;

	//�����������ڵĶ���
	TArray<IDDOO*> ObjectDestroyGroup;
	//�ͷ����ں���,ִֻ��һ�ξ�ȫ���ͷ�
	TArray<IDDOO*> ObjectReleaseGroup;
	//��ʱ�����������ڵĶ���,ȷ���Ѿ����������
	TArray<IDDOO*> PreObjectDestroyGroup;

};
