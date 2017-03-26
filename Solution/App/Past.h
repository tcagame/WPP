#pragma once
#include "define.h"
#include "mathmatics.h"

class Past {
public:
	Past( );
	virtual ~Past( );
public:
	GRAPH getGraph( ) const;
	void update( );
	bool isExistance( Vector pos ) const;
};

