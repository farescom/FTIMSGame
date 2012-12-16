#pragma once

class MenuState : public IState
{
public:
	MenuState(void);
	~MenuState(void);

	CTexture texture;

	bool initialize();
	void shutdown();
	bool update();
	void render();
};

