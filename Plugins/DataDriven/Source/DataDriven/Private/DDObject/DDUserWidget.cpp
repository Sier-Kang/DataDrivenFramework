// Fill out your copyright notice in the Description page of Project Settings.

#include "DDUserWidget.h"



bool UDDUserWidget::Initialize()
{
	//����һ��Ҫ�ж�һ�¸���
	if (!Super::Initialize()) return false;

	//�Զ�ע��
	RegisterToModule(ModuleName);

	return true;
}
