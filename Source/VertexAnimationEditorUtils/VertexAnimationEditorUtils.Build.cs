// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class VertexAnimationEditorUtils : ModuleRules
{
	public VertexAnimationEditorUtils(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// For material editing
				"UnrealEd",
				"MaterialEditor",	
			}
			);
		
	}
}
