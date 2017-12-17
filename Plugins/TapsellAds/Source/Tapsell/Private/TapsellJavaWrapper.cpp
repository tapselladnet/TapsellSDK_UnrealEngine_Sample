// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "TapsellPrivatePCH.h"
#include "TapsellJavaWrapper.h"
#include "TapsellComponent.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

#if PLATFORM_ANDROID
static jmethodID AndroidThunkJava_TapsellRequestAd;
static jmethodID AndroidThunkJava_TapsellShowAd;
static jmethodID AndroidThunkJava_TapsellGetVersion;
static jmethodID AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsagePercentage;
static jmethodID AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsage;
static jmethodID AndroidThunkJava_TapsellClearBandwidthUsageConstrains;
static jmethodID AndroidThunkJava_TapsellSetPermissionHandlerMode;
static jmethodID AndroidThunkJava_TapsellSetDebugMode;
static jmethodID AndroidThunkJava_TapsellRequestBannerAd;

void InitTapsellJavaMethods()
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (FJavaWrapper::GameActivityClassID)
      {
		  UE_LOG(LogTemp, Warning, TEXT("mylo InitTapsellJavaMethods"));
		  AndroidThunkJava_TapsellRequestAd = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellRequestAd", "(Ljava/lang/String;Z)V", true);
		  AndroidThunkJava_TapsellShowAd = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellShowAd", "(Ljava/lang/String;Ljava/lang/String;ZZIZ)V", true);
		  AndroidThunkJava_TapsellGetVersion = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellGetVersion", "()Ljava/lang/String;Ljava/lang/String;", true);
		  AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsagePercentage = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsagePercentage", "(I)V", true);
		  AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsage = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsage", "(I)V", true);
		  AndroidThunkJava_TapsellClearBandwidthUsageConstrains = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellClearBandwidthUsageConstrains", "()V", true);
		  AndroidThunkJava_TapsellSetPermissionHandlerMode = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellSetPermissionHandlerMode", "(I)V", true);
		  AndroidThunkJava_TapsellSetDebugMode = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellSetDebugMode", "(Z)V", true);
		  AndroidThunkJava_TapsellRequestBannerAd = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_TapsellRequestBannerAd", "(Ljava/lang/String;III)V", true);
      }
   }
}

void AndroidThunkCpp_TapsellRequestAd(FString zoneId, bool isCached)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellRequestAd"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellRequestAd)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellRequestAd"));
			jstring ZoneIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*zoneId));
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellRequestAd, ZoneIdArg, isCached);
			Env->DeleteLocalRef(ZoneIdArg);
		}
	}
}

void AndroidThunkCpp_TapsellShowAd(FString adId, FString zoneId, bool backDisabled, bool immersiveMode, int rotationMode, bool showDialog)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellShowAd"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellShowAd)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellShowAd"));

			jstring AdIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*adId));
			jstring ZoneIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*zoneId));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellShowAd, AdIdArg, ZoneIdArg, backDisabled, immersiveMode, rotationMode, showDialog);
			
			Env->DeleteLocalRef(AdIdArg);
			Env->DeleteLocalRef(ZoneIdArg);
		}
	}
}

FString AndroidThunkCpp_TapsellGetVersion()
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellGetVersion"));

	FString version;

	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellGetVersion)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellGetVersion"));

			jstring res = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellShowAd);

			const char *versionString = Env->GetStringUTFChars(res, 0);
			version = FString(versionString);

			Env->DeleteLocalRef(res);
		}
	}
	return version;
}

void AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsagePercentage(int maxPercentage)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsagePercentage"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsagePercentage)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsagePercentage"));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsagePercentage, maxPercentage);
		}
	}
}

void AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsage(int maxBpsSpeed)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellSetMaxAllowedBandwidthUsage"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsage)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsage"));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellSetMaxAllowedBandwidthUsage, maxBpsSpeed);
		}
	}
}

void AndroidThunkCpp_TapsellClearBandwidthUsageConstrains()
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellClearBandwidthUsageConstrains"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellClearBandwidthUsageConstrains)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellClearBandwidthUsageConstrains"));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellClearBandwidthUsageConstrains);
		}
	}
}

