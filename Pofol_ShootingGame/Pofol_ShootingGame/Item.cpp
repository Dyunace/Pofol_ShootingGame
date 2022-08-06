#include "Item.h"
#include "Bridge.h"

Item::Item(){}
Item::Item(Transform _Info) : Object(_Info) {}
Item::~Item(){}

Object* Item::Initialize(string _Key)
{
	str = _Key;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6, 3);

	return this;
}

int Item::Update()
{
	int result = pBridge->Update();

	return result;
}

void Item::Render()
{
	pBridge->Render();
}

void Item::Release()
{
}
