// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/NameTagWidget.h"

#include "Components/TextBlock.h"

void UNameTagWidget::SetText(FName NewText)
{
    Name->SetText(FText::FromName(NewText));

    OnSetText(NewText);
}
