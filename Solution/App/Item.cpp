#include "Item.h"
#include "define.h"

static const int CHIP_SIZE = 128;

Item::Item( Vector pos ) :
_pos( pos ) {
}


Item::~Item( ) {
}

void Item::update( Matrix mat, int oliginal_num ) {
	Vector central_oliginal( oliginal_num / 2, oliginal_num / 2 );
	Vector central_frame( DOT_NUM / 2, DOT_NUM / 2 );
	Vector vec = _pos - central_oliginal;
	vec = mat.multiply( vec );
	Vector pos = vec + central_frame;
	int x = (int)( pos.x * DOT_SIZE - CHIP_SIZE / 2 );
	int y = (int)( pos.y * DOT_SIZE - CHIP_SIZE / 2 );

	DrawerPtr drawer = Drawer::getTask( );
	Drawer::Transform trans( x, y );
	Drawer::Sprite sprite( trans, GRAPH_ITEM );
	drawer->drawSpriteToGraph( GRAPH_SCREEN_FUTURE, sprite );
}