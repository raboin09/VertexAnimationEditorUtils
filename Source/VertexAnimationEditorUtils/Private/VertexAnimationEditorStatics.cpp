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
