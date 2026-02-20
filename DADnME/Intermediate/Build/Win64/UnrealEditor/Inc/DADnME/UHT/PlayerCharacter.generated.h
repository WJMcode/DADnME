// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Player/PlayerCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DADNME_PlayerCharacter_generated_h
#error "PlayerCharacter.generated.h already included, missing '#pragma once' in PlayerCharacter.h"
#endif
#define DADNME_PlayerCharacter_generated_h

#define FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPlayerCharacter(); \
	friend struct Z_Construct_UClass_APlayerCharacter_Statics; \
public: \
	DECLARE_CLASS(APlayerCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/DADnME"), NO_API) \
	DECLARE_SERIALIZER(APlayerCharacter)


#define FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	APlayerCharacter(APlayerCharacter&&); \
	APlayerCharacter(const APlayerCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APlayerCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APlayerCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APlayerCharacter) \
	NO_API virtual ~APlayerCharacter();


#define FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h_18_PROLOG
#define FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h_21_INCLASS_NO_PURE_DECLS \
	FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DADNME_API UClass* StaticClass<class APlayerCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_DADnME_Source_DADnME_Public_Player_PlayerCharacter_h


#define FOREACH_ENUM_EMOVESTATE(op) \
	op(EMoveState::Stop) \
	op(EMoveState::Move) \
	op(EMoveState::Sprint) 

enum class EMoveState : uint8;
template<> struct TIsUEnumClass<EMoveState> { enum { Value = true }; };
template<> DADNME_API UEnum* StaticEnum<EMoveState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
