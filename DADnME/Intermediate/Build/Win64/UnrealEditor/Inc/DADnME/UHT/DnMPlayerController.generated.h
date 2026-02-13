// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/DnMPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DADNME_DnMPlayerController_generated_h
#error "DnMPlayerController.generated.h already included, missing '#pragma once' in DnMPlayerController.h"
#endif
#define DADNME_DnMPlayerController_generated_h

#define FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADnMPlayerController(); \
	friend struct Z_Construct_UClass_ADnMPlayerController_Statics; \
public: \
	DECLARE_CLASS(ADnMPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DADnME"), NO_API) \
	DECLARE_SERIALIZER(ADnMPlayerController)


#define FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADnMPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADnMPlayerController(ADnMPlayerController&&); \
	ADnMPlayerController(const ADnMPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADnMPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADnMPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADnMPlayerController) \
	NO_API virtual ~ADnMPlayerController();


#define FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_12_PROLOG
#define FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_15_INCLASS_NO_PURE_DECLS \
	FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DADNME_API UClass* StaticClass<class ADnMPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_DADnME_Source_DADnME_Public_Player_DnMPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
