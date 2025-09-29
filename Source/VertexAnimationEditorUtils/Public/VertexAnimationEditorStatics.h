// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VertexAnimationEditorStatics.generated.h"

/**
 * 
 */
UCLASS()
class VERTEXANIMATIONEDITORUTILS_API UVertexAnimationEditorStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "VertexAnimationEditorUtils")
	static UMaterialInterface* MakeMaterialInstance(UMaterialInterface* Material, const FString& NewMaterialName);
	UFUNCTION(BlueprintCallable, Category = "VertexAnimationEditorUtils")
	static void ToggleTangentSpaceNormalOnBaseMaterial(UMaterialInstanceConstant* MaterialChild, bool bNewValue);
};
