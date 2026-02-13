// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DADnME/Public/Player/Input/InputTriggerDoubleTap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInputTriggerDoubleTap() {}

// Begin Cross Module References
DADNME_API UClass* Z_Construct_UClass_UInputTriggerDoubleTap();
DADNME_API UClass* Z_Construct_UClass_UInputTriggerDoubleTap_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputTrigger();
UPackage* Z_Construct_UPackage__Script_DADnME();
// End Cross Module References

// Begin Class UInputTriggerDoubleTap
void UInputTriggerDoubleTap::StaticRegisterNativesUInputTriggerDoubleTap()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInputTriggerDoubleTap);
UClass* Z_Construct_UClass_UInputTriggerDoubleTap_NoRegister()
{
	return UInputTriggerDoubleTap::StaticClass();
}
struct Z_Construct_UClass_UInputTriggerDoubleTap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xee\xb0\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xbf\xef\xbf\xbd \xef\xbf\xbd\xde\xb8\xef\xbf\xbd\xef\xbf\xbd\xe2\xb8\xa6 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \n */" },
#endif
		{ "IncludePath", "Player/Input/InputTriggerDoubleTap.h" },
		{ "ModuleRelativePath", "Public/Player/Input/InputTriggerDoubleTap.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xc3\xb7\xef\xbf\xbd\xef\xbf\xbd\xcc\xbe\xee\xb0\xa1 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xcf\xbf\xef\xbf\xbd \xef\xbf\xbd\xde\xb8\xef\xbf\xbd\xef\xbf\xbd\xe2\xb8\xa6 \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xac\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DoubleTapThreshold_MetaData[] = {
		{ "Category", "Trigger" },
		{ "ModuleRelativePath", "Public/Player/Input/InputTriggerDoubleTap.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DoubleTapThreshold;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UInputTriggerDoubleTap>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UInputTriggerDoubleTap_Statics::NewProp_DoubleTapThreshold = { "DoubleTapThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UInputTriggerDoubleTap, DoubleTapThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DoubleTapThreshold_MetaData), NewProp_DoubleTapThreshold_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UInputTriggerDoubleTap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UInputTriggerDoubleTap_Statics::NewProp_DoubleTapThreshold,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInputTriggerDoubleTap_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UInputTriggerDoubleTap_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInputTrigger,
	(UObject* (*)())Z_Construct_UPackage__Script_DADnME,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInputTriggerDoubleTap_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UInputTriggerDoubleTap_Statics::ClassParams = {
	&UInputTriggerDoubleTap::StaticClass,
	"Input",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UInputTriggerDoubleTap_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UInputTriggerDoubleTap_Statics::PropPointers),
	0,
	0x401030A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInputTriggerDoubleTap_Statics::Class_MetaDataParams), Z_Construct_UClass_UInputTriggerDoubleTap_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UInputTriggerDoubleTap()
{
	if (!Z_Registration_Info_UClass_UInputTriggerDoubleTap.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInputTriggerDoubleTap.OuterSingleton, Z_Construct_UClass_UInputTriggerDoubleTap_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UInputTriggerDoubleTap.OuterSingleton;
}
template<> DADNME_API UClass* StaticClass<UInputTriggerDoubleTap>()
{
	return UInputTriggerDoubleTap::StaticClass();
}
UInputTriggerDoubleTap::UInputTriggerDoubleTap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UInputTriggerDoubleTap);
UInputTriggerDoubleTap::~UInputTriggerDoubleTap() {}
// End Class UInputTriggerDoubleTap

// Begin Registration
struct Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_Input_InputTriggerDoubleTap_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UInputTriggerDoubleTap, UInputTriggerDoubleTap::StaticClass, TEXT("UInputTriggerDoubleTap"), &Z_Registration_Info_UClass_UInputTriggerDoubleTap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInputTriggerDoubleTap), 2966992195U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_Input_InputTriggerDoubleTap_h_2302975856(TEXT("/Script/DADnME"),
	Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_Input_InputTriggerDoubleTap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_DADnME_Source_DADnME_Public_Player_Input_InputTriggerDoubleTap_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
