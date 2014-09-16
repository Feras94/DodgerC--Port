#pragma once

#include "GameObject.h"

// forward declarations
class Input;

class ControlledObject : public GameObject
{
public:
	ControlledObject(const sf::Texture& texture, int framwWidth, int frameHeight, sf::Time frameTime,
					 const sf::Vector2f position, const sf::Vector2f& speed, const Input& input, sf::Vector2f windowSize);
	virtual ~ControlledObject();

public:

	virtual void update(sf::Time dt);

protected:
	// returns the keyboard input direction
	sf::Vector2f getKeyboardDirection();
	const Input& m_Input;
	sf::Vector2f clientSize;
};

