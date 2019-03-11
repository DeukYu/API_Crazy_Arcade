#include "ColliderManager.h"
#include "../Object/Obj.h"
#include "Collider.h"

DEFINITION_SINGLE(CColliderManager)

void CColliderManager::AddObject(CObj * pObj)
{
	if(pObj->CheckCollider())
}

void CColliderManager::Collision(float fDeltaTime)
{
}

bool CColliderManager::Collision(CObj * pSrc, CObj * pDest, float fDeltaTime)
{
	return false;
}

void CColliderManager::Clear()
{
}
