#include "Game.h"
#include "Application.h"
#include "Frame.h"

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
}

void Game::update( ) {
	_frame->draw( );
}