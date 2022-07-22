// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLASTER_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Mark as friend cause Blaster Character will work very close with this component and we need an easy access
	friend class ABlasterCharacter;

	void EquipWeapon(AWeapon* WeaponToEquip);

protected:
	virtual void BeginPlay() override;


private:
	// Forward pointer ot character to manage the acces on methods.
	class ABlasterCharacter* Character;
	AWeapon* EquippedWeapon;

public:	
	

		
};
