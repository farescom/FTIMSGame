#include "Engine.h"

IState* CStateManager::activeState;
IState* CStateManager::nextState;
bool CStateManager::isActive = false;

CStateManager::CStateManager(void)
{
}

CStateManager::~CStateManager(void)
{
}

void CStateManager::setState( IState* newState )
{
	nextState = newState;
}

void CStateManager::setDefaultState()
{
	nextState = 0;
	activeState->shutdown();
	activeState = 0;
	isActive = false;
}

bool CStateManager::update()
{
	if( nextState )
	{
		if( activeState )
		{
			activeState->shutdown();
		}

		activeState = nextState;
		nextState = 0;

		if( activeState->initialize() == false )
		{
			activeState->shutdown();
			return false;
		}

		isActive = true;
	}
	else
	{
		if( activeState )
			if( activeState->update() == false )
				return false;
	}

	return true;
}

void CStateManager::render()
{
	if( activeState )
			activeState->render();
}