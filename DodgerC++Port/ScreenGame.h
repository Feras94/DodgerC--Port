#pragma once

#include "Screen.h"


// TODO DELETE
class ControlledObject;
class AutomatedObject;
class ChasingObject;
class EvadingObject;

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
	// TODO DELETE
	ControlledObject* player;
	EvadingObject* evading;
	AutomatedObject* automated;
	ChasingObject* chaser;
};

