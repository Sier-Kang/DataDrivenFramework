// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DDCommon/DDDefine.h"
#include "Engine/GameEngine.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DDCommon.generated.h"

class ADDGameMode;

namespace DDHelper {

	//Debug����
	FORCEINLINE void Debug(FString Message, float Duration = 3.f) {
		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, Duration, FColor::Yellow, Message);
		}
	}

	//��ȡGameMode����,���������Ϊ��ȡGameMode�Ĳο�,��ʹ��
	FORCEINLINE ADDGameMode* GetDDGameMode()
	{
		if (GWorld) {
			UWorld* WorldPtr = GWorld.GetReference();
			if (WorldPtr) {
				if (UGameplayStatics::GetGameMode(WorldPtr)) {
					return Cast<ADDGameMode>(UGameplayStatics::GetGameMode(WorldPtr));
				}
			}
		}
		return NULL;
	}

	//�������Enumֵ��Ӧ��String���
	template<typename TEnum>
	FORCEINLINE FString GetEnumValueAsString(const FString& Name, TEnum Value)
	{
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
		if (!EnumPtr) {
			return FString("InValid");
		}
		return EnumPtr->GetEnumName((int32)Value);
	}
	//�������String��Ӧ��Enum���
	template<typename TEnum>
	FORCEINLINE TEnum GetEnumValueFromString(const FString& Name, FString Value)
	{
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
		if (!EnumPtr) {
			return TEnum(0);
		}
		return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
	}

	//�������String��Ӧ��Enum��������
	FORCEINLINE int32 GetEnumIndexFromString(const FString& Name, FString Value)
	{
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
		if (!EnumPtr) {
			return -1;
		}
		return EnumPtr->GetIndexByName(FName(*FString(Value)));
	}
}



/**
 *
 */
UCLASS()
class DATADRIVEN_API UDDCommon : public UObject
{
	GENERATED_BODY()


};
