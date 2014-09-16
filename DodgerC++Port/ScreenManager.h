#pragma once

//for game definitions
#include "GameDefenitions.h"
//for screen
#include "Screen.h"

// forward declarations
class ScreenSplash;
class ScreenGame;

class ScreenManager : private sf::NonCopyable
{
public:
	enum class Action
	{
		Push,
		Pop,
		Clear,
	};

	struct Request
	{
		explicit Request(Action action, Screens::IDs ID = Screens::IDs::UNKNOWN)
		: action(action)
		, screenID(ID)
		{
		}

		Action action;
		Screens::IDs screenID;
	};

public:
	ScreenManager(Application* app);
	~ScreenManager();

public:

	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);
	void handleEvents(const sf::Event& event);

	bool isEmpty() { return screenStack.empty(); }

public:

	//register a request
	void registerRequest(Request request);



private:

	// apply pending requests
	void proccesRequests();
	// push the provided screen to the screen stack
	template<typename T>
	void pushScreen(Screens::IDs screenID)
	{
		if (activeScreen == screenID)
		{
			LOG("ERROR, cant push matching screens to the screenStack");
			context->application->RequestExit(-1);
		}
		else
		{
			Screen::Ptr p(new T(context));
			screenStack.push_back(std::move(p));
			activeScreen = screenID;
		}
	}
	// handle push operations
	void handlePush(Screens::IDs screenID);
	// pop the top screen from the stack
	void popScreen();
	// clear the screen stack
	void clearScreens();

private:
	std::vector<Screen::Ptr> screenStack;
	Screens::IDs activeScreen;

	std::vector<Request> pendingRequests;

	Context* context;
};

