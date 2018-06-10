// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DDOO.h"
#include "DDGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API ADDGameStateBase : public AGameStateBase, public IDDOO
{
	GENERATED_BODY()
	
public:

	ADDGameStateBase();

public:

	//ģ������,���Ϊ��,˵��Ҫ�ֶ�ָ��,��Ϊ�վ����Զ�ָ��
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ModuleName;
	//��������,���Ϊ��,˵��Ҫ�ֶ�ָ��,��Ϊ�վ����Զ�ָ��
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ObjectName;
	//������,���Ϊ��,˵��Ҫ�ֶ�ָ��,��Ϊ�վ����Զ�ָ��
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ClassName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
};
