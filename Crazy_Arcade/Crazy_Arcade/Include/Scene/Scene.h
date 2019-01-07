#pragma once

#include "../Game.h"

class CScene
{
protected:
	friend	class CSceneManager;
	
protected:
	CScene();
	virtual	~CScene()		=		0; // ���������Լ�

public:
	virtual bool Init();
};

