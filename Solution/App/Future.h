#pragma once
#include "define.h"

PTR( Item );

class Future
{
public:
	Future( );
	virtual ~Future( );
public:
	GRAPH getGraph( ) const;
	void update( );
private:
	void load( );
private:
	double _rot;
	ItemPtr _item;
};

