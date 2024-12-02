// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Blueprint/UserWidget.h"
#include "EnemyGameState.generated.h"

/**
 * 
 */
UCLASS()
class NETNONAME_API AEnemyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;


public:

	//class UEnemyHpBarUI* GetEnemyHpUI();

	template <typename T>
	T* GetGameUI(TSubclassOf<T> WidgetClass);

public:
	// ���⼭ �� ������� �ִµ�?
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UEnemyHpBarUI> enemyHpBarUIFactory;

	// �����غ��ϱ� Enemy�� ������� ���ڳ�?? �׿� �ʿ��Ѱ� ���� �ֳ�??

	/*UPROPERTY()
	class UEnemyHpBarUI* enemyHpBarUI;*/

	

};


