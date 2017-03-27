#pragma once
#include "Drawer.h"
#include "define.h"

PTR( Past );

class Player {
public:
	Player( PastPtr past );
	virtual ~Player( );
public:
	void update( );
	GRAPH getGraph( ) const;
	bool isDead( ) const;
private:
	enum STATE {
		STATE_WAIT,
		STATE_HAMMER,
		MAX_STATE
	};
private:
	void move( );
	void fall( );
	void draw( ) const;
	void updateState( );
private:
	Vector _pos;
	Vector _vec;
	STATE _state;
	int _action_count;
	PastPtr _past;
};