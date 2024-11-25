// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyState_RandomLighting.h"
#include "Enemy.h"
#include "Kismet\GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
//#include "NiagaraComponent.h"
#include "ParticleActor.h"


void UNotifyState_RandomLighting::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	auto me = MeshComp->GetOwner();

	if (!me)
		return;

	FVector CenterPos = me->GetActorLocation();

	UWorld* world = me->GetWorld();

	spawnPos.Empty();

	if (world)
	{
		for (int32 i = 0; i < spawnNum; i++)
		{
			FVector RandomDir = UKismetMathLibrary::RandomUnitVector();
			float RandomDis = FMath::FRandRange(spawnMinRadius, spawnMaxRadius);

			// ���� ��ġ ��� = ���� ��ġ + ����*�Ÿ�
			spawnPos.Add(CenterPos + RandomDir * RandomDis);
			spawnPos[i].Z = 0.1f;

			UNiagaraFunctionLibrary::SpawnSystemAtLocation(world, magicCircle, spawnPos[i], FRotator::ZeroRotator);

			//// ����� �� ǥ�� (����, ũ��, ���� �ð� ���� ����)
			//DrawDebugPoint(world, spawnPos[i], 10.0f, FColor::Blue, false, 2.0f);

			//// �Ǵ� ����� �� ǥ��
			//DrawDebugSphere(world, spawnPos[i], 50.0f, 12, FColor::Green, false, 2.0f);
		}
	}
}

void UNotifyState_RandomLighting::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	auto me = MeshComp->GetOwner();

	if (!me)
		return;

	FVector CenterPos = me->GetActorLocation();

	UWorld* world = me->GetWorld();

	if (world)
	{
		for (int32 i = 0; i < spawnNum; i++)
		{
			
			//niagaraComp[i]->DestroyComponent();

			int32 Randomindex = FMath::RandRange(0, particleActors.Num() - 1);

			/*UGameplayStatics::SpawnEmitterAtLocation(world, lightningEffects[Randomindex], spawnPos[i], FRotator::ZeroRotator);*/
		
			// Actor�� ��ü
			world->SpawnActor<AParticleActor>(particleActors[Randomindex], spawnPos[i], FRotator::ZeroRotator);

			//// ����� �� ǥ�� (����, ũ��, ���� �ð� ���� ����)
			//DrawDebugPoint(world, spawnPos[i], 10.0f, FColor::Blue, false, 2.0f);

			//// �Ǵ� ����� �� ǥ��
			//DrawDebugSphere(world, spawnPos[i], 50.0f, 12, FColor::Green, false, 2.0f);
		}
	}

}
