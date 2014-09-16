#pragma once

class Animation;

class GameObject
{

public:
	GameObject(const sf::Texture& texture, int frameWidth, int frameHeight, sf::Time frameTime, const sf::Vector2f& position, const sf::Vector2f& speed);
	virtual ~GameObject();

public:	
	
	// get the global bounds of the object
	sf::FloatRect getCollisionRect() { return m_Sprite.getGlobalBounds(); }
	// return true if the object is in the provided rectangle
	bool isOutOfBounds(sf::FloatRect clientRectangle) const;

	// returns the object position
	const sf::Vector2f& getPosition() const { return m_Sprite.getPosition(); }

	// sets the object scale
	void setScale(float x, float y) { m_Sprite.setScale(x, y); }
	// scales the object by the amount provided
	void scale(float multiplyer) { m_Sprite.scale(multiplyer, multiplyer); }

public:
	// update the game object
	virtual void update(sf::Time dt);
	// draw to the renderTarget
	virtual void draw(sf::RenderTarget& renderTarget);

protected:
	// the object speed
	sf::Vector2f m_Speed;
	// the object graphical representation
	sf::Sprite m_Sprite;
	// the object animation
	Animation* m_Animation;
	// the object movement direction
	sf::Vector2f m_Direction;
};

