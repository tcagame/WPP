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
	void addPicture( char data[ ] );
	bool isExistance( Vector pos ) const;
private:
	char _data[ DOT_NUM * DOT_NUM + 1 ];
};

