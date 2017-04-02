#include "Item.h"
#include "define.h"

static const int CHIP_SIZE = 128;

Item::Item( Vector pos ) :
_pos( pos ) {
}


Item::~Item( ) {
}

void Item::update( Matrix mat, int oliginal_num ) {
	Vector pos = rotetion( mat, oliginal_num );

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( (int)( pos.x - CHIP_SIZE / 2 ), (int)( pos.y - CHIP_SIZE / 2 ) );
	Drawer::Sprite sprite( trans, GRAPH_ITEM );
	drawer->drawSpriteToGraph( GRAPH_SCREEN_FUTURE, sprite );
	drawer->drawString( 0, 80, "x:%d y:%d", (int)( pos.x / DOT_SIZE ), (int)( pos.y / DOT_SIZE ) );
}

Vector Item::rotetion( Matrix mat, int oliginal_num ) {
	Vector central_oliginal( oliginal_num / 2, oliginal_num / 2 );
	Vector central_frame( DOT_NUM / 2, DOT_NUM / 2 );
	Vector vec = _pos - central_oliginal;
	vec = mat.multiply( vec );
	Vector pos = vec + central_frame;
	pos.x = pos.x * DOT_SIZE;
	pos.y = pos.y * DOT_SIZE;
	return pos;
}

Vector Item::getPos( Matrix mat, int oliginal_num ) {
	Vector pos = rotetion( mat, oliginal_num );
	pos = Vector( pos.x / DOT_SIZE, pos.y / DOT_SIZE );
	return pos;
}