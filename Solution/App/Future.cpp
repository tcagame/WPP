#include "Drawer.h"
#include "Future.h"

const int DOT_SIZE = 16;
const int DOT_NUM = PAINTING_SIZE / DOT_SIZE;
const int ORIGINAL_NUM = 100;

const char DATA[ ORIGINAL_NUM * ORIGINAL_NUM + 1 ] = 
"                                                                                                    "
"                                                                                                    "
"                               *********************************                                    "
"                                                                                                    "
"                                                                                                    "
"                               **********************************************                       "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                 **********************************************************         "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                *******************************************************                             "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"             *****************************************************************************          "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"         **************************************************************                             "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    "
"                                                                                                    ";
















Future::Future( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->createGraph( GRAPH_SCREEN_FUTURE, PAINTING_SIZE, PAINTING_SIZE );
	drawer->loadGraph( GRAPH_FUTURE_DOT, "future_dot.png" );

	for ( int i = 0; i < DOT_NUM; i++ ) {
		for ( int j = 0; j < DOT_NUM; j++ ) {
			int xx = ( ORIGINAL_NUM - DOT_NUM ) / 2 + i;
			int yy = ( ORIGINAL_NUM - DOT_NUM ) / 2 + j;
			int idx = xx + yy * ORIGINAL_NUM;
			if ( DATA[ idx ] != '*' ) {
				continue;
			}
			int x = i * DOT_SIZE;
			int y = j * DOT_SIZE;
			Drawer::Transform trans( x, y );
			Drawer::Sprite sprite( trans, GRAPH_FUTURE_DOT );
			drawer->drawSpriteToGraph( GRAPH_SCREEN_FUTURE, sprite );
		}
	}

}


Future::~Future( ) {
}

GRAPH Future::getGraph( ) const {
	return GRAPH_SCREEN_FUTURE;
}

void Future::update( ) {
}