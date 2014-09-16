#include "PreCompiled.h"
#include "AutomatedEnemy.h"


AutomatedObject::AutomatedObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime, const sf::Vector2f& position, const sf::Vector2f& speed)
: GameObject(texture, frameWidth, frameHeight, frameTime, position, speed)
{
}

AutomatedObject::~AutomatedObject()
{
}

void AutomatedObject::update(sf::Time dt)
{
	m_Sprite.move(m_Speed * dt.asSeconds());
	GameObject::update(dt);
}
