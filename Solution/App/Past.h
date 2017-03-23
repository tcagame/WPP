#pragma once
#include "define.h"

class Past {
public:
	Past( );
	virtual ~Past( );
public:
	GRAPH getGraph( ) const;
	void update( );
};

