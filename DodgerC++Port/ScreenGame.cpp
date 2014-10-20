#include "PreCompiled.h"

//class header file
#include "ScreenGame.h"
//for screen manager
#include "ScreenManager.h"
//for resources
#include "ResourceManager.h"
//for application
#include "Application.h"


// TODO DELETE
#include "ControlledObject.h"
#include "AutomatedEnemy.h"
#include "ChasingObject.h"
#include "EvadingObject.h"

ScreenGame::ScreenGame(Context* context)
: Screen(context)
{
	this->alwaysDraw = true;
	this->blockUpdate = true;

	sf::Vector2f windowSize = sf::Vector2f(
		(float)context->application->getWindowSize().x,
		(float)context->application->getWindowSize().y);

	player = new ControlledObject(
		context->resManager->getTexture(Textures::Texture::PlayerSheet), 75, 75, sf::seconds(0.025f),
		sf::Vector2f(0, 0), sf::Vector2f(150.0f, 150.0f), *(context->inputManager), windowSize);

	evading = new EvadingObject(context->resManager->getTexture(Textures::Texture::EnemyPlus), 75, 75,
								sf::seconds(0.025f), sf::Vector2f(100.0f, 100.0f), 
								sf::Vector2f(50.0f, 50.0f), 1.5f, 100, *player);
	automated = new AutomatedObject(context->resManager->getTexture(Textures::Texture::EnemySkull), 75, 75,
									sf::seconds(0.025f), sf::Vector2f(200.0f, 200.0f), sf::Vector2f(150.0f, 150.0f));
	chaser = new ChasingObject(context->resManager->getTexture(Textures::Texture::PowerUp), 75, 75,
							   sf::seconds(0.025f), sf::Vector2f(0.0f, 0.0f), sf::Vector2f(150.0f, 150.0f),
							   *player);

}

ScreenGame::~ScreenGame()
{
	delete player;
	delete chaser;
	delete automated;
	delete evading;
}


void ScreenGame::update(sf::Time dt)
{
	player->update(dt);
	evading->update(dt);
	automated->update(dt);
	chaser->update(dt);
}

void ScreenGame::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	player->draw(window);
	evading->draw(window);
	automated->draw(window);
	chaser->draw(window);
}

void ScreenGame::handleEvents(const sf::Event& event)
{
}