// Copyright 2017-2018, Tapsell team. All Rights Reserved.
#pragma once
#include "TapsellComponent.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class RotationMode : uint8
{
	RotationLockedPortrait = 1 	UMETA(DisplayName = "Locked Portrait"),
	RotationLockedLandscape = 2	UMETA(DisplayName = "Locked Landscape"),
	RotationUnlocked = 3	UMETA(DisplayName = "Unlocked"),
	RotationLockedReversedLandscape = 4	UMETA(DisplayName = "Locked Reversed Landscape"),
	RotationLockedReversedPortrait = 5	UMETA(DisplayName = "Locked Reversed Portrait")
};

UENUM(BlueprintType)		
enum class HorizontalGravity : uint8
{
	HorizontalGravityTop = 1 	UMETA(DisplayName = "Top"),
	HorizontalGravityBottom = 2	UMETA(DisplayName = "Bottom"),
};

UENUM(BlueprintType)		
enum class VerticalGravity : uint8
{
	VerticalGravityLeft = 3 	UMETA(DisplayName = "Left"),
	VerticalGravityCenter = 5	UMETA(DisplayName = "Center"),
	VerticalGravityRight = 4	UMETA(DisplayName = "Right")
};

UENUM(BlueprintType)
enum class PermissionHandler : uint8
{
	PermissionHandlerDisabled = 0 	UMETA(DisplayName = "Disabled"),
	PermissionHandlerAuto = 1	UMETA(DisplayName = "Auto"),
	PermissionHandlerAutoInsist = 2	UMETA(DisplayName = "Auto Insist")
};

UENUM(BlueprintType)
enum class BannerType : uint8
{
	BANNER_320x50 = 1 	UMETA(DisplayName = "BANNER 320x50"),
	BANNER_320x100 = 2 	UMETA(DisplayName = "BANNER 320x100"),
	BANNER_250x250 = 3 	UMETA(DisplayName = "BANNER 250x250"),
	BANNER_300x250 = 4 	UMETA(DisplayName = "BANNER 300x250")
};

UENUM(BlueprintType)
enum class MaxAllowedBandwidthUsagePercentage : uint8
{
	P20 = 20 	UMETA(DisplayName = "20 %"),
	P25 = 25 	UMETA(DisplayName = "25 %"),
	P33 = 33 	UMETA(DisplayName = "33 %"),
	P40 = 40 	UMETA(DisplayName = "40 %"),
	P50 = 50 	UMETA(DisplayName = "50 %"),
	P60 = 60 	UMETA(DisplayName = "60 %"),
	P75 = 75 	UMETA(DisplayName = "75 %"),
	P80 = 80 	UMETA(DisplayName = "80 %"),
	P100 = 100 	UMETA(DisplayName = "100 %")
};

UCLASS(ClassGroup = Advertising, HideCategories = (Activation, "Components|Activation", Collision), meta = (BlueprintSpawnableComponent))
class UTapsellComponent : public UActorComponent
{
   GENERATED_UCLASS_BODY()
public:
   ~UTapsellComponent();

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
   static void TapsellRequestAd(FString zoneId, bool isCached);

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	static void TapsellShowAd(FString adId, FString zoneId, bool backDisabled, bool immersiveMode, RotationMode rotationMode, bool showDialog);

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	static FString TapsellGetVersion();

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	static void TapsellSetMaxAllowedBandwidthUsagePercentage(MaxAllowedBandwidthUsagePercentage maxPercentage);

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	   static void TapsellSetMaxAllowedBandwidthUsage(int maxBpsSpeed);

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	   static void TapsellClearBandwidthUsageConstrains();

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	   static void TapsellSetPermissionHandlerMode(PermissionHandler permissionHandler);

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	   static void TapsellSetDebugMode(bool debug);