void AndroidThunkCpp_TapsellSetPermissionHandlerMode(int permissionHandlerConfig)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellSetPermissionHandlerMode"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellSetPermissionHandlerMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellSetPermissionHandlerMode"));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellSetPermissionHandlerMode, permissionHandlerConfig);
		}
	}
}

void AndroidThunkCpp_TapsellSetDebugMode(bool debug)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellSetDebugMode"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellSetDebugMode)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellSetDebugMode"));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellSetDebugMode, debug);
		}
	}
}

void AndroidThunkCpp_TapsellRequestBannerAd(FString zoneId, int bannerType, int horizontalGravity, int verticalGravity)
{
	UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkCpp_TapsellRequestBannerAd"));
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_TapsellRequestBannerAd)
		{
			UE_LOG(LogTemp, Warning, TEXT("mylo AndroidThunkJava_TapsellRequestBannerAd"));

			jstring ZoneIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*zoneId));

			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_TapsellRequestBannerAd, ZoneIdArg, bannerType, horizontalGravity, verticalGravity);

			Env->DeleteLocalRef(ZoneIdArg);
		}
	}
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellRequestAdOnError(JNIEnv* jenv, jobject thiz, jstring error, jstring zone_id)
{
	const char* JavaErrorString = jenv->GetStringUTFChars(error, 0);
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellRequestAdOnError_Broadcast(JavaErrorString, JavaZoneIdString);

	jenv->ReleaseStringUTFChars(error, JavaErrorString);
	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellRequestAdOnAdAvailable(JNIEnv* jenv, jobject thiz, jstring ad_id, jstring zone_id)
{
   const char* JavaAdIdString = jenv->GetStringUTFChars(ad_id, 0);
   const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

   UE_LOG(LogTemp, Warning, TEXT("mylo Java_com_epicgames_ue4_GameActivity_tapsellRequestAdOnAdAvailable ad_id is:"));

   UTapsellComponent::TapsellRequestAdOnAdAvailable_Broadcast(JavaAdIdString, JavaZoneIdString);

   jenv->ReleaseStringUTFChars(ad_id, JavaAdIdString);
   jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellRequestAdOnNoAdAvailable(JNIEnv* jenv, jobject thiz, jstring zone_id)
{
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellRequestAdOnNoAdAvailable_Broadcast(JavaZoneIdString);

	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellRequestAdOnNoNetwork(JNIEnv* jenv, jobject thiz, jstring zone_id)
{
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellRequestAdOnNoNetwork_Broadcast(JavaZoneIdString);

	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellRequestAdOnExpiring(JNIEnv* jenv, jobject thiz, jstring ad_id, jstring zone_id)
{
	const char* JavaAdIdString = jenv->GetStringUTFChars(ad_id, 0);
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellRequestAdOnExpiring_Broadcast(JavaAdIdString, JavaZoneIdString);

	jenv->ReleaseStringUTFChars(ad_id, JavaAdIdString);
	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellShowAdOnOpened(JNIEnv* jenv, jobject thiz, jstring ad_id, jstring zone_id)
{
	const char* JavaAdIdString = jenv->GetStringUTFChars(ad_id, 0);
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellShowAdOnOpened_Broadcast(JavaAdIdString, JavaZoneIdString);

	jenv->ReleaseStringUTFChars(ad_id, JavaAdIdString);
	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellShowAdOnClosed(JNIEnv* jenv, jobject thiz, jstring ad_id, jstring zone_id)
{
	const char* JavaAdIdString = jenv->GetStringUTFChars(ad_id, 0);
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellShowAdOnClosed_Broadcast(JavaAdIdString, JavaZoneIdString);

	jenv->ReleaseStringUTFChars(ad_id, JavaAdIdString);
	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

extern "C" void Java_com_epicgames_ue4_GameActivity_tapsellOnAdShowFinished(JNIEnv* jenv, jobject thiz, jstring ad_id, jstring zone_id, bool compeleted, bool rewarded)
{
	const char* JavaAdIdString = jenv->GetStringUTFChars(ad_id, 0);
	const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);

	UTapsellComponent::TapsellOnAdShowFinished_Broadcast(JavaAdIdString, JavaZoneIdString, compeleted, rewarded);

	jenv->ReleaseStringUTFChars(ad_id, JavaAdIdString);
	jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}


#endif
