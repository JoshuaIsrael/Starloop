// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Starloop : ModuleRules
{
	public Starloop(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"InteractionModule",
			"NameModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { 
			"Slate", 
			"SlateCore" 
		});
	}
}
