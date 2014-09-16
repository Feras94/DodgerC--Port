#include "PreCompiled.h"

//class header file
#include "ScreenManager.h"
//for application referencing
#include "Application.h"
//for logging
#include "Logger.h"

#include "ScreenGame.h"
#include "ScreenSplash.h"


ScreenManager::ScreenManager(Application* app)
: activeScreen(Screens::IDs::UNKNOWN)
, screenStack()
, pendingRequests()
{
	context = new Context();
	context->application = app;
	context->screenManager = this;
	context->resManager = app->getResManager();
	context->inputManager = app->getInput();
}

ScreenManager::~ScreenManager()
{
	delete context;
}

void ScreenManager::update(sf::Time dt)
{
	proccesRequests();

	if (screenStack.empty())
	{
		LOG("Screen Stack is Empty, Requesting Exit");
		context->application->RequestExit(0);
		return;
	}

	for (auto itr = screenStack.rbegin(); itr != screenStack.rend(); itr++)
	{
		(*itr)->update(dt);
		if ((*itr)->isBlocking())
			break;
	}

}

void ScreenManager::draw(sf::RenderWindow& window)
{
	for (auto itr = screenStack.begin(); itr != screenStack.end(); itr++)
	{
		if ((*itr)->isAlwaysVisible())
			(*itr)->draw(window);
	}
}

void ScreenManager::handleEvents(const sf::Event& event)
{
	for (auto itr = screenStack.rbegin(); itr != screenStack.rend(); itr++)
	{
		(*itr)->handleEvents(event);
		if ((*itr)->isBlocking())
			break;
	}
}

void ScreenManager::handlePush(Screens::IDs screenID)
{
	switch (screenID)
	{
		case Screens::IDs::UNKNOWN:
			LOG("ERROR, Pushing a default unknown screen");
			context->application->RequestExit(-1);
			break;
		case Screens::IDs::SplashScreen:
			pushScreen<ScreenSplash>(Screens::IDs::SplashScreen);
			break;
		case Screens::IDs::MainMenu:
			break;
		case Screens::IDs::Options:
			break;
		case Screens::IDs::InGame:
			pushScreen<ScreenGame>(Screens::IDs::InGame);
			break;
		case Screens::IDs::Paused:
			break;
		case Screens::IDs::HighScores:
			break;
		case Screens::IDs::ScreensCount:
			break;
		default:
			LOG("Error, pushing an unknown screen to the screen manager");
			context->application->RequestExit(-1);
			break;
	}
}

void ScreenManager::popScreen()
{
	if (!screenStack.empty())
	{
		screenStack.pop_back();
	}
}

void ScreenManager::clearScreens()
{
	if (!screenStack.empty())
	{
		screenStack.clear();
	}
}

void ScreenManager::registerRequest(Request request)
{
	LOG("Received a ScreenManager Request");
	pendingRequests.push_back(request);
}

void ScreenManager::proccesRequests()
{
	if (!pendingRequests.empty())
	{
		for (auto itr = pendingRequests.begin(); itr != pendingRequests.end(); itr++)
		{
			switch (itr->action)
			{
				case Action::Push:
					handlePush(itr->screenID);
					break;

				case Action::Pop:
					popScreen();
					break;

				case Action::Clear:
					clearScreens();
					break;
			}
		}

		pendingRequests.clear();
	}
}