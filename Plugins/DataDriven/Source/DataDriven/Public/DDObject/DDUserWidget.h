// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DDOO.h"
#include "DDUserWidget.generated.h"

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDUserWidget : public UUserWidget, public IDDOO
{
	GENERATED_BODY()

public:

	//Widget�ĳ�ʼ������
	virtual bool Initialize() override;

public:

	//ģ������,���Ϊ��,˵��Ҫ�ֶ�ָ��,��Ϊ�վ����Զ�ָ��
	UPROPERTY(EditAnywhere, Category = "DataDriven")
		FString ModuleName;

};



//UserWidget�Ĺ��캯����д��ʽ
//UDDUserWidget(const FObjectInitializer& ObjectInitializer);

//UDDUserWidget::UDDUserWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
//{
//
//}