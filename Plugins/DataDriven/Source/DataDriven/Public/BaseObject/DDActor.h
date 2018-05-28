// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DDBaseObject.h"
#include "DDActor.generated.h"



UCLASS()
class DATADRIVEN_API ADDActor : public AActor, public DDBaseObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADDActor();

	//���캯�������Լ��غ����,�����ｫObjectע�ᵽ���
	virtual void PostLoad() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	
	
};
