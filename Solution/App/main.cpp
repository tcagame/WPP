#include "Application.h"
#include "Drawer.h"
#include "Game.h"
#include "Keyboard.h"

void main( ) {
	TaskPtr game   = TaskPtr( new Game( ) );
	TaskPtr drawer = TaskPtr( new Drawer( "Resource" ) );
	TaskPtr keyboard = TaskPtr( new Keyboard( ) );

	ApplicationPtr app = Application::getInstance( );
	app->addTask( Game::getTag( ), game );
	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Keyboard::getTag( ), keyboard );
}