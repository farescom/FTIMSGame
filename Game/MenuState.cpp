#include "gameHeader.h"

MenuState::MenuState(void)
{
}

MenuState::~MenuState(void)
{
}

bool MenuState::initialize()
{
	if( texture.Load( "../Data/Textures/wood.bmp" ) == false )
		return false;

	return true;
}

void MenuState::shutdown()
{
	texture.Shutdown();
}

bool MenuState::update()
{
	if( GInput::KHit( VK_ESCAPE ) )
		return false;

	if( GInput::KHit( 'm' ) )
		GStateManager::setDefaultState();

	return true;
}

void MenuState::render()
{
	texture.Render();
	GDraw::rectf( SColor( 1.0f, 1.0f, 0.0f ), 1.2f, -0.5f, 0.1f, 0.1f );
	GDraw::textf( SColor( 1.0f, 1.0f, 0.0f ), 0.2f, -0.1f, "Press ESC to exit! (This is a MenuState)" );
}
