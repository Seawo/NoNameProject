// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHpBarUI.h"
#include "Components\ProgressBar.h"
#include "Components\TextBlock.h"

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
        progressBar_HpBar->SetPercent(hpRatio); // ���α׷����� ������Ʈ
    }

    if (txt_EnemyHp)
    {
        // ü�� �ؽ�Ʈ ������Ʈ
        txt_EnemyHp->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), currentHp, maxHp)));
    }


}
