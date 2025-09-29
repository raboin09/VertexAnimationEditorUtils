// Fill out your copyright notice in the Description page of Project Settings.


#include "VertexAnimationEditorStatics.h"

#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "MaterialEditingLibrary.h"
#include "Factories/MaterialInstanceConstantFactoryNew.h"
#include "Materials/MaterialInstanceConstant.h"

UMaterialInterface* UVertexAnimationEditorStatics::MakeMaterialInstance(UMaterialInterface* Material, const FString& NewMaterialName)
{
	if (!Material)
	{
		UE_LOG(LogTemp, Warning, TEXT("Material is null. Cannot create a material instance."));
		return nullptr;
	}
	
	FString ParentPackagePath = FPackageName::GetLongPackagePath(Material->GetOutermost()->GetName());
	
	IAssetTools &AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
	UMaterialInstanceConstantFactoryNew *Factory = NewObject<UMaterialInstanceConstantFactoryNew>();
	UMaterialInstanceConstant *MaterialInstance = CastChecked<UMaterialInstanceConstant>(AssetTools.CreateAsset(NewMaterialName, ParentPackagePath, UMaterialInstanceConstant::StaticClass(), Factory));
	UMaterialEditingLibrary::SetMaterialInstanceParent(MaterialInstance, Material);
	if (MaterialInstance)
	{
		MaterialInstance->SetFlags(RF_Standalone);
		MaterialInstance->MarkPackageDirty();
		MaterialInstance->PostEditChange();
	}
	return MaterialInstance;
}

void UVertexAnimationEditorStatics::ToggleTangentSpaceNormalOnBaseMaterial(UMaterialInstanceConstant* MaterialChild, bool bNewValue)
{
	if (!MaterialChild)
	{
		UE_LOG(LogTemp, Warning, TEXT("MaterialInstance is null!"));
		return;
	}

	// Get the base UMaterial
	UMaterial* BaseMaterial = MaterialChild->GetBaseMaterial();
	if (!BaseMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get the base material from the material instance!"));
		return;
	}

	if(BaseMaterial->bTangentSpaceNormal != bNewValue)
	{
		BaseMaterial->bTangentSpaceNormal = bNewValue;
		BaseMaterial->MarkPackageDirty(); // Mark as dirty so changes can be saved
		BaseMaterial->PostEditChange();   // Notify the editor of the change in property	
	}
}
