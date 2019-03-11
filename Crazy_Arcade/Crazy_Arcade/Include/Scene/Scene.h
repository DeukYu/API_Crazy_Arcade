#pragma once

#include "../Game.h"

class CScene
{
protected:
	friend	class CSceneManager;
	
protected:
	CScene();
	virtual	~CScene()		=		0; // 순수가상함수 : 추상 클래스로 만들어준다.

private:
	static unordered_map<string, class CObj*> m_mapPrototype[SC_END];
public:
	virtual bool Init();
};

