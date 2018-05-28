// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DDGameMode.generated.h"

class USceneComponent;
class UDDCenterModule;
class DDBaseObject;
/**
 * 
 */
UCLASS()
class DATADRIVEN_API ADDGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	ADDGameMode();

	virtual void PostInitializeComponents() override;

	virtual void Tick(float DeltaSeconds) override;

	//�ṩ����Դ�ǽ���ע��
	void RegisterObject(DDBaseObject* Object);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		UDDCenterModule* CenterModule;
	
	//��ʱ����������Դ
	TArray<DDBaseObject*> ObjectGroup;

protected:

	virtual void BeginPlay() override;

};
