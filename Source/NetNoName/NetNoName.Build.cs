// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetNoName : ModuleRules
{
	public NetNoName(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara", "UMG", "OnlineSubsystem", "OnlineSubsystemSteam" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });


        // Public ��� ���� ���
        PublicIncludePaths.AddRange(new string[] {
            "NetNoName/CSW/public"
        });

        // Private CPP ���� ���
        PrivateIncludePaths.AddRange(new string[] {
            "NetNoName/CSW/private"
        });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
