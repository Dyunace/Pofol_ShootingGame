#pragma once

// Key
const DWORD KEY_UP = 1;
const DWORD KEY_DOWN = 2;
const DWORD KEY_LEFT = 4;
const DWORD KEY_RIGHT = 8;
const DWORD KEY_SPACE = 16;
const DWORD KEY_ENTER = 32;
const DWORD KEY_CTRL = 64;
const DWORD KEY_ALT = 128;
const DWORD KEY_TAB = 256;
const DWORD KEY_ESC = 512;
const DWORD KEY_F = 1024;
const DWORD KEY_D = 2048;


// Buffer
const int BUFFER_OVER = 1;
const int MAX_SIZE = 2;


// Console Window
const SHORT ConsoleWidthSize = 80;
const SHORT ConsoleHeightSize = 55;


// String
const string PLAYER = "00_Player";
const string NORMALENEMY = "01_NormalEnemy";
const string SMALLENEMY = "02_SmallEnemy";
const string BIGENEMY = "03_BigEnemy";

const string NORMALBULLET = "10_NormalBullet";
const string LASERBULLET = "11_LaserBullet";
const string BOOM = "19_Boom";

const string ENORMALBULLET = "20_ENormalBullet";
const string ESPECIALBULLET = "21_ESpecialBullet";

const string STAGE1_BOSS_CORE = "30_Stage1_Boss_Core";
const string STAGE1_BOSS_HEAD = "30_Stage1_Boss_Head";
const string STAGE1_BOSS_ARM_LEFT = "30_Stage1_Boss_Arm_Left";
const string STAGE1_BOSS_ARM_RIGHT = "30_Stage1_Boss_Arm_Right";
const string STAGE1_BOSS_SHIELD_LEFT = "30_Stage1_Boss_Shield_Left";
const string STAGE1_BOSS_SHIELD_RIGHT = "30_Stage1_Boss_Shield_Right";

// ETC
const int EnemyBulletTargetY = 50;