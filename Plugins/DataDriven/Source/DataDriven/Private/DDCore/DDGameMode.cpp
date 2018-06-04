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

	Center = CreateDefaultSubobject<UDDCenterModule>(TEXT("Center"));
	Center->SetupAttachment(RootComponent);
}

void ADDGameMode::PostInitializeComponents()
{
	//�ȵ���һ�θ���
	Super::PostInitializeComponents();
	//ע��GameMode�����絽UDDCommon
	DDHelper::DDGameMode = this;
	//����Ϸ����֮ǰ�������һ��ģ��	ID���趨
	Center->IterChangeModuleType(Center, ModuleType);
	//����Manager���
	Center->IterCreateManager(Center);
}

void ADDGameMode::BeginPlay()
{
	Super::BeginPlay();

	//��������ģ���BeginPlay����
	Center->IterModuleBeginPlay(Center);
}

void ADDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//��������ģ���Tick����
	Center->IterModuleTick(Center, DeltaSeconds);
}


void ADDGameMode::ExecuteFunction(FDDModuleAgreement* Agreement, FDDParam* Param)
{
	Center->IterExecuteFunction(Center, Agreement, Param);
}

void ADDGameMode::ExecuteFunction(FDDObjectAgreement* Agreement, FDDParam* Param)
{
	Center->IterExecuteFunction(Center, Agreement, Param);
}

#if WITH_EDITOR
void ADDGameMode::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property &&
		PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(ADDGameMode, ModuleType))
	{
		Center->IterChangeModuleType(Center, ModuleType);
	}
}
#endif

bool ADDGameMode::RegisterToModule(DDBaseObject* Object)
{
	//��������ģ��ĵ���ע�������
	return Center->IterRegisterToModule(Center, Object);
}


