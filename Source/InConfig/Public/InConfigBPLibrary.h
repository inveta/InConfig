// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "InConfigBPLibrary.generated.h"


UCLASS()
class UInConfigBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	static void CheckAndCreateConfig();
	static FString GetConfigPath();
public:
	UFUNCTION(BlueprintCallable, Category = "InConfig")
	static bool GetConfigString(FString Section, FString Key, FString& value);

	UFUNCTION(BlueprintCallable, Category = "InConfig")
	static void SetConfigString(FString Section, FString Key, FString value);

	UFUNCTION(BlueprintCallable, Category = "InConfig")
		static bool GetConfigInt(FString Section, FString Key, int32& value);

	UFUNCTION(BlueprintCallable, Category = "InConfig")
		static void SetConfigInt(FString Section, FString Key, int32 value);
};
