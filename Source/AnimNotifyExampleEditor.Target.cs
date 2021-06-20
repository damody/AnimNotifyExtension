/*
*  Copyright (c) 2021 Damody(t1238142000@gmail.com).
*  All rights reserved.
*  @ Date : 2021/06/20
*
*/

using UnrealBuildTool;
using System.Collections.Generic;

public class AnimNotifyExampleEditorTarget : TargetRules
{
	public AnimNotifyExampleEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "AnimNotifyExample" } );
	}
}
