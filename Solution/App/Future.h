#pragma once
#include "define.h"

PTR( Item );
PTR( Past );
PTR( Player );

const int ORIGINAL_NUM = 100;

class Future
{
public:
	Future( PastPtr past );
	virtual ~Future( );
public:
	GRAPH getGraph( ) const;
	void update( );
	void change( );
	void erase( Vector pos, double radius );
	bool isGetItem( Vector pos );
private:
	void load( );
private:
	double _rot;
	ItemPtr _item;
	int _sheet;
	char _data[ ORIGINAL_NUM * ORIGINAL_NUM + 1 ];
	PastPtr _past;
};

