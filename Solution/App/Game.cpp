#include "Game.h"
#include "Application.h"
#include "Frame.h"
#include "Past.h"

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
}

void Game::update( ) {
	_past->update( );
	_frame->draw( _past->getGraph( ) );
}