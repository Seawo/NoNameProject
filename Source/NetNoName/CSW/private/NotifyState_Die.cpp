// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyState_Die.h"
#include "Components\SkeletalMeshComponent.h"
#include "Materials\MaterialInstanceDynamic.h"
#include "ParticleActor.h"

void UNotifyState_Die::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	AActor* my = MeshComp->GetOwner();

	FVector pos = my->GetActorLocation();
	FRotator rot = FRotator::ZeroRotator;

	FHitResult hitInfo;
	FVector start = pos + FVector(0, 0, 5000.0f);
	FVector end = pos + FVector(0, 0, -5000.0f);

	bool bHit = GetWorld()->LineTraceSingleByChannel(hitInfo, start, end, ECollisionChannel::ECC_Visibility);

	if (bHit)
	{
		// ���� ������
		pos.Z = hitInfo.Location.Z;
	}
	else
	{
		pos.Z = -250.0f;
	}


	my->GetWorld()->SpawnActor<AParticleActor>(p_Actor, pos, rot);

	if (MeshComp)
	{
		// ��Ƽ������ �������� ����
		mt_Dynamic = MeshComp->CreateAndSetMaterialInstanceDynamic(0);
		if (mt_Dynamic)
		{
			opacity = 1.0f; // �ʱ� Opacity
			mt_Dynamic->SetScalarParameterValue("Opacity", opacity);
		}
	}
}

void UNotifyState_Die::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	if (mt_Dynamic)
	{
		// �� �����Ӹ��� Opacity�� ���� 0.5�� ���� �ӵ�

		opacity = FMath::Clamp(opacity - FrameDeltaTime * 0.5f, 0.0f, 1.0f);
		mt_Dynamic->SetScalarParameterValue("Opacity", opacity);
	}
}

void UNotifyState_Die::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (MeshComp)
	{
		if (opacity <= 0.0f)
		{
			MeshComp->GetOwner()->Destroy();
		}
	}

}
