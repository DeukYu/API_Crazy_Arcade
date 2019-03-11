#include "PathManager.h"



CPathManager::CPathManager()
{
}


CPathManager::~CPathManager()
{
}

bool CPathManager::Init()
{
	wchar_t strPath[MAX_PATH] = {};

	GetModuleFileName(NULL, strPath, MAX_PATH);

	for (int i = lstrlen(strPath) - 1; i >= 0; --i)
	{
		if (strPath[i] == '/' || strPath[i] == '\\')
		{
			memset(strPath + (i + 1), sizeof(wchar_t) * (MAX_PATH - (i + 1)));
			break;
		}
	}

	m_mapPath.insert(make_pair(ROOT_PATH, strPath));

	// Texture ��� ����
	if (!CreatePath(TEXTURE_PATH, L"Texture\\"))
		return;

	return true;
}

bool CPathManager::CreatePath(const string & strKey, const wchar_t * pPath, const string & strBaseKey)
{
	const wchar_t*		pBasePath = FindPath(strBaseKey);

	wstring		strPath;

	if (pBasePath)
		strPath = pBasePath;

	strPath += pPath;

	m_mapPath.insert(make_pair(strKey, strPath));

	return true;
}

const wchar_t * CPathManager::FindPath(const string & strKey)
{
	unordered_map<string, wstring>::iterator iter = m_mapPath.find(strKey);

	if (iter == m_mapPath.end())
		return NULL;

	return iter->second.c_str();
}

const char * CPathManager::FindPathMultByte(const string & strKey)
{
	const wchar_t* pPath = FindPath(strKey);

	if (!pPath)
		return NULL;

	int iLen = WideCharToMultiByte(CP_ACP, 0, pPath, -1, NULL, 0, 0, 0);

	WideCharToMultiByte(CP_ACP, 0, pPath, -1, m_strPath, iLen, 0, 0);

	return m_strPath;
}
