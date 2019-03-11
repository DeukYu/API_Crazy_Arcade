
#pragma once


typedef		struct _tagResolution
{
	long		iW;
	long		iH;

	_tagResolution() :
		iW(0), iH(0)
	{

	}

	_tagResolution(int x, int y) :
		iW(x), iH(y)
	{

	}
}RESOULTION, *PRESOULTION;

typedef struct _tagPosition
{
	float x, y;

	_tagPosition() :
		x(0.f), y(0.f)
	{

	}

	_tagPosition(float _x, float _y) :
		x(_x), y(_y)
	{

	}

	_tagPosition(const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}

	_tagPosition(const POINT& pt)
	{
		x = (float)pt.x;
		y = (float)pt.y;
	}
	void operator=(const _tagPosition& pos)
	{
		x = pos.x;
		y = pos.y;
	}
	void operator=(const POINT& pt)
	{
		x = (float)pt.x;
		y = (float)pt.y;
	}
	void operator=(float f[2])
	{
		x = f[0];
		y = f[1];
	}

	// + 연산자 오버로딩
	_tagPosition	operator+(const _tagPosition& pos)	const
	{
		_tagPosition	tPos;
		tPos.x = x + pos.x;
		tPos.y = y + pos.y;
		return tPos;
	}
	_tagPosition	operator+(const POINT& pos)	const
	{
		_tagPosition		tPos;
		tPos.x = (float)(x + pos.x);
		tPos.y = (float)(y + pos.y);
		return tPos;
	}
	_tagPosition	operator+(float f[2]) const
	{
		_tagPosition		tPos;
		tPos.x = x + f[0];
		tPos.y = y + f[1];
		return tPos;
	}
	_tagPosition	operator+(float f)	const
	{
		_tagPosition	tPos;
		tPos.x = x + f;
		tPos.y = y + f;
	}
	void operator+=(const _tagPosition& pos)
	{
		x += pos.x;
		y += pos.y;
	}

	//- 연산자 오버로딩
	_tagPosition	operator - (const _tagPosition&	pos)	const
	{
		_tagPosition		tPos;
		tPos.x = x - pos.x;
		tPos.y = y - pos.y;
		return tPos;
	}
	_tagPosition	operator - (const POINT&	pos)	const
	{
		_tagPosition		tPos;
		tPos.x = (float)(x - pos.x);
		tPos.y = (float)(y - pos.y);
		return tPos;
	}
	_tagPosition	operator - (float	f[2])	const
	{
		_tagPosition		tPos;
		tPos.x = x - f[0];
		tPos.y = y - f[1];
		return tPos;
	}
	_tagPosition	operator - (float	f)	const
	{
		_tagPosition		tPos;
		tPos.x = x - f;
		tPos.y = y - f;
		return tPos;
	}
	void operator	-=	(const _tagPosition& pos)
	{
		x -= pos.x;
		y -= pos.y;
	}

	// * 연산자 오버로딩
	_tagPosition	operator * (const _tagPosition&	pos)	const
	{
		_tagPosition		tPos;
		tPos.x = x * pos.x;
		tPos.y = y * pos.y;
		return tPos;
	}
	_tagPosition	operator * (const POINT&	pos)	const
	{
		_tagPosition		tPos;
		tPos.x = (float)(x * pos.x);
		tPos.y = (float)(y * pos.y);
		return tPos;
	}
	_tagPosition	operator * (float	f[2])	const
	{
		_tagPosition		tPos;
		tPos.x = x * f[0];
		tPos.y = y * f[1];
		return tPos;
	}
	_tagPosition	operator * (float	f)	const
	{
		_tagPosition		tPos;
		tPos.x = x * f;
		tPos.y = y * f;
		return tPos;
	}

	// / 연산자 오버로딩
	_tagPosition	operator / (const _tagPosition&	pos)	const
	{
		_tagPosition		tPos;
		tPos.x = x / pos.x;
		tPos.y = y / pos.y;
		return tPos;
	}
	_tagPosition	operator / (const POINT&	pos)	const
	{
		_tagPosition		tPos;
		tPos.x = (float)(x / pos.x);
		tPos.y = (float)(y / pos.y);
		return tPos;
	}
	_tagPosition	operator / (float	f[2])	const
	{
		_tagPosition		tPos;
		tPos.x = x / f[0];
		tPos.y = y / f[1];
		return tPos;
	}

	_tagPosition	operator / (float	f)	const
	{
		_tagPosition		tPos;
		tPos.x = x / f;
		tPos.y = y / f;
		return tPos;
	}
}POSITION, *PPOSITION, _SIZE, *_PSIZE;

typedef struct _tagRectangle
{
	float left, top, right, bottom;

	_tagRectangle() :
		left(0.f), top(0.f), right(0.f), bottom(0.f)
	{

	}
}RECTANGLE, *PRECTANGLE;

typedef struct _tagSphere
{
	POSITION	tCenter;
	float			fRadius;

	_tagSphere() :
		tCenter(0.f, 0.f), fRadius(0.f)
	{

	}
}SPHERE, *PSPHERE;

typedef struct _tagPixel
{
	unsigned char r, g, b;
}PIXEL, *PPIXEL;

typedef struct _tagAnimationClip
{
	ANIMATION_TYPE			eType;
	ANIMATION_OPTION		eOption;
	vector<class CTxture*>	vecTexture;
	float		fAnimationTime;
	float		fAnimationLimitTime;
	float		fAnimationFrameTime;
	int		iFrameX, iFrameY;
	int		iFrameMaxX, iFrameMaxY;
	int		iStartX, iStartY;
	int		iLengthX, iLengthY;
	float		fOptionTime;
	float		fOptionLimitTime;
	_SIZE	tFrameSize;
}ANIMATIONCLIP, *PANIMATIONCLIP;