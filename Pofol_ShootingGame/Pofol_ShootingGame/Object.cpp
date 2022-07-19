#include "Object.h"

Object::Object() : TransInfo(), str(), hp(0), Speed(0), pBridge(nullptr), DelayCount(0) {}
Object::Object(Transform _Info) : TransInfo(_Info), str(), hp(0), Speed(0), pBridge(nullptr), DelayCount(0) {}
Object::~Object(){}
