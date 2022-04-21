// Copyright (C) Developed by Joshua Israel Albao. All Rights Reserved.

using UnrealBuildTool;

public class NameModule : ModuleRules
{
    public NameModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
        });
    }
}
