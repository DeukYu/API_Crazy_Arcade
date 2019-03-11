#pragma once

#include "../Game.h"

class CScene
{
protected:
	friend	class CSceneManager;
	
protected:
	CScene();
	virtual	~CScene()		=		0; // ���������Լ� : �߻� Ŭ������ ������ش�.

private:
	static unordered_map<string, class CObj*> m_mapPrototype[SC_END];
public:
	virtual bool Init();
};

