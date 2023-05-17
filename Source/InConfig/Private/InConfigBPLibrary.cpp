// Copyright Epic Games, Inc. All Rights Reserved.

#include "InConfigBPLibrary.h"
#include "InConfig.h"
#include "Misc/Paths.h"
#include "Misc/App.h"
#include "HAL/FileManager.h"

FString UInConfigBPLibrary::GetConfigPath()
{
	FString ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
	FString ProjectName = FApp::GetProjectName();
	FString ConfigPath = ProjectPath + "Config/" + ProjectName + ".ini";
	return ConfigPath;
}
void UInConfigBPLibrary::CheckAndCreateConfig()
{
	FString ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
	FString ProjectName = FApp::GetProjectName();
	FString ConfigPath = GetConfigPath();
	FString DefaultGamePath = ProjectPath + "Config/" + "DefaultGame.ini";

	if (true == FPaths::FileExists(ConfigPath))
	{
		return;
	}
	auto file = IFileManager::Get().CreateFileWriter(*ConfigPath);
	if (nullptr == file)
	{
		return;
	}
	file->Close();

	FString fileName = ProjectName + "/" + "Config/" + ProjectName + ".ini";
	GConfig->SetString(TEXT("Staging"), TEXT("+BlacklistConfigFiles"), *fileName, *DefaultGamePath);
}

bool UInConfigBPLibrary::GetConfigString(FString Section, FString Key, FString& value)
{
	FString ConfigPath = GetConfigPath();
	return GConfig->GetString(*Section, *Key, value, ConfigPath);
}

void UInConfigBPLibrary::SetConfigString(FString Section, FString Key, FString value)
{
	CheckAndCreateConfig();
	FString ConfigPath = GetConfigPath();
	GConfig->SetString(*Section, *Key, *value, ConfigPath);
}

bool UInConfigBPLibrary::GetConfigInt(FString Section, FString Key, int32& value)
{
	FString ConfigPath = GetConfigPath();
	return GConfig->GetInt(*Section, *Key, value, ConfigPath);
}


void UInConfigBPLibrary::SetConfigInt(FString Section, FString Key, int32 value)
{
	CheckAndCreateConfig();
	FString ConfigPath = GetConfigPath();
	GConfig->SetInt(*Section, *Key, value, ConfigPath);
}