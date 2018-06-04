// Fill out your copyright notice in the Description page of Project Settings.

#include "DDModule.h"
#include "DDManager.h"
#include "DDBaseObject.h"


// Sets default values for this component's properties
UDDModule::UDDModule()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//�������к���
	bWantsInitializeComponent = true;

}


void UDDModule::ModuleBeginPlay()
{
	////��ģ���Լ��ڲ���BeginPlay�������ุ��ģ���ע��
	//for (int i = 0; i < GetAttachChildren().Num(); ++i)
	//{
	//	if (Cast<UDDModule>(GetAttachChildren()[i]))
	//		Manager->RegisterChildModule(Cast<UDDModule>(GetAttachChildren()[i]));
	//}
	////ע�Ḹ��
	//if (Cast<UDDModule>(GetAttachParent())) Manager->RegisterSuperModule(Cast<UDDModule>(GetAttachParent()));
	//���������һ��Manger��BeginPlay����,����ȷ��ģ���Ѿ�����,���Ƕ���һ���Ѿ�����
	Manager->ManagerBeginPlay();
}

void UDDModule::ModuleTick(float DeltaSeconds)
{
	//����Manager��Tick����
	Manager->ManagerTick(DeltaSeconds);
}


bool UDDModule::RegisterObject(DDBaseObject* Object)
{
	//������Module��ID����Ʒ��ID����ͬ,ֱ�ӷ���false
	if (Object->GetModuleIndex() != ModuleIndex) return false;
	//���߹�������Ӷ�������
	Manager->RegisterObject(Object);
	//���Լ�ע�ᵽ�����ģ��
	Object->AssignModule(this);
	return true;
}

void UDDModule::CreateManager()
{
	//ʵ�������������
	if (ManagerClass) Manager = NewObject<UDDManager>(this, ManagerClass);
}

void UDDModule::ChangeModuleType(FString ModuleType)
{
	ModuleIndex = DDHelper::GetEnumIndexFromString(ModuleType, GetName());

	if (ModuleIndex < 0) {
		DDHelper::Debug(FString("Generate Module Index Error --> ") + GetName(), 120.f);
	}
	/*else {
		DDHelper::Debug(GetName() + FString(" Generate Module Index As --> ") + FString::FromInt(ModuleIndex), 120.f);
	}*/
}

void UDDModule::ExecuteFunction(FDDModuleAgreement* Agreement, FDDParam* Param)
{
	//������Ǳ���ģ��,ֱ�ӷ���
	if (Agreement->ModuleIndex != ModuleIndex) return;
	//����Manager��UFunction
	UFunction* ExeFunc = Manager->FindFunction(FName(*Agreement->FunctionName));
	//����������ھ�ִ��
	if (ExeFunc) {
		Manager->ProcessEvent(ExeFunc, Param);
	}
	else {
		//���������ھ����ý��ΪNoModFunc
		Param->Result = ECallResult::NoFunction;
	}
}

void UDDModule::ExecuteFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	//������Ǳ���ģ��,ֱ�ӷ���
	if (Agreement->ModuleIndex != ModuleIndex) return;
	//ֱ��ִ��Manger��ִ�ж��󷽷�
	Manager->ExecuteObjectFunction(Agreement, Param);
}

