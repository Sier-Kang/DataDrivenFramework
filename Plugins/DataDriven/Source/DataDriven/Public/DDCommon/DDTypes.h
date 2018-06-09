// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDTypes.generated.h"

/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDTypes : public UObject
{
	GENERATED_BODY()


};

//Ĭ��ģ��ö��
UENUM()
enum class EDefaultModule : uint8 {
	Center = 0,      //����ģ��
	Resource,        //��Դģ��
	UI,              //UIģ��
};




//ͨ��Э��,ֻ���ڶ���ͨ��
UENUM()
enum class EAgreementType : uint8 {
	SelfObject,        //������Ķ���ͨ��
	OtherObject,       //������Ķ���֮��Ķ���ͨ��
	ClassOtherObject,  //������Ķ������ͬ�����������ͨ��,�����������Ҫȷ���������Ķ�����ͬһ���,�����ͬ��Ͷ��ͨ��
	SelfClass,         //�������Ķ���ͨ��
	OtherClass         //�������֮�����ͨ��
};

//���ý��,��Ŀ����ʱ��ȷ��ÿ�ζ��ܵ��óɹ�
UENUM()
enum class ECallResult : uint8
{
	NoModule = 0,     //���ʲô��û�иı�˵��û�ж�Ӧģ��
	LackObject,  //ȱʧ����
	NoFunction,  //û�ж�Ӧ����
	Succeed      //�ɹ�����
};

//BaseObject��������
UENUM()
enum class EBaseObjectLife : uint8
{
	None = 0,//��ʼ����״̬
	Init,
	Loading,
	Register,
	Enable,
	Disable,
	UnRegister,
	UnLoading
};

//BaseObject��������
UENUM()
enum class EBaseObjectState : uint8
{
	Active = 0, //�������
	Stable,     //�ȶ�����
	Destroy     //���ٽ���
};

//��Ϣͨ�Ż���
struct DDParam
{

public:
	
	//�ص��Ľ��
	ECallResult AsyResult;

	//����ָ��
	void* ParamPtr;
};


struct DDModuleAgreement
{

public:
	//ģ�����
	int32 ModuleIndex;
	//������
	FString FunctionName;
};



struct DDObjectAgreement
{

public:
	//ģ�����
	int32 ModuleIndex;
	//Э������
	EAgreementType AgreementType;
	//������
	TArray<FString> ObjectGroup;
	//������
	FString FunctionName;
};


//UCLASS()
//class DATADRIVEN_API UDDParameter : public UObject
//{
//	GENERATED_BODY()
//
//public:
//
//	FDDParam* Param;
//};


//USTRUCT()
//struct FDDModulePackage
//{
//	GENERATED_BODY()
//
//public:
//
//	UDDModuleAgreement* Agreement;
//
//	UDDParameter* Parameter;
//
//};
//
//USTRUCT()
//struct FDDObjectPackage
//{
//	GENERATED_BODY()
//
//public:
//
//	UDDObjectAgreement Agreement;
//
//	UDDParameter* Parameter;
//};