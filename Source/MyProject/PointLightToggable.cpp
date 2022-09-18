//=============================================================================
// Togglable version of Point Light (UDK)
//=============================================================================

#include "PointLightToggable.h"
#include "Components/PointLightComponent.h"

//
// Constructor
//
APointLightToggable::APointLightToggable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	IEntity::Constructor(this);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComp0"));
	SetRootComponent(PointLight);

	RegisterState(&APointLightToggable::TurnOn, "TurnOn");
	RegisterState(&APointLightToggable::TurnOff, "TurnOff");
}

//
// Serialize
//
void APointLightToggable::SerializeActor(FArchive &Ar)
{
	IEntity::SerializeActor(Ar);

	ArBit(PointLight->bVisible);

	if (Ar.IsLoading())
	{
		PointLight->SetVisibility(PointLight->bVisible);
		PointLight->MarkRenderStateDirty();
	}
}

//
// Turn on lights!
//
void APointLightToggable::TurnOn()
{
	PointLight->SetVisibility(true);
	OnTurnedOn.Broadcast();
}

//
// Turn off lights!
//
void APointLightToggable::TurnOff()
{
	PointLight->SetVisibility(false);
	OnTurnedOff.Broadcast(); 
}

//
// Toggle lights!
//
void APointLightToggable::Toggle()
{
	if (PointLight->bVisible)
		GotoState("TurnOff");
	else
		GotoState("TurnOn");
}
