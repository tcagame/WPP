#pragma once
#include "Task.h"
#include <string>

PTR( Game );
PTR( Frame );
PTR( Past );

class Game : public Task {
public:
	static std::string getTag( ) { return "GAME"; };
	static GamePtr getTask( );
public:
	Game( );
	virtual ~Game( );
public:
	void initialize( );
	void update( );
private:
	FramePtr _frame;
	PastPtr _past;
};

