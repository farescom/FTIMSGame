#include "Engine.h"

CCamera::Position CCamera::position;

CCamera::CCamera(void)
{
}

CCamera::~CCamera(void)
{
}

void CCamera::lookAt( float x, float y )
{
	position.x = x;
	position.y = y;
}

void CCamera::lookAt( float pos[2] )
{
	position.pos[0] = pos[0];
	position.pos[1] = pos[1];
}

void CCamera::lookAt()
{
	glTranslatef( -position.x, -position.y, 0.0f );
}

void CCamera::move( float x, float y )
{
	position.x += x;
	position.y += y;
}

void CCamera::move( float vectorU[2] )
{
	position.pos[0] += vectorU[0];
	position.pos[1] += vectorU[1];
}
