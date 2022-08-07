#pragma once
#include "ItemBridge.h"

class WeaponItem : public ItemBridge
{
private:
	char* Buffer[5];

	int ItemCount;
	string ItemType;

public:
	WeaponItem();
	virtual ~WeaponItem();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	string GetItemType() { return ItemType; }
};

