#include "Application.h"
#include "Drawer.h"
#include "Game.h"

void main( ) {
	TaskPtr game   = TaskPtr( new Game( ) );
	TaskPtr drawer = TaskPtr( new Drawer( "Resource" ) );

	ApplicationPtr app = Application::getInstance( );
	app->addTask( Game::getTag( ), game );
	app->addTask( Drawer::getTag( ), drawer );
}