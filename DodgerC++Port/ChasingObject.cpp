#include "PreCompiled.h"
#include "ChasingObject.h"


ChasingObject::ChasingObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime, const sf::Vector2f& position, const sf::Vector2f& speed, const GameObject& target)
: GameObject(texture, frameWidth, frameHeight, frameTime, position, speed)
, target(target)
{
}

ChasingObject::~ChasingObject()
{
}

void ChasingObject::update(sf::Time dt)
{
	m_Sprite.move(m_Speed * dt.asSeconds());

	const sf::Vector2f& targetPos = target.getPosition();

	if (m_Speed.x == 0)
	{
		if (targetPos.x < getPosition().x)
		{
			m_Sprite.move(-std::abs(m_Speed.y) * dt.asSeconds(), 0.0f);
		}
		else if (targetPos.x > getPosition().x)
		{
			m_Sprite.move(std::abs(m_Speed.y) * dt.asSeconds(), 0.0f);
		}
	}

	if (m_Speed.y == 0)
	{
		if (targetPos.y < getPosition().y)
		{
			m_Sprite.move(0.0f, -std::abs(m_Speed.x) * dt.asSeconds());
		}
		else if (targetPos.y > getPosition().y)
		{
			m_Sprite.move(0.0f, std::abs(m_Speed.x) * dt.asSeconds());
		}
	}

	GameObject::update(dt);
}
