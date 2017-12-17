// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once

#if PLATFORM_ANDROID
void InitTapsellJavaMethods();
void AndroidThunkCpp_TapsellRequestAd(FString zoneId, bool isCached);
void AndroidThunkCpp_TapsellShowAd(FString adId, FString zoneId, bool backDisabled, bool immersiveMode, int rotationMode, bool showDialog);
FString AndroidThunkCpp_TapsellGetVersion();
void AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsagePercentage(int maxPercentage);
void AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsage(int maxBpsSpeed);
void AndroidThunkCpp_TapsellClearBandwidthUsageConstrains();
void AndroidThunkCpp_TapsellSetPermissionHandlerMode(int permissionHandlerConfig);
void AndroidThunkCpp_TapsellSetDebugMode(bool debug);
void AndroidThunkCpp_TapsellRequestBannerAd(FString zoneId, int bannerType, int horizontalGravity, int verticalGravity);
#endif