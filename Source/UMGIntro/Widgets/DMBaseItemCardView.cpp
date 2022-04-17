/**
 * @author Justin Noel
 * @file   DMBaseItemCardView.cpp
 */

#include "DMBaseItemCardView.h"
#include "../Data/Model/DMCollection.h"

void UDMBaseItemCardView::SetupData(const UDMBase* BaseItem)
{
	if (!IsValid(BaseItem))
		return;

	mBaseItem = BaseItem;
	
	if(BaseItem->IsA(UDMCollection::StaticClass()))
	{
		mIsCollection = true;
		SetupCollection();
	}
	
	if (IsValid(BaseItem->mImage)) 
	{
		SetupImage(BaseItem->mImage->mUrl);
	}
	SetupTitle(BaseItem->mName);
}