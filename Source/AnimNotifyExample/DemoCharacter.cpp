/*
*  Copyright (c) 2021 Damody(t1238142000@gmail.com).
*  All rights reserved.
*  @ Date : 2021/06/20
*
*/

#include "DemoCharacter.h"

UAbilitySystemComponent* ADemoCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

// Sets default values
ADemoCharacter::ADemoCharacter(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Full);
}

// Called when the game starts or when spawned
void ADemoCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystem)
	{
		if (HasAuthority() && DemoAbility)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(DemoAbility.GetDefaultObject(), 1, 0));
		}
		AbilitySystem->InitAbilityActorInfo(this, this);
	}
}

// Called every frame
void ADemoCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ADemoCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADemoCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (AbilitySystem)
	{
		AbilitySystem->RefreshAbilityActorInfo();
	}
}

