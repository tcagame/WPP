#pragma once
#include "Drawer.h"
#include "define.h"

PTR( Past );

class Player {
public:
	Player( );
	virtual ~Player( );
public:
	void update( PastPtr past );
	GRAPH getGraph( ) const;
private:
	void move( PastPtr past );
	void fall( );
	void draw( ) const;
private:
	Vector _pos;
	Vector _vec;
};