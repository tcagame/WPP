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
	enum ACTION {
		ACTION_STANDING,
		ACTION_FLOATING,
		ACTION_HAMMER,
		MAX_ACTION
	};
private:
	void move( );
	void draw( ) const;
	void actOnStanding( );
	void actOnFloating( );
	void actOnHammer( );
	bool isStanding( ) const;
	void changeAction( ACTION action );
private:
	Vector _pos;
	Vector _vec;
	ACTION _action;
	PastPtr _past;
	int _pattern;
	int _action_count;
	bool _standing;
};