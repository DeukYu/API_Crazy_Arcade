#include "Layer.h"
#include "../Object/Obj.h"
#include "../Collider/CollisionManager.h"


CLayer::CLayer()	:
	m_iZOrder(0),
	m_strTag(" "),
	m_pScene(NULL),
	m_bLife(true),
	m_bEnable(true)
{
}


CLayer::~CLayer()
{
	list<CObj*>::iterator	iter;
	list<CObj*>::iterator	iterEnd = m_ObjList.end();

	for (iter = m_ObjList.begin(); iter != iterEnd; ++iter)
	{
		CObj::EraseObj(*iter);
		SAFE_RELEASE((*iter));
	}
	m_ObjList.clear();
}

void CLayer::AddObject(CObj * pObj)
{
}

void CLayer::Input(float fDeltaTime)
{
}

int CLayer::Update(float fDeltaTime)
{
	return 0;
}

int CLayer::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CLayer::Collision(float fDeltaTime)
{
}

void CLayer::Render(HDC hDC, float fDeltaTime)
{
}
