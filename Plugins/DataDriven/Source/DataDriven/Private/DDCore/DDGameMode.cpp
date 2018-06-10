// Fill out your copyright notice in the Description page of Project Settings.

#include "DDGameMode.h"
#include "DDDefault/DDCenterModule.h"
#include "DDOO.h"
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
	//����Ϸ����֮ǰ�������һ��ģ��	ID���趨
	Center->IterChangeModuleType(Center, ModuleType);
	//����Manager���
	Center->IterCreateManager(Center);
}

void ADDGameMode::BeginPlay()
{
	Super::BeginPlay();

	//��������ģ���BeginPlay����
	Center->IterPreModuleBeginPlay(Center);
	//ע��GameInstance�����
	RegisterGameInstance();
}

void ADDGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!IsBeginPlay) {
		//��������ģ���BeginPlay����
		Center->IterModuleBeginPlay(Center);
		//��һ֡����ȫ���BeginPlay����
		IsBeginPlay = true;
	}
	else {
		//��������ģ���Tick����
		Center->IterModuleTick(Center, DeltaSeconds);
	}
}


void ADDGameMode::ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param)
{
	Center->IterExecuteFunction(Center, Agreement, Param);
}

void ADDGameMode::ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param)
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

bool ADDGameMode::RegisterToModule(IDDOO* Object)
{
	//��������ģ��ĵ���ע�������
	return Center->IterRegisterToModule(Center, Object);
}

void ADDGameMode::RegisterGameInstance()
{
	//��ȡGameInstance
	UGameInstance* GameInst = UGameplayStatics::GetGameInstance(GetWorld());
	//������ڲ��Ҽ̳���IDDOO,��ע���Center,�����Ͷ���������GameInstance
	if (GameInst && Cast<IDDOO>(GameInst))
		Cast<IDDOO>(GameInst)->RegisterToModule("Center", "GameInstacne", "GameInstacne");
}

