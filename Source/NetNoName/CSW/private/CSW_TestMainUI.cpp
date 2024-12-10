// Fill out your copyright notice in the Description page of Project Settings.


#include "CSW_TestMainUI.h"
#include "Components\NamedSlot.h"
#include "EnemyHpBarUI.h"
#include "TransferToLevelUI.h"

void UCSW_TestMainUI::NativeConstruct()
{
	Super::NativeConstruct();


	AddEnemeyHpBar();

}

void UCSW_TestMainUI::AddEnemeyHpBar()
{
	if (!enemyHpBarFactory) return;

	enemyHp = CreateWidget<UEnemyHpBarUI>(GetWorld(), enemyHpBarFactory);
	// ü�� ���� �Լ� �ϳ� �����
	// slot�� ���̱�
	enemyHpSlot->AddChild(enemyHp);

	// �⺻������ ü���� ǥ��
	enemyHp->SetVisibility(ESlateVisibility::Visible);
}

void UCSW_TestMainUI::UpdateCurrentHp(int32 current, int32 maxHp)
{
	enemyHp->UpdateHp(current, maxHp);

	if (current <= 0)
	{
		FTimerHandle hpTimer;

		GetWorld()->GetTimerManager().SetTimer
		(
			hpTimer,
			[this]()
			{
				// �⺻������ ü���� ǥ��
				enemyHp->SetVisibility(ESlateVisibility::Hidden);
			}
			, 3.0f, false
		);
	}
}

void UCSW_TestMainUI::AddTransferLevel()
{
	if (transferToLevelFactory == nullptr) return;

	transferUI = CreateWidget<UTransferToLevelUI>(GetWorld(), transferToLevelFactory);

	transferSlot->AddChild(transferUI);
}


