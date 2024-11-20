// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyState_RandomPourLighting.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet\GameplayStatics.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

void UNotifyState_RandomPourLighting::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	me = MeshComp->GetOwner();

	if (!me)
		return;

	CenterPos = me->GetActorLocation();

	world = me->GetWorld();

	float spawnNumFloat = static_cast<float>(spawnNum*2);

	circleIndex = 0;
	magicIndex = 0;

	// ������ = ����ð� / 1�� / ����
	delayTime = 300.0f / 60.0f / spawnNumFloat*2;
	spawnPos.Empty();

	for (int i = 0; i < spawnNum; i++)
	{
		FVector randomDir = UKismetMathLibrary::RandomUnitVector();
		float randomDis = FMath::RandRange(spawnMinRadius, spawnMaxRadius);

		spawnPos.Add(CenterPos + randomDir * randomDis);
		spawnPos[i].Z = 0.1f;

		// spawn ���̾ư��� ��Ŭ 
	}


	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Blue, TEXT("NotifyBegin"));
}

void UNotifyState_RandomPourLighting::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	currentTime += FrameDeltaTime;

	if (currentTime >= delayTime)
	{
		currentTime = 0;
		
		if (circleIndex < spawnNum)
		{
			// circle �����ϰ�
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, magicCircle, spawnPos[circleIndex], FRotator::ZeroRotator);

			circleIndex++;
		}
		else
		{
			if (magicIndex > spawnNum)
				return;

			// õ�� ġ��
			int32 Randomindex = FMath::RandRange(0, lightningEffects.Num() - 1);

			UGameplayStatics::SpawnEmitterAtLocation(world, lightningEffects[Randomindex], spawnPos[magicIndex], FRotator::ZeroRotator);

			magicIndex++;
		}
	}


    //GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("NotifyTick"));
}

void UNotifyState_RandomPourLighting::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("NotifyEnd"));
}
