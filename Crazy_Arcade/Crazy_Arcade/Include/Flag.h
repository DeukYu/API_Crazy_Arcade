
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
	AT_ATLAS, // �������� �پ��ִ� �̹���
	AT_FRAME, // ������ ������ �ִ� �̹���
	AT_END
};

// Animation Option
enum ANIMATION_OPTION
{
	AO_LOOP,	// �̹��� ������ �ݺ� ex)IDLE ���
	AO_ONCE_RETURN,	// Default�� �ٽ� ����
	AO_ONCE_DESTROY, // ����Ʈ ���� �͵� ó�� - �ִϸ��̼��� ���ư��� ���� ������ �����
	AO_TIME_RETURN, // ���� �ð����� ���ư�
	AO_TIME_DESTROY // ���� �ð� ���Ŀ� �����
};

// Scene Change
enum SCENE_CHANGE
{
	SC_NONE,
	SC_CHANGE
};