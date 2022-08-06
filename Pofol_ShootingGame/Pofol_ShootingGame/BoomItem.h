#pragma once
#include "ItemBridge.h"

class BoomItem : public ItemBridge
{
private:
	char* Buffer[5];

public:
	BoomItem();
	virtual ~BoomItem();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

