// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DDOO.h"
#include "DDGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDGameInstance : public UGameInstance, public IDDOO
{
	GENERATED_BODY()
	
public:

	//GameInstance���������ٲ�������д�������ں���,��д�������ں����Ļ�Ҫ���ؿ���,������ת������ʱ�ظ�����
	//virtual void DDRelease() override;
	
	
};
