// Fill out your copyright notice in the Description page of Project Settings.

#include "DDObject.h"




UDDObject::UDDObject()
{

}

void UDDObject::PostLoad()
{
	Super::PostLoad();
	//���Լ�ע�ᵽ���
	RegisterObject((UObject*)this);
}
