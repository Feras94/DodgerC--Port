#include "PreCompiled.h"

//class header file
#include "ScreenSplash.h"
//for game definitions
#include "GameDefenitions.h"
//for screenManager
#include "ScreenManager.h"
//for resources
#include "ResourceManager.h"
//for application
#include "Application.h"
//for in game screen
#include "ScreenGame.h"



ScreenSplash::ScreenSplash(Context* context)
: Screen(context)
{
	splashScreen = sf::Sprite(context->resManager->getTexture(Textures::Texture::SplashScreen));
	centerOrigin(splashScreen);
	centerScreen(splashScreen, context->application->getWindowSize());

	delayTime = sf::seconds(3.f);
	elapsedTime = sf::Time::Zero;

	this->alwaysDraw = true;
	this->blockUpdate = true;
}

ScreenSplash::~ScreenSplash()
{
}

void ScreenSplash::update(sf::Time dt)
{
	elapsedTime += dt;
	if (elapsedTime > delayTime)
	{
		context->screenManager->registerRequest(ScreenManager::Request(ScreenManager::Action::Push, Screens::IDs::InGame));
	}
}

void ScreenSplash::draw(sf::RenderWindow& window)
{
	window.draw(splashScreen);
}

void ScreenSplash::handleEvents(const sf::Event& event)
{
}