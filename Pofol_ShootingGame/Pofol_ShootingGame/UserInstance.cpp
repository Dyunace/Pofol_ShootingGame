#include "UserInstance.h"

UserInstance* UserInstance::Instance = nullptr;
UserInstance::UserInstance() : Life(0), Score(0), Boom(0), BulletName("NormalBullet"), BulletLevel(0) {}
UserInstance::~UserInstance(){}