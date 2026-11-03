// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestLib.generated.h"

/**
 * 
 */
UCLASS()
class SORRYWERECLEANING_API UTestLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintPure,Category = "Unreal_DLL|Test")
	static FString HelloTest();

	UFUNCTION(BlueprintCallable,Category = "Unreal_DLL|DLL")
	static bool LoadUnreal_DLL();

	UFUNCTION(BlueprintCallable, Category="Unreal_DLL|DLL")
	static const float getPuddleSize();

private:
	static void* DllHandle;

	typedef const float (*GetPuddleSizeFn)();

	static GetPuddleSizeFn pGetPuddleSize;
};
