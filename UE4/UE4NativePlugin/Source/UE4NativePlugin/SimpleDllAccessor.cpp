// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleDllAccessor.h"
#include <string>
#include "Paths.h"
#include "UnrealString.h"

void *v_dllHandle;

typedef std::wstring(*_getStringValue)(int value);
_getStringValue m_getStringValueFromDll;


bool USimpleDllAccessor::importDLL(FString folder, FString name)
{
	FString filePath = *FPaths::GamePluginsDir() + folder + "/" + name;

	if (FPaths::FileExists(filePath))
	{
		v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);
		if (v_dllHandle != nullptr)
		{
			return true;
		}
	}
	return false;
}

void USimpleDllAccessor::freeDLL()
{
	if (v_dllHandle != nullptr)
	{
		m_getStringValueFromDll = nullptr;

		FPlatformProcess::FreeDllHandle(v_dllHandle);
		v_dllHandle = nullptr;
	}
}


bool USimpleDllAccessor::importMethodGetStringValue()
{
	if (v_dllHandle != nullptr)
	{
		m_getStringValueFromDll = nullptr;
		FString procName = "GetStringValue";
		m_getStringValueFromDll = (_getStringValue)FPlatformProcess::GetDllExport(v_dllHandle, *procName);
		if (m_getStringValueFromDll != nullptr)
		{
			return true;
		}
	}
	return false;
}

FString USimpleDllAccessor::GetStringValue(int value)
{
	if (m_getStringValueFromDll != nullptr)
	{
		auto out = FString(m_getStringValueFromDll(value).c_str());
		return out;
	}
	return FString("Fail");
}
