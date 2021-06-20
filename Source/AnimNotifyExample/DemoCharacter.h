/*
*  Copyright (c) 2021 Damody(t1238142000@gmail.com).
*  All rights reserved.
*  @ Date : 2021/06/20
*
*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "DemoCharacter.generated.h"

UCLASS()
class ANIMNOTIFYEXAMPLE_API ADemoCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_UCLASS_BODY()

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
public:
	// Sets default values for this character's properties
	ADemoCharacter();

	UPROPERTY(BlueprintReadOnly)
	class UAbilitySystemComponent* AbilitySystem;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UGameplayAbility> DemoAbility;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;

};
