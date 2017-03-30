#pragma once
#include "define.h"

PTR( Item );

const int ORIGINAL_NUM = 100;

class Future
{
public:
	Future( );
	virtual ~Future( );
public:
	GRAPH getGraph( ) const;
	void update( );
	void change( );
	void erase( Vector pos, int radius ); 
private:
	void load( );
private:
	double _rot;
	ItemPtr _item;
	int _sheet;
	char _data[ ORIGINAL_NUM * ORIGINAL_NUM + 1 ];
};

