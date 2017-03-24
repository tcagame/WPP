#pragma once
#include "define.h"

class Future
{
public:
	Future( );
	virtual ~Future( );
public:
	GRAPH getGraph( ) const;
	void update( );
};

