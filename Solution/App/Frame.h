#pragma once
#include "define.h"

class Frame {
public:
	Frame( );
	virtual ~Frame( );
public:
	void draw( GRAPH graph ) const;
private:
	void drawGraph( GRAPH graph ) const;
	void drawFrame( ) const;
private:
	int _size;
	int _width;
};

