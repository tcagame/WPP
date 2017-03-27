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
	bool isDead( ) const;
private:
	enum STATE {
		STATE_WAIT,
		STATE_HAMMER,
		MAX_STATE
	};
private:
	void action( );
	void move( PastPtr past );
	void fall( );
	void draw( ) const;
	void updateState( );
private:
	Vector _pos;
	Vector _vec;
	STATE _state;
	int _action_count;
};