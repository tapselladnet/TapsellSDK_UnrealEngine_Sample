// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class test1 : ModuleRules
{
	public test1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay"  });

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystemGooglePlay", "AndroidAdvertising" });
        }

        PrivateDependencyModuleNames.Add("OnlineSubsystem");

        //PrivateDependencyModuleNames.AddRange(new string[] { "TapsellPlugin/Private" });

        //DynamicallyLoadedModuleNames.AddRange(new string[] { "TapsellPlugin" });

        //PrivateIncludePathModuleNames.AddRange(new string[] { "TapsellPlugin/Public", "TapsellPlugin/Private" });
        //PublicIncludePaths.AddRange(new string[] { "TapsellPlugin/Public", "TapsellPlugin/Private" });

        //if (Target.Platform == UnrealTargetPlatform.Android)
        //{

        //}

        //PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystemGooglePlay", "AndroidAdvertising" , "OnlineSubsystem" });
        //PrivateIncludePathModuleNames.AddRange(new string[] { "OnlineSubsystemGooglePlay", "AndroidAdvertising", "OnlineSubsystem" });

    }
}
