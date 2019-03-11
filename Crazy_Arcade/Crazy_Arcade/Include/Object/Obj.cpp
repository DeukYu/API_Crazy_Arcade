#include "Obj.h"



CObj::CObj()
{
}

CObj::CObj(const CObj & obj)
{
	*this = obj;
}


CObj::~CObj()
{
}

void CObj::AddObj(CObj * pObj)
{
}

CObj * CObj::FindObject(const string & strTag)
{
	return nullptr;
}

void CObj::EraseObj(CObj * pObj)
{
}

void CObj::EraseObj(const string & strTag)
{
}

void CObj::EraseObj()
{
}
