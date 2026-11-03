// Fill out your copyright notice in the Description page of Project Settings.

#include "TestLib.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"
#include <string>

void* UTestLib::DllHandle = nullptr;
UTestLib::GetPuddleSizeFn        UTestLib::pGetPuddleSize = nullptr;


FString UTestLib::HelloTest()
{
	return TEXT("Hello from TestLib! It's aliiiiiiiive!");
}


bool UTestLib::LoadUnreal_DLL()
{
	if (DllHandle) return true;

#if PLATFORM_WINDOWS
	const FString DllPath = FPaths::Combine(FPaths::ProjectDir(), TEXT("Binaries/Win64/Unreal_DLL.dll"));
	DllHandle = FPlatformProcess::GetDllHandle(*DllPath);
	if (!DllHandle) return false;

	pGetPuddleSize = reinterpret_cast<GetPuddleSizeFn>(FPlatformProcess::GetDllExport(DllHandle, TEXT("getPuddleSize")));

	if (!(pGetPuddleSize))
	{
		FPlatformProcess::FreeDllHandle(DllHandle);
		DllHandle = nullptr;
		return false;
	}
	return true;
#else
	return false;
#endif
}




const float UTestLib::getPuddleSize()
{
	if (!DllHandle && !LoadUnreal_DLL()) return 1.0;
	if (pGetPuddleSize)
	{
		const float FLT = pGetPuddleSize();
		return float(FLT ? FLT : 1.0);
	}
	return 1.0;
}