#include "PreCompiled.h"
#include "GameObject.h"

#include "Animation.h"
#include "GameDefenitions.h"

GameObject::GameObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime, 
					   const sf::Vector2f& position, const sf::Vector2f& speed)
: m_Sprite(texture)
, m_Speed(speed)
{
	//m_Sprite.setOrigin(frameWidth / 2, frameHeight / 2);
	m_Sprite.setPosition(position);

	m_Animation = new Animation(frameWidth, frameHeight, frameTime, m_Sprite, texture);
	m_Animation->play(true);
}


GameObject::~GameObject()
{
	delete m_Animation;
}

void GameObject::update(sf::Time dt)
{
	m_Animation->update(dt);
}

void GameObject::draw(sf::RenderTarget& renderTarget)
{
	renderTarget.draw(m_Sprite);
}

bool GameObject::isOutOfBounds(sf::FloatRect clientRectangle) const
{
	return m_Sprite.getGlobalBounds().intersects(clientRectangle);
}
