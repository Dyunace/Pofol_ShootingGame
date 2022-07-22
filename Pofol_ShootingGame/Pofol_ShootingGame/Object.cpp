#include "Object.h"

Object::Object() : TransInfo(), str(), pBridge(nullptr), DelayCount(0) {}
Object::Object(Transform _Info) : TransInfo(_Info), str(), pBridge(nullptr), DelayCount(0) {}
Object::~Object(){}
