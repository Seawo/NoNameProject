// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHpBarUI.h"
#include "Components\ProgressBar.h"
#include "Components\TextBlock.h"
#include "Components\CanvasPanel.h"

void UEnemyHpBarUI::NativeConstruct()
{
	//enemy hp = progress  ��Ī
	// Text�� ��Ī
	
}

void UEnemyHpBarUI::UpdateHp(int32 currentHp, int32 maxHp)
{
    if (progressBar_HpBar)
    {
        // ü�� ���� ���
        float hpRatio = FMath::Clamp(static_cast<float>(currentHp) / static_cast<float>(maxHp), 0.0f, 1.0f);

        UE_LOG(LogTemp, Warning, TEXT("CurrentHp: %d, MaxHp: %d, HpRatio: %f"), currentHp, maxHp, hpRatio);


        // ���α׷����� ������Ʈ
        progressBar_HpBar->SetPercent(hpRatio);

    }

    if (txt_EnemyHp)
    {
        // ü�� �ؽ�Ʈ ������Ʈ
        txt_EnemyHp->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), currentHp, maxHp)));
    }

}


