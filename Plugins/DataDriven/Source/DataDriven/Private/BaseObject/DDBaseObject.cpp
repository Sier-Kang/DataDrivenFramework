// Fill out your copyright notice in the Description page of Project Settings.

#include "DDBaseObject.h"
#include "UObject/NoExportTypes.h"
#include "DDGameMode.h"
#include "Kismet/GameplayStatics.h"


DDBaseObject::DDBaseObject()
{
}


void DDBaseObject::RegisterObject(UObject* SelfBody)
{
	//��ȡ�Լ���ʵ��
	Body = SelfBody;
	//��ȡDDGameMode����ע�ᵽDDGameMode����ʱ��Դ��
	Cast<ADDGameMode>(UGameplayStatics::GetGameMode(Body))->RegisterObject(this);
}

