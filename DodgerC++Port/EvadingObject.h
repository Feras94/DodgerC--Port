#pragma once

#include "GameObject.h"

class EvadingObject : GameObject
{
public:

	EvadingObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime,
				  const sf::Vector2f& position, const sf::Vector2f& speed, 
				  float evasionModifier, int evasionRange, const GameObject& target);
	virtual ~EvadingObject();

	virtual void update(sf::Time dt);

protected:

	const GameObject& target;

	float evasionModifier;
	int evasionRange;
	int evasionRangeSquared;
	bool evade;
};

