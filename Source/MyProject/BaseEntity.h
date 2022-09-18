//=============================================================================
// Base Entity
//============================================================================= 
#pragma once 

#include "IEntity.h"
#include "BaseEntity.generated.h"

UCLASS() 
class MYPROJECT_API ABaseEntity : public AActor, public IEntity
{
	GENERATED_BODY()
	
public:
	ABaseEntity(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
	{
		Constructor(this);
	}
};
