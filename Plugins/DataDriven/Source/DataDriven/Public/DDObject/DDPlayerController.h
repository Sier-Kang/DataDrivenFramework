// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DDOO.h"
#include "DDPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class DATADRIVEN_API ADDPlayerController : public APlayerController, public IDDOO
{
	GENERATED_BODY()
	
public:

	ADDPlayerController();

	//PlayerController����������,��������д�������ں���
	//virtual void DDRelease() override;

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
