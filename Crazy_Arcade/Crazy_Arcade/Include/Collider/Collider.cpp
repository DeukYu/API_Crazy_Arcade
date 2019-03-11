#include "Collider.h"
#include "../Object/Obj.h"
#include "../Math.h"

CCollider::CCollider()
{
}

CCollider::CCollider(const CCollider & coll)
{
	*this = coll;
}


CCollider::~CCollider()
{
	list<CCollider*>::iterator	iter;
	list<CCollider*>::iterator	iterEnd = m_CollisionList.end();

	for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->EraseCollisionList(this);
	}
}

void CCollider::Input(float fDeltaTime)
{
}

int CCollider::Update(float fDeltaTime)
{
	return 0;
}

int CCollider::LateUpdate(float fDeltaTime)
{
	return 0;
}

bool CCollider::Collision(CCollider * pDest)
{
	return false;
}

void CCollider::Render(HDC hDC, float fDeltaTime)
{
}

bool CCollider::CollisionRectToRect(const RECTANGLE & src, const RECTANGLE & dest)
{
	if (src.left > dest.right)
		return false;
	else if (src.right < dest.left)
		return false;
	else if (src.top > dest.bottom)
		return false;
	else if (src.bottom < dest.top)
		return false;
	return true;
}

bool CCollider::CollisionRectToSphere(const RECTANGLE & src, const SPHERE & dest)
{
	// 원의 중점의 x좌표가 사각형의 가로 영역 안에 있는지, 원의 중점의 y좌표가 사각형의 세로 영역 안에 있는지 체크한다.
	// 둘 중 하나라도 맞다면, 사각형의 위, 아래, 좌, 우 영역 안에 존재한다는 것이다.
	if ((src.left <= dest.tCenter.x && dest.tCenter.x <= src.right) ||
		(src.top <= dest.tCenter.y && dest.tCenter.y <= src.bottom))
	{
		RECTANGLE	tRC = src;
		tRC.left			-= dest.fRadius;
		tRC.top			-= dest.fRadius;
		tRC.right		+= dest.fRadius;
		tRC.bottom	+= dest.fRadius;

		if (dest.tCenter.x < tRC.left)
			return false;
		else if (dest.tCenter.x > tRC.right)
			return false;
		else if (dest.tCenter.y < tRC.top)
			return false;
		else if (dest.tCenter.y > tRC.bottom)
			return false;
		return true;
	}

	// 사각형의 꼭지점 중에 하나라도 원 안에 있을 경우, 충돌!!
	POSITION	tPos[4];
	tPos[0] = POSITION(src.left, src.top);
	tPos[1] = POSITION(src.right, src.top);
	tPos[2] = POSITION(src.left, src.bottom);
	tPos[3] = POSITION(src.right, src.bottom);

	for (int i = 0; i < 4; ++i)
	{
		float fDist = CMath::Distance(tPos[i], dest.tCenter);

		if (fDist <= dest.fRadius)
			return true;
	}
	return false;
}

bool CCollider::CollisionSphereToSphere(const SPHERE & src, const SPHERE & dest)
{
	float fDist = CMath::Distance(src.tCenter, dest.tCenter);

	return fDist <= src.fRadius + dest.fRadius;
}

bool CCollider::CollisionRectToPixel(const RECTANGLE & src, const vector<PIXEL>& vecPixel, int iWidth, int iHeight)
{
	m_tHitPoint.x = -1;
	m_tHitPoint.y = -1;

	int iStartX, iEndX;
	int iStartY, iEndY;

	iStartX = src.left < 0 ? 0 : src.left;
	iEndX = src.right >= iWidth ? iWidth - 1 : src.right;

	iStartY = src.top < 0 ? 0 : src.top;
	iEndY = src.bottom >= iHeight ? iHeight - 1 : src.bottom;

	for (int i = iStartY; i <= iEndY; ++i)
	{
		for (int j = iStartX; j <= iStartX; ++j)
		{
			int idx = i * iWidth + j;
			const PIXEL&	pixel = vecPixel[idx];
			if (pixel.r = 255 && pixel.g == 0 && pixel.b == 255)
			{
				m_tHitPoint.x = j;
				m_tHitPoint.y = i;
				return true;
			}
		}
	}
	return false;
}

bool CCollider::CollisionSphereToPixel(const SPHERE & src, const vector<PIXEL>& vecPixel, int iWidth, int iHeight)
{
	return false;
}

bool CCollider::CollisionRectToPoint(const RECTANGLE & src, const POSITION & dest)
{
	if (dest.x < src.left)
		return false;
	else if (dest.x > src.right)
		return false;
	else if (dest.y < src.top)
		return false;
	else if (dest.y > src.bottom)
		return false;
	return true;
}

bool CCollider::CollisionSphereToPoint(const SPHERE & src, const POSITION & dest)
{
	return CMath::Distance(dest, src.tCenter) <= src.fRadius;
}

bool CCollider::CollisionPixelToPoint(const vector<PIXEL>& vecPixel, int iWidth, int iHeight, const POSITION & dest)
{
	if(dest.y < 0 || dest.x < 0 || dest.y >= iWidth || dest.y >= iHeight)
		return false;

	int idx = (int)dest.y * iWidth + (int)dest.x;
	const PIXEL&	pixel = vecPixel[idx];
	if (pixel.r == 255 && pixel.g == 0 && pixel.b == 255)
	{
		m_tHitPoint = dest;
		return true;
	}
	return false;
}
