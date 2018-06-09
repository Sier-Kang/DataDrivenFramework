// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DDCommon/DDCommon.h"
#include "DDGameMode.generated.h"

class USceneComponent;
class UDDCenterModule;
class IDDOO;
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

	//����ģ�鷽��
	void ExecuteFunction(DDModuleAgreement Agreement, DDParam* Param);
	//���ö��󷽷�
	void ExecuteFunction(DDObjectAgreement Agreement, DDParam* Param);

#if WITH_EDITOR
	//�����޸ķ���
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	//�ṩ����Դ�ǽ���ע��
	bool RegisterToModule(IDDOO* Object);

public:

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, NoClear, BlueprintReadOnly, Category = "DataDriven")
		UDDCenterModule* Center;

	//ģ���Ӧ��ö������
	UPROPERTY(EditDefaultsOnly, Category = "DataDriven")
		FString ModuleType;

protected:

	virtual void BeginPlay() override;

protected:

	//�Ƿ��Ѿ�����BeginPlay����
	bool IsBeginPlay;

};
