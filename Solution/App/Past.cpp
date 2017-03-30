#include "Past.h"
#include "define.h"
#include "Drawer.h"

const char DATA[ DOT_NUM * DOT_NUM + 1 ] = 
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
"                                                                "
" ***************                                                "
"               *                                                "
"               *                                                "
"               *                                                "
"               *                                                "
"               *                                                "
"               *                                                "
"               *                                                "
"*****************                                      *********"
"********************                           *****************"
"**********************                     *********************"
"**********************                 *************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************"
"****************************************************************";

Past::Past( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->createGraph( GRAPH_SCREEN_PAST, PAINTING_SIZE, PAINTING_SIZE );
	drawer->loadGraph( GRAPH_PAST_DOT, "past_dot.png" );
	
	for ( int i = 0; i < DOT_NUM * DOT_NUM; i++ ) {
		if ( DATA[ i ] != '*' ) {
			continue;
		}
		_data[ i ] = DATA[ i ];
		int x = i % DOT_NUM * DOT_SIZE;
		int y = i / DOT_NUM * DOT_SIZE;
		Drawer::Transform trans( x, y );
		Drawer::Sprite sprite( trans, GRAPH_PAST_DOT );
		drawer->drawSpriteToGraph( GRAPH_SCREEN_PAST, sprite );
	}
}

Past::~Past( ) {

}

void Past::update( ) {
}

GRAPH Past::getGraph( ) const {
	return GRAPH_SCREEN_PAST;
}

bool Past::isExistance( Vector pos ) const {
	int x = (int)pos.x;
	int y = (int)pos.y;
	if ( x < 0 || x > DOT_NUM ||
		 y < 0 || y > DOT_NUM ) {
		return false;
	}
	int idx = y * DOT_NUM + x;
	if ( _data[ idx ] == '*' ) {
		return true;
	}
	return false;
}

void Past::addPicture( char data[ ] ) {
	DrawerPtr drawer = Drawer::getTask( );
	for ( int i = 0; i < DOT_NUM * DOT_NUM; i++ ) {
		if ( _data[ i ] == '*' ) {
			continue;
		}
		_data[ i ] = data[ i ];
		if ( _data[ i ] != '*' ) {
			continue;
		}
		int x = i % DOT_NUM * DOT_SIZE;
		int y = i / DOT_NUM * DOT_SIZE;
		Drawer::Transform trans( x, y );
		Drawer::Sprite sprite( trans, GRAPH_PAST_DOT );
		drawer->drawSpriteToGraph( GRAPH_SCREEN_PAST, sprite );
	}
}
