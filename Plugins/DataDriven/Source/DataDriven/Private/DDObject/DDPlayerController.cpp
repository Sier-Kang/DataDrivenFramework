// Fill out your copyright notice in the Description page of Project Settings.

#include "DDPlayerController.h"



ADDPlayerController::ADDPlayerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ADDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//�Զ�ע��
	RegisterToModule(ModuleName, ObjectName, ClassName);
}
