// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DDOO.h"
#include "DDHUD.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API ADDHUD : public AHUD, public IDDOO
{
	GENERATED_BODY()
	
public:

	ADDHUD();

public:

	//ģ������,���Ϊ��,˵��Ҫ�ֶ�ָ��,��Ϊ�վ����Զ�ָ��
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ModuleName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
