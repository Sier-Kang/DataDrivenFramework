// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDManager.generated.h"


class UDDMessage;
class UDDModel;

/**
 * 
 */
UCLASS()
class DATADRIVEN_API UDDManager : public UObject
{
	GENERATED_BODY()
	
public:

	UDDManager();
	
	//�������ں���
	virtual void Register();
	virtual void Active();
	virtual void Disable();
	virtual void UnRegister();
	virtual void Release();


public:
	//��Ϣģ�����
	TSubclassOf<UDDMessage> MessageClass;
	//����ģ�����
	TSubclassOf<UDDModel> ModelClass;


	//��Ϣģ��
	UDDMessage* Message;
	//����ģ��
	UDDModel* Model;

};
