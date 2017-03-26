#include "Player.h"
#include "Application.h"
#include "Past.h"
#include "Frame.h"

static const int CHIP_SIZE = 64;
static const int GRAVITY = 1;
static const int MAX_SPEED = 15;
static const Vector START_POS( 512, 100 );

Player::Player( ) :
_pos( START_POS ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER, "character.png" );
}


Player::~Player( ) {
}

void Player::update( PastPtr past ) {
	fall( );
	move( past );
	setGraph( );
}

void Player::move( PastPtr past ) {
	if ( _vec.y > 0 ) {
		Vector check_pos = _pos + _vec;
		if ( past->isExistance( check_pos ) ) {
			_vec.y = 0.0;
		}
	}

	_pos += _vec;
}

void Player::fall( ) {
	_vec.y += GRAVITY;
	if ( _vec.y > MAX_SPEED ) {
		_vec.y = MAX_SPEED;
	}
}

GRAPH Player::getGraph( ) const {
	return GRAPH_SCREEN_CHARACTER;
}

void Player::setGraph( ) const {
	int x = (int)_pos.x - CHIP_SIZE / 2;
	int y = (int)_pos.y - CHIP_SIZE;
	Drawer::Transform trans( x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, x + CHIP_SIZE, y + CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_CHARACTER );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->createGraph( GRAPH_SCREEN_CHARACTER, PAINTING_SIZE, PAINTING_SIZE );
	drawer->drawSpriteToGraph( GRAPH_SCREEN_CHARACTER, sprite );
}