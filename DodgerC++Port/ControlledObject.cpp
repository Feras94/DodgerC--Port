#include "PreCompiled.h"
#include "ControlledObject.h"

#include "Animation.h"
#include "Input.h"

ControlledObject::ControlledObject(const sf::Texture& texture, int framwWidth, int frameHeight, sf::Time frameTime,
								   const sf::Vector2f position, const sf::Vector2f& speed,
								   const Input& input, sf::Vector2f windowSize)
: GameObject(texture, framwWidth, frameHeight, frameTime, position, speed)
, m_Input(input)
, clientSize(windowSize)
{
}


ControlledObject::~ControlledObject()
{
}

void ControlledObject::update(sf::Time dt)
{
	sf::Vector2f movmentDirection(0.0f, 0.0f);
	movmentDirection.x = getKeyboardDirection().x * m_Speed.x;
	movmentDirection.y = getKeyboardDirection().y * m_Speed.y;
	m_Sprite.move(movmentDirection * dt.asSeconds());

	
	if (m_Input.MouseDeltaPosition().x != 0 ||
		m_Input.MouseDeltaPosition().y != 0)
	{
		m_Sprite.setPosition(sf::Vector2f((float)m_Input.MousePos().x, (float)m_Input.MousePos().y));
	}

	if (getPosition().x < 0.0f)
		m_Sprite.setPosition(0.0f, getPosition().y);
	if (getPosition().y < 0)
		m_Sprite.setPosition(getPosition().x, 0.0f);
	if (getPosition().x >(clientSize.x - (m_Animation->getFrameWidth())))
		m_Sprite.setPosition(clientSize.x - m_Animation->getFrameWidth(), getPosition().y);
	if (getPosition().y >(clientSize.y - m_Animation->getFrameHeight()))
		m_Sprite.setPosition(getPosition().x, clientSize.y - m_Animation->getFrameHeight());

	GameObject::update(dt);
}

sf::Vector2f ControlledObject::getKeyboardDirection()
{
	sf::Vector2f inputDirection(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		inputDirection.x -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		inputDirection.x += 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		inputDirection.y -= 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		inputDirection.y += 1;

	return inputDirection;
}
