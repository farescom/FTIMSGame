#pragma once
class CStateManager
{
public:
	CStateManager(void);
	~CStateManager(void);

	static void setState( IState* newState );
	static void setDefaultState();

private:
	static bool update();
	static void render();

	static IState* activeState;
	static IState* nextState;

	static bool isActive;

	friend int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

};

typedef CStateManager GStateManager;

