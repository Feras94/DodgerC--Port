#include "PreCompiled.h"

//class header file
#include "Input.h"
//for logging function
#include "Logger.h"


Input::Input()
: oldKeyState(sf::Keyboard::KeyCount, false)
, newKeyState(sf::Keyboard::KeyCount, false)
{
	_Window = nullptr;
}

Input::~Input()
{
}

void Input::Init(sf::RenderWindow* window)
{
	LOG("Initializing the input manager");
	this->_Window = window;
}

void Input::handleEvent(sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
		newKeyState[event.key.code] = true;
	else if (event.type == sf::Event::KeyReleased)
		newKeyState[event.key.code] = false;
}

void Input::update(sf::Time dt)
{
	oldMousePos = sf::Mouse::getPosition(*_Window);
}

void Input::lateUpdate()
{
	oldKeyState = newKeyState;
}
