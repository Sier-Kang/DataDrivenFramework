// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



class UObject;
class UDDModule;
/**
 * 
 */
class DATADRIVEN_API DDBaseObject
{

public:

	DDBaseObject();


	//�������������ԴPostInitPropertiesʱ����,�ڱ༭���ھ���ӵ���ģ��
	void RegisterObject(UObject* SelfBody);
	
public:

	//��������UObject
	UObject* Body;

	


};
