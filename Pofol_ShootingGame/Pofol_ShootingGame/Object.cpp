#include "Object.h"

Object::Object() : TransInfo(), str(), pBridge(nullptr), DelayCount(0), isVisible(true), canMove(true), canShoot(true), canRender(true) {}
Object::Object(Transform _Info) : TransInfo(_Info), str(), pBridge(nullptr), DelayCount(0), isVisible(true), canMove(true), canShoot(true), canRender(true) {}
Object::~Object(){}
