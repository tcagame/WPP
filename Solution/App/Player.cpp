#include "Player.h"
#include "Application.h"
#include "Future.h"
#include "Past.h"
#include "device.h"

static const int CHIP_SIZE = 128;
static const double GRAVITY = 0.098;
static const double MAX_SPEED = 1.0;
static const Vector START_POS( 30, 12 );
static const int PATTERN_NUM = 8;
static const int WAIT_ANIM_TIME = 4;
static const double HAMMER_MOVE_SPEED_RATIO = 0.3;
static const int DEAD_LINE = DOT_NUM + 4;
static const int HAMMER_PATTERN_NUM = 8;
static const int HAMMER_COUNT = HAMMER_PATTERN_NUM * WAIT_ANIM_TIME;
static const double JUMP_POW = 1.0;
static const double HEIGHT = 5.0;
static const int MAX_HIT = 3;

Player::Player( PastPtr past, FuturePtr future ) :
_pos( START_POS ),
_action( ACTION_STANDING ),
_past( past ),
_future( future ),
_pattern( 0 ),
_hammer_count( 0 ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_CHARACTER, "character.png" );
}


Player::~Player( ) {
}

void Player::update( ) {
	_action_count++;

	switch ( _action ) {
	case ACTION_STANDING:
		actOnStanding( );
		break;
	case ACTION_FLOATING:
		actOnFloating( );
		break;
	case ACTION_HAMMER:
		actOnHammer( );
		break;
	}

	draw( );
	DrawerPtr drawer = Drawer::getTask( );
	drawer->drawString( 10, 10, "プレイヤーの座標\nx:%d y:%d", (int)_pos.x, (int)_pos.y );
}

void Player::actOnStanding( ) {
	DevicePtr device = Device::getTask( );
	char device_x = device->getDirX( );
	_vec.x = device_x / 100;
	if ( device_x != 0 ) {
		_hammer_count = 0;
	}
	_pattern = 8;

	if ( !isStanding( ) ) {
		changeAction( ACTION_FLOATING );
	}

	if ( device->getPush( ) & BUTTON_A ) {
		changeAction( ACTION_HAMMER );
	}
	if ( device->getPush( ) & BUTTON_C ) {
		_vec.y -= JUMP_POW;
		_hammer_count = 0;
	}

	move( );
}

void Player::actOnFloating( ) {
	move( );

	_pattern = 0;

	if ( isStanding( ) ) {
		changeAction( ACTION_STANDING );
	}

	DevicePtr device = Device::getTask( );
	if ( device->getPush( ) & BUTTON_A ) {
		_action = ACTION_HAMMER;
	}
}

void Player::actOnHammer( ) {

	_pattern = 24 + _action_count / ( HAMMER_COUNT / HAMMER_PATTERN_NUM );
	if ( _action_count > HAMMER_COUNT ) {
		_pattern = 8;
		_hammer_count++;
		_future->erase( _pos, HEIGHT / 2 );
		if ( _hammer_count >= MAX_HIT ) {
			_future->change( );
			_hammer_count = 0;
		}
		changeAction( ACTION_STANDING );
	}
}

bool Player::isStanding( ) const {
	return _standing;
}

void Player::move( ) {
	_vec.y += GRAVITY;

	_standing = false;
	double add_y = 0.0;
	double adjust_y = GRAVITY / 2;
	if ( _vec.y < -0.01 ) {
		add_y = HEIGHT;
		adjust_y = -HEIGHT - 1;
	}

	Vector check_pos = _pos + _vec;
	check_pos.y -= add_y;
	if ( _past->isExistance( check_pos ) ) {
		_vec.y = 0.0;
		_standing = true;
		do {
			//２回目以降のadjustの値がおかしい
			_pos.y = ( int )check_pos.y - adjust_y;
			check_pos.y = _pos.y - add_y;
		} while ( _past->isExistance( check_pos ) && adjust_y > 0.01 );
	}

	if ( _vec.getLength( ) > MAX_SPEED ) {
		_vec = _vec.normalize( ) * MAX_SPEED;
	}
	_pos += _vec;
}

GRAPH Player::getGraph( ) const {
	return GRAPH_SCREEN_CHARACTER;
}

void Player::draw( ) const {
	if ( _pos.x < 0 || _pos.y < 0 ) {
		DrawerPtr drawer = Drawer::getTask( );
		drawer->createGraph( GRAPH_SCREEN_CHARACTER, PAINTING_SIZE, PAINTING_SIZE );	
		return;
	}
	int x = (int)( _pos.x * DOT_SIZE - CHIP_SIZE / 2 );
	int y = (int)( _pos.y * DOT_SIZE - CHIP_SIZE );
	int tx = _pattern % PATTERN_NUM * CHIP_SIZE;
	int ty = _pattern / PATTERN_NUM * CHIP_SIZE;
	Drawer::Transform trans( x, y, tx, ty, CHIP_SIZE, CHIP_SIZE );
	Drawer::Sprite sprite( trans, GRAPH_CHARACTER );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->createGraph( GRAPH_SCREEN_CHARACTER, PAINTING_SIZE, PAINTING_SIZE );
	drawer->drawSpriteToGraph( GRAPH_SCREEN_CHARACTER, sprite );
}

bool Player::isDead( ) const {
	return ( _pos.y > DEAD_LINE );
}

void Player::changeAction( ACTION action ) {
	_action = action;
	_action_count = 0;
}