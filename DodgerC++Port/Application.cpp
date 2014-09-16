#include "PreCompiled.h"

//for logging
#include "Logger.h"
//for input
#include "Input.h"
//for resources
#include "ResourceManager.h"
//for screen manager
#include "ScreenManager.h"
//for MISC
#include "GameDefenitions.h"
//class header file
#include "Application.h"



Application* Application::pInstance = nullptr;

Application::Application()
: _Window()
, _running(false)
, exitCode(0)
{
	input = new Input();
	resManager = new ResourceManager();
	screenManager = new ScreenManager(this);

	pInstance = this;
}

Application::~Application()
{
	LOG("Cleaning up The Application Class Before exiting");
	delete screenManager;
	delete resManager;
	delete input;
}


int Application::Run()
{
	//if initialization was good we will run the game, if not we clean up and exit
	_running = initSystems();

	screenManager->registerRequest(ScreenManager::Request(ScreenManager::Action::Push, Screens::IDs::SplashScreen));

	//time keeping variables
	sf::Time timeSinceUpdate = sf::Time::Zero;
	sf::Clock _clock;

	//main game loop
	while (_running)
	{
		sf::Time dt = _clock.restart();
		timeSinceUpdate += dt;

		//fps limiting
		while (timeSinceUpdate > _nFrameTime)
		{
			timeSinceUpdate -= _nFrameTime;

			handleEvents();
			//update the game world
			update(_nFrameTime);
			input->update(dt);
		}

		//draw the game world
		draw();

		//update the input manager at the end of the main loop
		input->lateUpdate();
	}

	//we finished the game loop, exit and return the exit code
	return exitCode;
}

#pragma region Update And Draw

void Application::update(sf::Time dt)
{
	screenManager->update(dt);
}

void Application::draw()
{
	_Window.clear(sf::Color::White);

	screenManager->draw(_Window);

	_Window.display();
}

#pragma endregion


/*********************************************************/
/*														 */
/*					HELPER FUNCTIONS					 */
/*														 */
/*********************************************************/

void Application::handleEvents()
{
	sf::Event event;
	while (_Window.pollEvent(event))
	{
		//forward the event to the input manager
		input->handleEvent(event);
		//forward the event to the screenManager
		screenManager->handleEvents(event);

		switch (event.type)
		{
			case sf::Event::Closed:
				RequestExit(0);
				break;

			case sf::Event::KeyPressed:
				if ((event.key.code == sf::Keyboard::F4)
					&& (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)))
					RequestExit(0);
				break;
		}
	}
}

bool Application::initSystems()
{
	LOG("Initializing systems");

	//declare game options and fill it from a file
	Settings::GameSettings settings;
	if (!loadOptions(settings))		//check if load is good
	{
		LOG("ERROR, error while loading game options from the file");
		exitCode = -1;
		return false;
	}

	LOG("Opening the window");
	//create the window
	if (settings.isFullScreen)
		_Window.create(sf::VideoMode(settings.screenWidth, settings.screenHeight), settings.windowTitle, sf::Style::Fullscreen);
	else
		_Window.create(sf::VideoMode(settings.screenWidth, settings.screenHeight), settings.windowTitle, sf::Style::Close | sf::Style::Titlebar);

	//check if window creation is good
	if (!_Window.isOpen())
	{
		LOG("ERROR, Could not create the window");
		exitCode = -1;
		return false;
	}

	//set the frame time
	_nFrameTime = sf::seconds(1.f / settings.fps);

	//initialize the input manager
	input->Init(&_Window);
	
	//load resources
	if (!resManager->LoadResources())
	{
		LOG("ERROR, error during loading resources");
		exitCode = -1;
		return false;
	}

	return true;	//if we reached this far then everything is ok and we can run the game
}

bool Application::loadOptions(Settings::GameSettings& settings)
{
	YAML::Node baseNode;
	try
	{
		baseNode = YAML::LoadFile(Constants::SettingsFilePath);
	}
	catch (YAML::ParserException& ex)
	{
		LOG(ex.what());
		return false;
	}

	if (baseNode.IsNull())
	{
		LOG("ERROR, could not open settings file");
		return false;
	}

	settingsNode = baseNode["Settings"];
	//a simple way to check for errors
	settings.fps = -1;
	settingsNode >> settings;

	if (settings.fps == -1)
	{
		LOG("ERROR, could not fill the settings struct");
		return false;
	}

	return true;
}

void Application::RequestExit(int exitCode)
{
	LOG("Received Exit Request with exit code : " + std::to_string(exitCode));

	_running = false;
	this->exitCode = exitCode;
}

void Application::setTargetFPS(int newFPS)
{
	_nFrameTime = sf::seconds(1.f / newFPS);
}