// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "TapsellPrivatePCH.h"
#include "TapsellComponent.h"
#if PLATFORM_ANDROID
#include "TapsellJavaWrapper.h"
#include "Runtime/Core/Public/CoreGlobals.h"
#include "../Public/TapsellComponent.h"
#endif

/*static*/ UTapsellComponent* UTapsellComponent::ActiveComponent = nullptr;

UTapsellComponent::UTapsellComponent(FObjectInitializer const&)
{
   ActiveComponent = this;
}

UTapsellComponent::~UTapsellComponent()
{
   ActiveComponent = nullptr;
}

void UTapsellComponent::TapsellRequestAd(FString zoneId, bool isCached)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_TapsellRequestAd(zoneId , isCached);
#endif
}

void UTapsellComponent::TapsellShowAd(FString adId, FString zoneId, bool backDisabled, bool immersiveMode, RotationMode rotationMode, bool showDialog)
{
#if PLATFORM_ANDROID
	int rote_mode = static_cast<int>(rotationMode);
	AndroidThunkCpp_TapsellShowAd(adId, zoneId, backDisabled, immersiveMode, rote_mode, showDialog);
#endif
}

FString UTapsellComponent::TapsellGetVersion()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_TapsellGetVersion();
#else
	return "";
#endif
}

void UTapsellComponent::TapsellSetMaxAllowedBandwidthUsagePercentage(MaxAllowedBandwidthUsagePercentage maxPercentage)
{
#if PLATFORM_ANDROID
	int mp = static_cast<int>(maxPercentage);
	return AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsagePercentage(mp);
#endif
}

void UTapsellComponent::TapsellSetMaxAllowedBandwidthUsage(int maxBpsSpeed)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsage(maxBpsSpeed);
#endif
}

void UTapsellComponent::TapsellClearBandwidthUsageConstrains()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_TapsellClearBandwidthUsageConstrains();
#endif
}

void UTapsellComponent::TapsellSetPermissionHandlerMode(PermissionHandler permissionHandler)
{
#if PLATFORM_ANDROID
	int ph = static_cast<int>(permissionHandler);
	return AndroidThunkCpp_TapsellSetPermissionHandlerMode(ph);
#endif
}

void UTapsellComponent::TapsellSetDebugMode(bool debug)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_TapsellSetDebugMode(debug);
#endif
}

void UTapsellComponent::TapsellRequestBannerAd(FString zoneId, BannerType bannerType, HorizontalGravity horizontalGravity, VerticalGravity verticalGravity)
{
#if PLATFORM_ANDROID
	int bt = static_cast<int>(bannerType);
	int hg = static_cast<int>(horizontalGravity);
	int vg = static_cast<int>(verticalGravity);

	return AndroidThunkCpp_TapsellRequestBannerAd(zoneId, bt, hg, vg);
#endif
}
