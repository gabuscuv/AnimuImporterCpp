// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimuImporterSubSystem.h"
#include "AnimuImporterSubSystemStyle.h"
#include "AnimuImporterSubSystemCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName AnimuImporterSubSystemTabName("AnimuImporterSubSystem");

#define LOCTEXT_NAMESPACE "FAnimuImporterSubSystemModule"

void FAnimuImporterSubSystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FAnimuImporterSubSystemStyle::Initialize();
	FAnimuImporterSubSystemStyle::ReloadTextures();

	FAnimuImporterSubSystemCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FAnimuImporterSubSystemCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FAnimuImporterSubSystemModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FAnimuImporterSubSystemModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(AnimuImporterSubSystemTabName, FOnSpawnTab::CreateRaw(this, &FAnimuImporterSubSystemModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FAnimuImporterSubSystemTabTitle", "AnimuImporterSubSystem"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FAnimuImporterSubSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FAnimuImporterSubSystemStyle::Shutdown();

	FAnimuImporterSubSystemCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(AnimuImporterSubSystemTabName);
}

TSharedRef<SDockTab> FAnimuImporterSubSystemModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FAnimuImporterSubSystemModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("AnimuImporterSubSystem.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FAnimuImporterSubSystemModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(AnimuImporterSubSystemTabName);
}

void FAnimuImporterSubSystemModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FAnimuImporterSubSystemCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FAnimuImporterSubSystemCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAnimuImporterSubSystemModule, AnimuImporterSubSystem)