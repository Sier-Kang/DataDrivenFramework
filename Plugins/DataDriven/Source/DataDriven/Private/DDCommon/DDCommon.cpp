// Fill out your copyright notice in the Description page of Project Settings.

#include "DDCommon.h"


UDDCommon* UDDCommon::DDInst = NULL;

UDDCommon* UDDCommon::Get()
{
	/************************************************************************/
	/* ��һ�ַ��� ʹ��GEngine->GameSingleton, ��ʱ����һ��, ��Ҫ�ڱ༭������, ����ֻ����һ��, ��ò���
				if (!DDInst) DDInst = Cast<UDDCommon>( GEngine->GameSingleton );
	������:  https://wiki.unrealengine.com/Global_Data_Access,_Data_Storage_Class_Accessible_From_Any_CPP_or_BP_Class_During_Runtime
	*/
	/************************************************************************/

	if (!DDInst) {
		DDInst = NewObject<UDDCommon>();
		DDInst->AddToRoot();
	}
	return DDInst;
}

ADDGameMode* UDDCommon::GetDDGameMode()
{
	return DDGameMode;
}

UWorld* UDDCommon::GetDDWorld()
{
	return DDWorld;
}

void UDDCommon::SetDDWorld(UWorld* World)
{
	DDWorld = World;
}

void UDDCommon::SetDDGameMode(ADDGameMode* GameMode)
{
	DDGameMode = GameMode;
}

