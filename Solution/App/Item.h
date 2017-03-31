#pragma once
#include "Drawer.h"

class Item {
public:
	Item( Vector pos );
	virtual ~Item( );
public:
	void update( Matrix mat, int oliginal_num );
	Vector getPos( );
	Vector rotetion( Matrix mat, int oliginal_num );
private:
	Vector _pos;
};

