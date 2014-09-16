#pragma once

#include "GameObject.h"

class AutomatedObject : public GameObject
{
public:

	AutomatedObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime, const sf::Vector2f& position, const sf::Vector2f& speed);
	virtual ~AutomatedObject();

public:

	virtual void update(sf::Time dt) override;
};

