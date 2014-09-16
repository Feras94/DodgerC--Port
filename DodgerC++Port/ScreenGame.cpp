#include "PreCompiled.h"

//class header file
#include "ScreenGame.h"
//for screen manager
#include "ScreenManager.h"
//for resources
#include "ResourceManager.h"
//for application
#include "Application.h"

#include "ControlledObject.h"

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
}

ScreenGame::~ScreenGame()
{
}


void ScreenGame::update(sf::Time dt)
{
	player->update(dt);
}

void ScreenGame::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color::White);
	player->draw(window);
}

void ScreenGame::handleEvents(const sf::Event& event)
{
}