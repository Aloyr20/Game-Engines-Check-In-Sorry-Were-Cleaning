// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class SorryWereCleaning : ModuleRules
{
    public SorryWereCleaning(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicDelayLoadDLLs.Add("Unreal_DLL.dll");

            string ProjectDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "../../"));
            string DllSource = Path.Combine(ProjectDir, "EditorBinaries", "Win64", "Unreal_DLL.dll");

            RuntimeDependencies.Add("$(TargetOutputDir)/Unreal_DLL.dll", DllSource);
        }

        // Commented this bc wasn't in the slides?      PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
