// Fill out your copyright notice in the Description page of Project Settings.

#include "TKMenuController.h"




ATKMenuController::ATKMenuController()
{
	//����ģ����ΪController
	ModuleName = FString("Controller");

	ObjectName = ClassName = FString("MenuController");
}

void ATKMenuController::DDInit()
{
	Super::DDInit();

	//��������ģʽΪGameAndUI
	FInputModeGameAndUI InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);

	//��ʾ���
	bShowMouseCursor = true;

}

void ATKMenuController::PCInfo(TArray<FString>& MessInfo, int32 IsUsed)
{
	FString EchoStr;
	for (int i = 0; i < MessInfo.Num(); ++i) {
		EchoStr = EchoStr + MessInfo[i] + FString(" -- ");
	}
	EchoStr = EchoStr + FString::FromInt(IsUsed);
	DDHelper::Debug(EchoStr);
	MessInfo.Add("InfoThree");
}
