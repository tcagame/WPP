#include "Player.h"
#include "Application.h"
#include "Past.h"

static const int CHIP_SIZE = 64;
static const double GRAVITY = 0.098;
static const double MAX_SPEED = 1.0;
static const Vector START_POS( 30, 12 );

Player::Player( ) :
_pos( START_POS ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER, "character.png" );
}


Player::~Player( ) {
}

void Player::update( PastPtr past ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "プレイヤーの座標\nx:%d y:%d", (int)_pos.x, (int)_pos.y );
	if ( isDead( ) ) {
		return;//死んだら処理しない
	}
	fall( );
	move( past );
	draw( );
}

void Player::move( PastPtr past ) {
	if ( _vec.y > 0 ) {
		Vector check_pos = _pos + _vec;
		if ( past->isExistance( check_pos ) ) {
			_vec.y = 0.0;
		}
	}

	if ( _vec.getLength( ) > MAX_SPEED ) {
		_vec = _vec.normalize( ) * MAX_SPEED;
	}
	_pos += _vec;
}

void Player::fall( ) {
	_vec.y += GRAVITY;
}

GRAPH Player::getGraph( ) const {
	return GRAPH_SCREEN_CHARACTER;
}

void Player::draw( ) const {
	int x = (int)_pos.x * DOT_SIZE - CHIP_SIZE / 2;
	int y = (int)_pos.y * DOT_SIZE - CHIP_SIZE;
	Drawer::Transform trans( x, y, 0, 0, CHIP_SIZE, CHIP_SIZE, x + CHIP_SIZE, y + CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_CHARACTER );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->createGraph( GRAPH_SCREEN_CHARACTER, PAINTING_SIZE, PAINTING_SIZE );
	drawer->drawSpriteToGraph( GRAPH_SCREEN_CHARACTER, sprite );
}

bool Player::isDead( ) const {
	return ( _pos.y - ( (double)CHIP_SIZE / DOT_SIZE ) > DOT_NUM );
}
