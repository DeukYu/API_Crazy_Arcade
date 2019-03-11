
#pragma once

// Scene Type
enum SCENE_CREATE
{
	SC_CURRENT,
	SC_NEXT,
	SC_END
};

// Direction
enum MOVE_DIR
{
	MD_BACK = -1,
	MD_NONE,
	MD_FRONT
};

// Collider Type
enum COLLIDER_TYPE
{
	CT_RECT,
	CT_SPHERE,
	CT_LINE,
	CT_POINT,
	CT_PIXEL,
	CT_END
};

// Collision State
enum COLLISION_STATE
{
	CS_ENTER,
	CS_STAY,
	CS_LEAVE,
	CS_END
};

// Animation Type
enum ANIMATION_TYPE
{
	AT_ATLAS, // 여러장이 붙어있는 이미지
	AT_FRAME, // 낱개로 나뉘어 있는 이미지
	AT_END
};

// Animation Option
enum ANIMATION_OPTION
{
	AO_LOOP,	// 이미지 동작이 반복 ex)IDLE 모션
	AO_ONCE_RETURN,	// Default로 다시 복귀
	AO_ONCE_DESTROY, // 이펙트 같은 것들 처리 - 애니메이션이 돌아가고 나서 스스로 사라짐
	AO_TIME_RETURN, // 일정 시간동안 돌아감
	AO_TIME_DESTROY // 일정 시간 이후에 사라짐
};

// Scene Change
enum SCENE_CHANGE
{
	SC_NONE,
	SC_CHANGE
};