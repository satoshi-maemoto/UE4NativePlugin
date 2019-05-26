// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SimpleDllAccessor.generated.h"

/**
 * 
 */
UCLASS()
class UE4NATIVEPLUGIN_API USimpleDllAccessor : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Simple DLL")
		static bool importDLL(FString folder, FString name);

	UFUNCTION(BlueprintCallable, Category = "Simple DLL")
		static void freeDLL();


	UFUNCTION(BlueprintCallable, Category = "Simple DLL")
		static bool importMethodGetStringValue();

	UFUNCTION(BlueprintCallable, Category = "Simple DLL")
		static FString GetStringValue(int value);

};
