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

	//��д�ͷź���
	virtual void DDRelease() override;

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

};



//UserWidget�Ĺ��캯����д��ʽ
//UDDUserWidget(const FObjectInitializer& ObjectInitializer);

//UDDUserWidget::UDDUserWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
//{
//
//}