// Fill out your copyright notice in the Description page of Project Settings.

#include "DDGameMode.h"
#include "Default/DDCenterModule.h"
#include "DDBaseObject.h"
#include "Components/SceneComponent.h"



ADDGameMode::ADDGameMode()
{
	//����ÿ֡����
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	CenterModule = CreateDefaultSubobject<UDDCenterModule>(TEXT("CenterModule"));
	CenterModule->SetupAttachment(RootComponent);

}

void ADDGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	//��ʼ������ģ��
	CenterModule->Register();

}

void ADDGameMode::BeginPlay()
{
	Super::BeginPlay();

	//��������ģ���BeginPlay����
	CenterModule->IterModuleBeginPlay(CenterModule);
}

void ADDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//��������ģ���Tick����
	CenterModule->IterModuleTick(CenterModule, DeltaSeconds);
}

void ADDGameMode::RegisterObject(DDBaseObject* Object)
{
	ObjectGroup.Push(Object);
}


