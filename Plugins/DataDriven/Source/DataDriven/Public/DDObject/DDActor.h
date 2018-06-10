// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DDOO.h"
#include "DDActor.generated.h"


UCLASS()
class DATADRIVEN_API ADDActor : public AActor, public IDDOO
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADDActor();

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};





//struct DesObjParam : DDParam
//{
//	struct
//	{
//		EAgreementType Agree;
//		TArray<FString> ObjectNameGroup;
//	} Parameter;
//	EAgreementType Agree() { return Parameter.Agree; }
//	TArray<FString> ObjectNameGroup() { return Parameter.ObjectNameGroup; }
//	DesObjParam() { ParamPtr = &Parameter; }
//};
//DesObjParam* DesObj(int32 ModuleIndex, FString FunctionName, EAgreementType Agree, TArray<FString> ObjectNameGroup)
//{
//	DDModuleAgreement Agreement;
//	Agreement.ModuleIndex = ModuleIndex;
//	Agreement.FunctionName;
//
//	DesObjParam* Param = new DesObjParam();
//	Param->Parameter.Agree = Agree;
//	Param->Parameter.ObjectNameGroup = ObjectNameGroup;
//	ExecuteFunction(Agreement, Param);
//
//	return Param;
//}