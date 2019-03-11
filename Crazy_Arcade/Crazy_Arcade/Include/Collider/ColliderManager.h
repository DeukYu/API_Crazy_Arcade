#pragma once
#include "../Game.h"

class CColliderManager
{
private:
	list<class CObj*>	m_CollisionList;

public:
	void AddObject(class CObj* pObj);
	void Collision(float fDeltaTime);
	bool Collision(class CObj* pSrc, CObj* pDest, float fDeltaTime);
	void Clear();

	DECLARE_SINGLE(CColliderManager)
};

