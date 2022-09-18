//=============================================================================
// IEntity
//=============================================================================

#include "IEntity.h"
#include "Serialization/Archive.h"
#include "Engine.h"

//=============================================================================
// IENTITY

//
// Constructor
//
void IEntity::Constructor(AActor *pActor)
{
	selfActor = pActor;
}

//
// Serializing
//
void IEntity::SerializeActor(FArchive &Ar)
{
	if (selfActor->GetWorld())
	{
		SerializeState(Ar);
	}
}

//=============================================================================
// State System

//
// registration state logic
//
void IEntity::_RegisterState(const FState &pFunc, const char* szName)
{
	check(aStateNames.Num() == aStateFuncs.Num());
	aStateNames.Add(szName);
	aStateFuncs.Add(pFunc);
}

//
// Just execute state or time it
//
void IEntity::GotoState(const char *szName)
{
	int index = INDEX_NONE;
	for (int i = 0; i < aStateNames.Num(); i++)
	{
		if (!strcmp(szName, aStateNames[i]))
		{
			index = i;
			break;
		}
	}
	if (index != INDEX_NONE)
		timeState.curState = aStateNames[index];
	if (this->aStateFuncs[index])
	{
		(this->*(aStateFuncs[index]))();
		timeState.lastTime = selfActor->GetWorld()->TimeSeconds;
	}
}

//
// Serializing
//
void IEntity::SerializeState(FArchive &Ar)
{
	ArVar(timeState.curState);
	ArVar(timeState.execState);
	ArVar(timeState.gameTime);
	ArVar(timeState.lastTime);
}
