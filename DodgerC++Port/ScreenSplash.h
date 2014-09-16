#pragma once

#include "Screen.h"


class ScreenSplash : public Screen
{
public:

	ScreenSplash(Context* context);
	~ScreenSplash();

public:

	void update(sf::Time dt) override;
	void draw(sf::RenderWindow& window) override;
	void handleEvents(const sf::Event& event) override;

private:

	sf::Sprite splashScreen;
	sf::Time elapsedTime;
	sf::Time delayTime;
};