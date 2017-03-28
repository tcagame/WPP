#pragma once
#include "Drawer.h"

class Item {
public:
	Item( Vector pos );
	virtual ~Item( );
public:
	void update( Matrix mat, int oliginal_num );
private:
	Vector _pos;
};

