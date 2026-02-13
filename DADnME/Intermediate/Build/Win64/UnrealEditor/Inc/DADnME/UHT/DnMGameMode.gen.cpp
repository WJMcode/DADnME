// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DADnME/Public/GameFramework/DnMGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDnMGameMode() {}

// Begin Cross Module References
DADNME_API UClass* Z_Construct_UClass_ADnMGameMode();
DADNME_API UClass* Z_Construct_UClass_ADnMGameMode_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameMode();
UPackage* Z_Construct_UPackage__Script_DADnME();
// End Cross Module References

// Begin Class ADnMGameMode
void ADnMGameMode::StaticRegisterNativesADnMGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADnMGameMode);
UClass* Z_Construct_UClass_ADnMGameMode_NoRegister()
{
	return ADnMGameMode::StaticClass();
}
struct Z_Construct_UClass_ADnMGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "GameFramework/DnMGameMode.h" },
		{ "ModuleRelativePath", "Public/GameFramework/DnMGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADnMGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADnMGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameMode,
	(UObject* (*)())Z_Construct_UPackage__Script_DADnME,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADnMGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADnMGameMode_Statics::ClassParams = {
	&ADnMGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADnMGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ADnMGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADnMGameMode()
{
	if (!Z_Registration_Info_UClass_ADnMGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADnMGameMode.OuterSingleton, Z_Construct_UClass_ADnMGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADnMGameMode.OuterSingleton;
}
template<> DADNME_API UClass* StaticClass<ADnMGameMode>()
{
	return ADnMGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADnMGameMode);
ADnMGameMode::~ADnMGameMode() {}
// End Class ADnMGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_GameFramework_DnMGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADnMGameMode, ADnMGameMode::StaticClass, TEXT("ADnMGameMode"), &Z_Registration_Info_UClass_ADnMGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADnMGameMode), 3463529878U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_GameFramework_DnMGameMode_h_2746766040(TEXT("/Script/DADnME"),
	Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_GameFramework_DnMGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_GameFramework_DnMGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
