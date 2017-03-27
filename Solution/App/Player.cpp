#include "Player.h"
#include "Application.h"
#include "Past.h"
#include "device.h"

static const int CHIP_SIZE = 64;
static const double GRAVITY = 0.098;
static const double MAX_SPEED = 1.0;
static const Vector START_POS( 30, 12 );
static const int HAMMER_ANIM_PATTERN = 8;
static const int WAIT_ANIM_TIME = 10;
static const double HAMMER_MOVE_SPEED_RATIO = 0.3;

Player::Player( ) :
_pos( START_POS ),
_state( STATE_WAIT ) {
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
	updateState( );
	fall( );
	action( );
	move( past );
	draw( );
}

void Player::updateState( ) {
	DevicePtr device = Device::getTask( );
	STATE state = STATE_WAIT;
	if ( device->getButton( ) & BUTTON_A ) {
		state = STATE_HAMMER;
	}
	if ( _state != state ) {
		_state = state;
		_action_count = 0;
	}
}

void Player::action( ) {
	switch ( _state ) {
	case STATE_WAIT:
		break;
	case STATE_HAMMER:
		break;
	}
	_action_count++;
}

void Player::move( PastPtr past ) {
	if ( _vec.y > 0 ) {
		Vector check_pos = _pos + _vec;
		if ( past->isExistance( check_pos ) ) {
			_vec.y = 0.0;
		}
	}

	double max_speed = MAX_SPEED;
	if ( _state == STATE_HAMMER ) {
		max_speed *= HAMMER_MOVE_SPEED_RATIO;
	}
	if ( _vec.getLength( ) > max_speed ) {
		_vec = _vec.normalize( ) * max_speed;
	}
	_pos += _vec;
}

void Player::fall( ) {
	double ratio = 1.0;
	if ( _state == STATE_HAMMER ) {
		ratio = HAMMER_MOVE_SPEED_RATIO;
	}
	_vec.y += GRAVITY * ratio;
}

GRAPH Player::getGraph( ) const {
	return GRAPH_SCREEN_CHARACTER;
}

void Player::draw( ) const {
	int x = (int)_pos.x * DOT_SIZE - CHIP_SIZE / 2;
	int y = (int)_pos.y * DOT_SIZE - CHIP_SIZE;
	int cx = 0;
	int cy = 0;
	switch ( _state ) {
	case STATE_WAIT:
		break;
	case STATE_HAMMER:
		cx = _action_count / WAIT_ANIM_TIME % HAMMER_ANIM_PATTERN;
		cy = 3;
		break;
	}
	Drawer::Transform trans( x, y, cx * CHIP_SIZE, cy * CHIP_SIZE, CHIP_SIZE, CHIP_SIZE, x + CHIP_SIZE, y + CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_CHARACTER );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->createGraph( GRAPH_SCREEN_CHARACTER, PAINTING_SIZE, PAINTING_SIZE );
	drawer->drawSpriteToGraph( GRAPH_SCREEN_CHARACTER, sprite );
}

bool Player::isDead( ) const {
	return ( _pos.y - ( (double)CHIP_SIZE / DOT_SIZE ) > DOT_NUM );
}