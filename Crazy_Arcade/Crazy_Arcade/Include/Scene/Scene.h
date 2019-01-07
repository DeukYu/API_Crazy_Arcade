#pragma once

#include "../Game.h"

class CScene
{
protected:
	friend	class CSceneManager;
	
protected:
	CScene();
	virtual	~CScene()		=		0; // 순수가상함수

public:
	virtual bool Init();
};

