// Fill out your copyright notice in the Description page of Project Settings.

#include "DDActorComponent.h"


// Sets default values for this component's properties
UDDActorComponent::UDDActorComponent()
{
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	//������������
	bAllowAnyoneToDestroyMe = true;
}

// Called when the game starts
void UDDActorComponent::BeginPlay()
{
	Super::BeginPlay();

	//�Զ�ע��
	RegisterToModule(ModuleName, ObjectName, ClassName);
	
}

void UDDActorComponent::DDRelease()
{
	//�������ɾ���Լ�,�����Ϊ׼����gc����
	DestroyComponent();
	//ConditionalBeginDestroy();
}



