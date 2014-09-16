#include "PreCompiled.h"

//class header file
#include "Screen.h"

Screen::Screen(Context* context)
{
	this->context = context;
	//by default all screens always draw
	this->alwaysDraw = false;
	//by default screens don't block updating of other screens
	this->blockUpdate = false;
}


Screen::~Screen()
{
}
