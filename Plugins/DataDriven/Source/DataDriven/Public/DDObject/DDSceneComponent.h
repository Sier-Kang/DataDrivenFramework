// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "DDOO.h"
#include "DDSceneComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATADRIVEN_API UDDSceneComponent : public USceneComponent, public IDDOO
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDDSceneComponent();

public:

	//模组名字,如果为空,说明要手动指定,不为空就是自动指定
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ModuleName;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	
};
