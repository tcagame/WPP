#include "Application.h"
#include "Drawer.h"
#include "Game.h"
#include "device.h"

void main( ) {
	TaskPtr game   = TaskPtr( new Game( ) );
	TaskPtr drawer = TaskPtr( new Drawer( "Resource" ) );
	TaskPtr device = TaskPtr( new Device( ) );

	ApplicationPtr app = Application::getInstance( );
	app->addTask( Game::getTag( ), game );
	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Device::getTag( ), device );
}