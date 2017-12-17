// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "TapsellPrivatePCH.h"

#if PLATFORM_ANDROID
#include "TapsellJavaWrapper.h"
#endif

DEFINE_LOG_CATEGORY(LogTapsell);

class FTapsellModule : public ITapsellModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FTapsellModule, Tapsell )

void FTapsellModule::StartupModule()
{
#if PLATFORM_ANDROID
   InitTapsellJavaMethods();
#endif
}

void FTapsellModule::ShutdownModule()
{	
}
