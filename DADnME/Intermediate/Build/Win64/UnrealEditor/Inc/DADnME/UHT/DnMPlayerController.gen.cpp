// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DADnME/Public/Player/DnMPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDnMPlayerController() {}

// Begin Cross Module References
DADNME_API UClass* Z_Construct_UClass_ADnMPlayerController();
DADNME_API UClass* Z_Construct_UClass_ADnMPlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_DADnME();
// End Cross Module References

// Begin Class ADnMPlayerController
void ADnMPlayerController::StaticRegisterNativesADnMPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADnMPlayerController);
UClass* Z_Construct_UClass_ADnMPlayerController_NoRegister()
{
	return ADnMPlayerController::StaticClass();
}
struct Z_Construct_UClass_ADnMPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Player/DnMPlayerController.h" },
		{ "ModuleRelativePath", "Public/Player/DnMPlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADnMPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ADnMPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_DADnME,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADnMPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADnMPlayerController_Statics::ClassParams = {
	&ADnMPlayerController::StaticClass,
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
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADnMPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_ADnMPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADnMPlayerController()
{
	if (!Z_Registration_Info_UClass_ADnMPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADnMPlayerController.OuterSingleton, Z_Construct_UClass_ADnMPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADnMPlayerController.OuterSingleton;
}
template<> DADNME_API UClass* StaticClass<ADnMPlayerController>()
{
	return ADnMPlayerController::StaticClass();
}
ADnMPlayerController::ADnMPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADnMPlayerController);
ADnMPlayerController::~ADnMPlayerController() {}
// End Class ADnMPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADnMPlayerController, ADnMPlayerController::StaticClass, TEXT("ADnMPlayerController"), &Z_Registration_Info_UClass_ADnMPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADnMPlayerController), 257015869U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_3827624367(TEXT("/Script/DADnME"),
	Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
