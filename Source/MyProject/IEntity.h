//=============================================================================
// IEntity
//=============================================================================
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCH.h"
#include "Delegates/Delegate.h"
#include "IEntity.generated.h"

class FArchive;
class IEntity;
typedef void (IEntity::*FState)(void);
#define TO_FUNC(a) static_cast <void (IEntity::*)(void)> (a)
#define RegisterState(funcPtr, funcName) _RegisterState(TO_FUNC(funcPtr), funcName)

struct FStateData
{
	FTimerHandle timeHandle;
	FString execState;
	FString curState;
	float gameTime;
	float lastTime;
	FState pfnState; // fw
};

// delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSimpleBPEvent);

UINTERFACE(MinimalAPI, Blueprintable)
class UEntity : public UInterface
{
	GENERATED_BODY()
};

class IEntity
{
// ########################## IEntity ##########################
	GENERATED_BODY()
public:
	void Constructor(AActor *pActor);
	virtual void SerializeActor(FArchive &Ar);
private:
	AActor *selfActor;
// ########################## State System ##########################
protected:
	void _RegisterState(const FState &pFunc, const char* szName);
	void GotoState(const char *szName);
	FORCEINLINE const char* GetStateName() { return T2A(*timeState.curState); }
	FORCEINLINE float GetLastStateTime(const char* szName) { return timeState.lastTime; }
	FORCEINLINE bool IsInState(const char* szName) { return strlen(T2A(*timeState.curState)) ? true : false; }
	virtual void SerializeState(FArchive &Ar);
private:
	TArray<const char*> aStateNames;	// array of names states
	TArray<FState> aStateFuncs;			// array of funcs states
	FStateData timeState;				// timer data (timer. what state to play, when, where was last)
};
