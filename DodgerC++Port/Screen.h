#pragma once

//for game definitions
#include "GameDefenitions.h"


class Screen : private sf::NonCopyable
{
public:
	typedef std::unique_ptr<Screen> Ptr;


public:
	Screen(Context* context);
	virtual ~Screen();

public:

	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void handleEvents(const sf::Event& event) = 0;

public:
	//does the screen block updating other screens
	bool isBlocking() { return blockUpdate; }

	//does the screen always need to be drawn
	bool isAlwaysVisible() { return alwaysDraw; }

protected:
	Context* context;

	bool alwaysDraw;
	bool blockUpdate;
};

