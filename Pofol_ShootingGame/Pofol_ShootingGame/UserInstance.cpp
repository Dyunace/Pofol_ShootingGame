#include "UserInstance.h"

UserInstance* UserInstance::Instance = nullptr;
UserInstance::UserInstance() : Life(3), Boom(2), Score(0), BulletName("NormalBullet"), BulletLevel(2) {};
UserInstance::~UserInstance() {};