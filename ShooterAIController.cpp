// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
        //PlayerCharactor
        PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        //Setting StartLocation
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
}

bool AShooterAIController::IsDead() const
{
    AShooterCharacter* Character =  Cast<AShooterCharacter>(GetPawn());
    if (Character != nullptr)
    {
        return Character->IsDead();
    }
    return true;
}
