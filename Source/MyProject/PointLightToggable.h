//=============================================================================
// Togglable version of Point Light (UDK)
//============================================================================= 
#pragma once

#include "BaseEntity.h"
#include "PointLightToggable.generated.h"

UCLASS() 
class MYPROJECT_API APointLightToggable : public ABaseEntity
{
	GENERATED_BODY()
	
public:
	APointLightToggable(const FObjectInitializer& ObjectInitializer);
	virtual void SerializeActor(FArchive &Ar) override;

protected:
	UFUNCTION(BlueprintCallable) void TurnOn();
	UFUNCTION(BlueprintCallable) void TurnOff();
	UFUNCTION(BlueprintCallable) void Toggle();
	UPROPERTY(BlueprintAssignable) FSimpleBPEvent OnTurnedOn;
	UPROPERTY(BlueprintAssignable) FSimpleBPEvent OnTurnedOff;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", ExposeFunctionCategories = "PointLight,Rendering|Lighting"), Category = PointLight)  class UPointLightComponent *PointLight;
};
