// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "AnimuImporterSubSystemStyle.h"

class FAnimuImporterSubSystemCommands : public TCommands<FAnimuImporterSubSystemCommands>
{
public:

	FAnimuImporterSubSystemCommands()
		: TCommands<FAnimuImporterSubSystemCommands>(TEXT("AnimuImporterSubSystem"), NSLOCTEXT("Contexts", "AnimuImporterSubSystem", "AnimuImporterSubSystem Plugin"), NAME_None, FAnimuImporterSubSystemStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};