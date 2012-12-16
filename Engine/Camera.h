#pragma once

class CCamera
{
public:
	CCamera(void);
	~CCamera(void);

	static void lookAt( float x, float y );
	static void lookAt( float pos[2] );
	static void lookAt();

	static void move( float x, float y );
	static void move( float vectorU[2] );

	union Position
	{
		float pos[2];
		struct
		{
			float x, y;
		};
	};

	static Position position;
};

typedef CCamera GCamera;
