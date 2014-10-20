#include "PreCompiled.h"
#include "EvadingObject.h"


EvadingObject::EvadingObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime,
							 const sf::Vector2f& position, const sf::Vector2f& speed,
							 float evasionModifier, int evasionRange, const GameObject& target)
: GameObject(texture, frameWidth, frameHeight, frameTime, position, speed)
, evasionModifier(evasionModifier)
, evasionRange(evasionRange)
, evasionRangeSquared(evasionRange * evasionRange)
, evade(false)
, target(target)
{
}


EvadingObject::~EvadingObject()
{
}

void EvadingObject::update(sf::Time dt)
{
	m_Sprite.move(m_Speed * dt.asSeconds());

	const sf::Vector2f playerPos = target.getPosition();
	if (evade)
	{
		// horizontal evade
		if (playerPos.x < getPosition().x)
			m_Sprite.move(std::abs(m_Speed.y) * dt.asSeconds(), 0.0f);
		else if (playerPos.x > getPosition().x)
			m_Sprite.move(-std::abs(m_Speed.y) * dt.asSeconds(), 0.0f);

		// vertical evade
		if (playerPos.y < getPosition().y)
			m_Sprite.move(0.0f, std::abs(m_Speed.x) * dt.asSeconds());
		else if (playerPos.y > getPosition().x)
			m_Sprite.move(0.0f, -std::abs(m_Speed.x) * dt.asSeconds());
	}
	else
	{
		sf::Vector2f distanceVec = getPosition() - target.getPosition();
		float distanceSquared = thor::squaredLength(distanceVec);
		if (distanceSquared < evasionRangeSquared)
		{
			m_Speed *= -evasionModifier;
			evade = true;
		}
	}

	GameObject::update(dt);
}
