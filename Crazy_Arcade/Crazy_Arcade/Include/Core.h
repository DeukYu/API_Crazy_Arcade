#pragma once

#include "Game.h"

class CCore
{
private:
	static CCore*	m_pInst; // static 멤버 변수는 전역 변수처럼 취급,

public:
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	CCore();
	~CCore();

private:
	static bool		m_bLoop;

private:
	HINSTANCE		m_hInst;
	HWND				m_hWnd;
	HDC					m_hDC;
	RESOULTION	m_tRS;

public:
	RESOULTION	GetResolution()		const
	{
		return m_tRS;
	}

	HWND	GetWindowHandle()	const
	{
		return m_hWnd;
	}

	void DestroyGame()
	{
		DestroyWindow(m_hWnd);
	}
public:
	bool Init(HINSTANCE	hInst);
	int Run();

private:
	void	Logic();
	void Input(float fDeltaTime);
	int	Update(float	fDeltaTime);
	int	LateUpdate(float	fDeltaTime); // 후처리
	void	Collision(float	fDeltaTime);
	void	Render(float fDeltaTime);
private:
	ATOM	MyRegisterClass();
	BOOL	Create();

public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

