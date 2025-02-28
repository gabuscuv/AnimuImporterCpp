// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AnimuImporterMainSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class ANIMUIMPORTERSUBSYSTEM_API UAnimuImporterMainSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	bool ImportMMDModel();
	UFUNCTION(BlueprintCallable)
	bool ImportVRMModel();
};
