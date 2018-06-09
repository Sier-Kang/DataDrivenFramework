// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DDCommon/DDCommon.h"
#include "DDModule.generated.h"

class UDDManager;
class UDDModel;
class UDDMessage;
class IDDOO;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DATADRIVEN_API UDDModule : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDDModule();

	//Module��ԤBeginPlay����
	virtual void PreModuleBeginPlay();

	//Module��BeginPlay����
	virtual void ModuleBeginPlay();

	//Module��Tick����
	virtual void ModuleTick(float DeltaSeconds);

	bool RegisterObject(IDDOO* Object);

	void CreateManager();

	void ChangeModuleType(FString ModuleType);

	//����ģ�鷽��
	void ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param);
	//���ö��󷽷�
	void ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		TSubclassOf<UDDManager> ManagerClass;

	UPROPERTY(VisibleAnywhere, Category = "DataDriven")
		int32 ModuleIndex;

	//������
	UDDManager* Manager;

protected:



protected:




};


