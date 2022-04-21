// Copyright (C) Developed by Joshua Israel Albao. All Rights Reserved.

using UnrealBuildTool;

public class InteractionModule : ModuleRules
{
    public InteractionModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
