#pragma once

#include "Screen.h"

class ControlledObject;

class ScreenGame : public Screen
{
public:
	ScreenGame(Context* context);
	~ScreenGame();

public:

	void update(sf::Time dt) override;
	void draw(sf::RenderWindow& window) override;
	void handleEvents(const sf::Event& event) override;

private:
	ControlledObject* player;
};