   UFUNCTION(BlueprintCallable, Category = "Plugin|TapsellAds")
	   static void TapsellRequestBannerAd(FString zoneId, BannerType bannerType, HorizontalGravity horizontalGravity, VerticalGravity verticalGravity);

   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTapsellRequestAdOnErrorDelegate, FString, error, FString, zone_id);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTapsellRequestAdOnAdAvailableDelegate, FString, ad_id, FString, zone_id);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTapsellRequestAdOnNoAdAvailableDelegate, FString, zone_id);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTapsellRequestAdOnNoNetworkDelegate, FString, zone_id);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTapsellRequestAdOnExpiringDelegate, FString, ad_id, FString, zone_id);

   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTapsellShowAdOnOpenedDelegate, FString, ad_id, FString, zone_id);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTapsellShowAdOnClosedDelegate, FString, ad_id, FString, zone_id);

   DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FTapsellOnAdShowFinishedDelegate, FString, ad_id, FString, zone_id, bool, compeleted, bool, rewarded);

   UPROPERTY(BlueprintAssignable)
	FTapsellRequestAdOnErrorDelegate TapsellRequestAdOnError;

   UPROPERTY(BlueprintAssignable)
	   FTapsellRequestAdOnAdAvailableDelegate TapsellRequestAdOnAdAvailable;

   UPROPERTY(BlueprintAssignable)
	   FTapsellRequestAdOnNoAdAvailableDelegate TapsellRequestAdOnNoAdAvailable;

   UPROPERTY(BlueprintAssignable)
	   FTapsellRequestAdOnNoNetworkDelegate TapsellRequestAdOnNoNetwork;

   UPROPERTY(BlueprintAssignable)
	   FTapsellRequestAdOnExpiringDelegate TapsellRequestAdOnExpiring;

   UPROPERTY(BlueprintAssignable)
	   FTapsellShowAdOnOpenedDelegate TapsellShowAdOnOpened;

   UPROPERTY(BlueprintAssignable)
	   FTapsellShowAdOnClosedDelegate TapsellShowAdOnClosed;

   UPROPERTY(BlueprintAssignable)
	   FTapsellOnAdShowFinishedDelegate TapsellOnAdShowFinished;

   static void TapsellRequestAdOnError_Broadcast(FString error, FString zone_id) {
      ActiveComponent->TapsellRequestAdOnError.Broadcast(error, zone_id);
   }

   static void TapsellRequestAdOnAdAvailable_Broadcast(FString ad_id, FString zone_id) {
	   ActiveComponent->TapsellRequestAdOnAdAvailable.Broadcast(ad_id, zone_id);
   }

   static void TapsellRequestAdOnNoAdAvailable_Broadcast(FString zone_id) {
	   ActiveComponent->TapsellRequestAdOnNoAdAvailable.Broadcast(zone_id);
   }

   static void TapsellRequestAdOnNoNetwork_Broadcast(FString zone_id) {
	   ActiveComponent->TapsellRequestAdOnNoNetwork.Broadcast(zone_id);
   }

   static void TapsellRequestAdOnExpiring_Broadcast(FString ad_id, FString zone_id) {
	   ActiveComponent->TapsellRequestAdOnExpiring.Broadcast(ad_id, zone_id);
   }

   static void TapsellShowAdOnOpened_Broadcast(FString ad_id, FString zone_id) {
	   ActiveComponent->TapsellShowAdOnOpened.Broadcast(ad_id, zone_id);
   }

   static void TapsellShowAdOnClosed_Broadcast(FString ad_id, FString zone_id) {
	   ActiveComponent->TapsellShowAdOnClosed.Broadcast(ad_id, zone_id);
   }

   static void TapsellOnAdShowFinished_Broadcast(FString ad_id, FString zone_id, bool compeleted, bool rewarded) {
	   ActiveComponent->TapsellOnAdShowFinished.Broadcast(ad_id, zone_id, compeleted, rewarded);
   }

private:
   static UTapsellComponent* ActiveComponent;
};