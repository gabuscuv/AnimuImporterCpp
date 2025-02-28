// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimuImporterSubSystemCommands.h"

#define LOCTEXT_NAMESPACE "FAnimuImporterSubSystemModule"

void FAnimuImporterSubSystemCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "AnimuImporterSubSystem", "Bring up AnimuImporterSubSystem window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
