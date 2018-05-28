// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DDBaseObject.h"
#include "DDUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDUserWidget : public UUserWidget, public DDBaseObject
{
	GENERATED_BODY()
	
public:

	UDDUserWidget(const FObjectInitializer& ObjectInitializer);

	//���캯�������Լ��غ����,�����ｫObjectע�ᵽ���
	virtual void PostLoad() override;

	//Widget�ĳ�ʼ������
	virtual bool Initialize() override;

	
	
};
