// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimuImporterSubSystemStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FAnimuImporterSubSystemStyle::StyleInstance = nullptr;

void FAnimuImporterSubSystemStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FAnimuImporterSubSystemStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FAnimuImporterSubSystemStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("AnimuImporterSubSystemStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FAnimuImporterSubSystemStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("AnimuImporterSubSystemStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("AnimuImporterSubSystem")->GetBaseDir() / TEXT("Resources"));

	Style->Set("AnimuImporterSubSystem.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	return Style;
}

void FAnimuImporterSubSystemStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FAnimuImporterSubSystemStyle::Get()
{
	return *StyleInstance;
}
