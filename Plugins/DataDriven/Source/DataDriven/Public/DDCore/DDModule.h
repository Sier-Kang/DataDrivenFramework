// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Common/DDCommon.h"
#include "DDModule.generated.h"

class UDDManager;
class UDDModel;
class UDDMessage;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATADRIVEN_API UDDModule : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDDModule();

	//Module��BeginPlay����
	virtual void ModuleBeginPlay();

	//Module��Tick����
	virtual void ModuleTick(float DeltaSeconds);

	//��������
	virtual void Init();
	virtual void Register();
	virtual void Active();
	virtual void Disable();
	virtual void UnRegister();
	virtual void Release();

	//��������ģ��ķ��䷽��
	virtual void IterCallFunction(UDDModule* Module, FString FunctionName, void* Param);
	
	
public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDManager> ManagerClass;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDModel> ModelClass;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDMessage> MessageClass;

	//������
	UDDManager* Manager;

protected:

	

protected:


		
	
};
