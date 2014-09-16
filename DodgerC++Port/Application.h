#pragma once

//forward declarations
namespace Settings
{
	struct GameSettings;
}

class Input;
class ResourceManager;
class ScreenManager;

class Application
{

public:
	static Application* pInstance;

public:
	Application();
	~Application();

	//run the game and return the exitCode upon completion
	int Run();

	//set the fps for the application
	void setTargetFPS(int newFPS);

	//request an exit after cleaning after the systems
	void RequestExit(int exitCode);

public:
	//get a const reference to the input manager
	Input* getInput() { return input; }

	//get a const reference to the resource manager
	ResourceManager* getResManager() { return resManager; }

	//returns the window size
	const sf::Vector2u& getWindowSize() { return _Window.getSize(); }
	// returns the active window
	const sf::RenderWindow& getWindow() { return _Window; }

private:
	//initialize the game systems
	//returns true if initialization was good
	bool initSystems();

	// saves the options
	bool loadOptions(Settings::GameSettings& settings);

	//handle window events
	void handleEvents();

	//update the game world
	void update(sf::Time dt);
	//draw the game world to the rendering window
	void draw();

private:
	Input* input;
	ResourceManager* resManager;

	ScreenManager* screenManager;
	
private:
	sf::RenderWindow _Window;
	bool _running;
	int exitCode;
	sf::Time _nFrameTime;

	YAML::Node settingsNode;
};