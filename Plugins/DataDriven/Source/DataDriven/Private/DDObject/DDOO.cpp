// Fill out your copyright notice in the Description page of Project Settings.

#include "DDOO.h"
#include "UObject/NoExportTypes.h"
#include "DDGameMode.h"
#include "DDModule.h"



void IDDOO::RegisterToModule(FString ModName, FString ObjectName /*= FString()*/, FString ClassName /*= FString()*/)
{
	//���GameMode�Ѿ�����,˵���Ѿ�ע�����,ֱ�ӷ���,�����ظ�����
	if (DDGameMode) return;
	//���ģ����Ϊ��,ֱ�ӷ���
	if (ModName.IsEmpty()) return;
	//ע�������Ͷ�����
	if (!ObjectName.IsEmpty()) IObjectName = ObjectName;
	if (!ClassName.IsEmpty()) IClassName = ClassName;
	//��ȡUObject����
	Body = Cast<UObject>(this);
	//��ȡGameMode
	DDGameMode = DDHelper::GetDDGameMode();
	//ע�ᵽģ��
	if (DDGameMode)
	{
		//�����õ�IDΪ��ֱ�ӷ���
		ModuleIndex = DDHelper::GetEnumIndexFromString(DDGameMode->ModuleType, ModName);
		if (ModuleIndex < 0) {
			DDHelper::Debug(Body->GetName() + FString(" Get ") + ModName + FString(" ModuleID Failed !"), 120.f);
			return;
		}
		//���ע�᲻�ɹ�˵����û��ʵ������Ӧ��Module
		if (!DDGameMode->RegisterToModule(this))
			DDHelper::Debug(Body->GetName() + FString(" Register To ") + ModName + FString(" Failed !"), 120.f);
	}
	else {
		DDHelper::Debug(Body->GetName() + FString(" Get DDGameMode Failed !"), 120.f);
	}
}


void IDDOO::AssignModule(UDDModule* Mod)
{
	Module = Mod;
}

UObject* IDDOO::GetObjectBody() const
{
	return Body;
}

int32 IDDOO::GetModuleIndex() const
{
	return ModuleIndex;
}

FString IDDOO::GetObjectName() const
{
	return IObjectName.IsEmpty() ? Body->GetName() : IObjectName;
}

FString IDDOO::GetClassName() const
{
	return IClassName;
}


bool IDDOO::ActiveLife()
{
	switch (LifeState)
	{
	case EBaseObjectLife::None:
		DDInit();
		LifeState = EBaseObjectLife::Init;
		break;
	case EBaseObjectLife::Init:
		DDLoading();
		LifeState = EBaseObjectLife::Loading;
		break;
	case EBaseObjectLife::Loading:
		DDRegister();
		LifeState = EBaseObjectLife::Register;
		break;
	case EBaseObjectLife::Register:
		DDEnable();
		LifeState = EBaseObjectLife::Enable;
		//��������״̬Ϊ�ȶ�
		RunState = EBaseObjectState::Stable;
		return true;
	}
	return false;
}

bool IDDOO::DestroyLife()
{
	switch (LifeState)
	{
	case EBaseObjectLife::Enable:
		DDDisable();
		LifeState = EBaseObjectLife::Disable;
		//��������״̬Ϊ����
		RunState = EBaseObjectState::Destroy;
		break;
	case EBaseObjectLife::Disable:
		DDUnRegister();
		LifeState = EBaseObjectLife::UnRegister;
		break;
	case EBaseObjectLife::UnRegister:
		DDUnLoading();
		LifeState = EBaseObjectLife::UnLoading;
		return true;
	}
	return false;
}

void IDDOO::ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param)
{
	if (Agreement.ModuleIndex == ModuleIndex) {
		Module->ExecuteFunction(Agreement, Param);
	}
	else {
		DDGameMode->ExecuteFunction(Agreement, Param);
	}
}

void IDDOO::ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param)
{
	if (Agreement.ModuleIndex == ModuleIndex) {
		Module->ExecuteFunction(Agreement, Param);
	}
	else {
		DDGameMode->ExecuteFunction(Agreement, Param);
	}
}

void IDDOO::OnRealse()
{
	//����DD��ܵ��ͷź���
	DDRelease();
}

void IDDOO::OnEnable()
{
	//һ������һ��DDEnable����,������д
	DDEnable();
	//����״̬Ϊ����״̬
	LifeState = EBaseObjectLife::Enable;
}

void IDDOO::OnDisable()
{
	//һ������һ��DDDisable����,������д
	DDDisable();
	//����״̬Ϊʧ��״̬
	LifeState = EBaseObjectLife::Disable;
}

void IDDOO::ObjectTick(float DeltaSeconds) {}

//��������ϵ�к���
void IDDOO::DDInit() {}
void IDDOO::DDLoading() {}
void IDDOO::DDRegister() {}
void IDDOO::DDEnable() {}
void IDDOO::DDDisable() {}
void IDDOO::DDUnRegister() {}
void IDDOO::DDUnLoading() {}
void IDDOO::DDRelease() {}
