// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DDCore/DDModule.h"
#include "DDCenterModule.generated.h"

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDCenterModule : public UDDModule
{
	GENERATED_BODY()

public:

	UDDCenterModule();

	virtual void InitializeComponent() override;

	//�������ñ�ģ���Լ���ģ���BeginPlay����,���÷���
	virtual void IterModuleBeginPlay(UDDModule* Module);

	//�������ñ�ģ���Լ���ģ���Tick����,���÷���
	virtual void IterModuleTick(UDDModule* Module, float DeltaSeconds);


};
