#pragma once

#include "GameObject.h"

class ChasingObject :	public GameObject
{
public:
	ChasingObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime,
				  const sf::Vector2f& position, const sf::Vector2f& speed,
				  const GameObject& target);

	virtual ~ChasingObject();

public:

	virtual void update(sf::Time dt);

protected:
	
	const GameObject& target;
};

