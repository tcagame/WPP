#include "Drawer.h"
#include "Future.h"

const int ORIGINAL_NUM = 100;
const double ROT_SPEED = 0.05;

const char DATA[ ORIGINAL_NUM * ORIGINAL_NUM + 1 ] = 
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
"                                                                                                    "
"                                              *                                                     "
"                                              *                                                     "
"                                              *                                                     "
"                                              *                                                     "
"                                             ***                                                    "
"                                            *****                                                   "
"                                          *********                                                 "
"                                         ***********                                                "
"                                        *************                                               "
"***                                    ***** *** *****                                              "
" ***                                   **** * * * ****                                              "
"  ***                                  **** * * * ****                                              "
"                                       ** ** *** ** **                                              "
"                                       **  *******  **                                              "
"                                        **         **                                               "
"                                         ***********                                                "
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

	_rot = 0;
}


Future::~Future( ) {
}

GRAPH Future::getGraph( ) const {
	return GRAPH_SCREEN_FUTURE;
}

void Future::update( ) {
	_rot += ROT_SPEED;
	
	DrawerPtr drawer = Drawer::getTask( );
	
	drawer->clearToGraph( GRAPH_SCREEN_FUTURE );

	for ( int i = 0; i < DOT_NUM; i++ ) {
		for ( int j = 0; j < DOT_NUM; j++ ) {
			//�@����]
			Vector vec(
				i - DOT_NUM / 2,
				j - DOT_NUM / 2 );
			Matrix mat = Matrix::makeTransformRotation( Vector( 0, 0, 1 ), _rot );
			vec = mat.multiply( vec );
			int xx = ( int )vec.x + ORIGINAL_NUM / 2;
			int yy = ( int )vec.y + ORIGINAL_NUM / 2;
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