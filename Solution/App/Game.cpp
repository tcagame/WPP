#include "Game.h"
#include "Application.h"
#include "Frame.h"
#include "Past.h"
#include "Future.h"
#include "Drawer.h"
#include "Player.h"

GamePtr Game::getTask( ) {
	ApplicationPtr app = Application::getInstance( );
	return std::dynamic_pointer_cast< Game >( app->getTask( getTag( ) ) );
}

Game::Game( ) {
}


Game::~Game( ) {
}

void Game::initialize( ) {
	_frame = FramePtr( new Frame );
	_past = PastPtr( new Past );
	_future = FuturePtr( new Future );
	_player = PlayerPtr( new Player );
}

void Game::update( ) {
	_past->update( );
	_future->update( );
	_player->update( _past );
	_frame->draw( _past->getGraph( ) );
	_frame->draw( _player->getGraph( ) );
	_frame->draw( _future->getGraph( ) );
}