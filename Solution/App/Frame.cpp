#include "Frame.h"
#include "Drawer.h"
#include "define.h"
#include "Application.h"

const int CHIP_SIZE = 64;

Frame::Frame( ) {
	DrawerPtr drawer = Drawer::getTask( );
	drawer->loadGraph( GRAPH_FRAME, "frame.png" );
	
	// ƒtƒŒ[ƒ€ƒTƒCƒY
	ApplicationPtr app = Application::getInstance( );
	_size = app->getWindowHeight( ) - CHIP_SIZE * 2;
	_width  = app->getWindowWidth( );
}


Frame::~Frame( ) {
}

void Frame::draw( GRAPH graph ) const {
	drawGraph( graph );
	drawFrame( );
}

void Frame::drawGraph( GRAPH graph  )  const {
	// ƒtƒŒ[ƒ€‚ÌƒTƒCƒY‚É‡‚í‚¹‚Äk¬‚µ‚Ä•`‰æ
	int x1 = ( _width - _size ) / 2;
	int x2 = x1 + _size;
	int y1 = CHIP_SIZE;
	int y2 = y1 + _size;
	Drawer::Transform trans( x1, y1, 0, 0, PAINTING_SIZE, PAINTING_SIZE, x2, y2 );
	Drawer::Sprite sprite( trans, graph );

	DrawerPtr drawer = Drawer::getTask( );
	drawer->setSprite( sprite );
}

void Frame::drawFrame( ) const {
	DrawerPtr drawer = Drawer::getTask( );
	

	{	// ¶ãŠp
		int x = ( _width - _size ) / 2 - CHIP_SIZE;
		int y = 0;
		Drawer::Transform trans( x, y, CHIP_SIZE * 0, 0, CHIP_SIZE, CHIP_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
	{	// ‰EãŠp
		int x = ( _width + _size ) / 2;
		int y = 0;
		Drawer::Transform trans( x, y, CHIP_SIZE * 1, 0, CHIP_SIZE, CHIP_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
	{	// ¶‰ºŠp
		int x = ( _width - _size ) / 2 - CHIP_SIZE;
		int y = _size + CHIP_SIZE;
		Drawer::Transform trans( x, y, CHIP_SIZE * 2, 0, CHIP_SIZE, CHIP_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
	{	// ‰E‰ºŠp
		int x = ( _width + _size ) / 2;
		int y = _size + CHIP_SIZE;
		Drawer::Transform trans( x, y, CHIP_SIZE * 3, 0, CHIP_SIZE, CHIP_SIZE );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}

	{	// ã•Ó
		int x1 = ( _width - _size ) / 2;
		int y1 = 0;
		int x2 = x1 + _size;
		int y2 = y1 + CHIP_SIZE;
		Drawer::Transform trans( x1, y1, CHIP_SIZE * 0, CHIP_SIZE, CHIP_SIZE, CHIP_SIZE, x2, y2 );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
	{	// ‰º•Ó
		int x1 = ( _width - _size ) / 2;
		int y1 = _size + CHIP_SIZE;
		int x2 = x1 + _size;
		int y2 = y1 + CHIP_SIZE;
		Drawer::Transform trans( x1, y1, CHIP_SIZE * 1, CHIP_SIZE, CHIP_SIZE, CHIP_SIZE, x2, y2 );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
	{	// ¶•Ó
		int x1 = ( _width - _size ) / 2 - CHIP_SIZE;
		int y1 = CHIP_SIZE;
		int x2 = x1 + CHIP_SIZE;
		int y2 = y1 + _size;
		Drawer::Transform trans( x1, y1, CHIP_SIZE * 2, CHIP_SIZE, CHIP_SIZE, CHIP_SIZE, x2, y2 );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
	{	// ‰E•Ó
		int x1 = ( _width + _size ) / 2;
		int y1 = CHIP_SIZE;
		int x2 = x1 + CHIP_SIZE;
		int y2 = y1 + _size;
		Drawer::Transform trans( x1, y1, CHIP_SIZE * 3, CHIP_SIZE, CHIP_SIZE, CHIP_SIZE, x2, y2 );
		Drawer::Sprite sprite( trans, GRAPH_FRAME );
		drawer->setSprite( sprite );
	}
}
