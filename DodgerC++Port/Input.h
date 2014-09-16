#pragma once

class Input
{
public:
	Input();
	~Input();

	//initialize the input manager
	void Init(sf::RenderWindow *window);

	//handle window events
	void handleEvent(sf::Event& event);
	
	//update the input manager at the end of the main loop after all game logic
	void update(sf::Time dt);
	// late update ... call at the end of the frame
	void lateUpdate();

public:

	//is the provided key currently being pressed
	bool isKeyDown(sf::Keyboard::Key key) const 
	{
#if __MYDEBUG__
		assert(key >= sf::Keyboard::A && key <= sf::Keyboard::KeyCount);
#endif

		return newKeyState[key]; 
	}

	//was the provided key pressed and released
	bool isKeyPressed(sf::Keyboard::Key key) const
	{ 
#if __MYDEBUG__
		assert(key >= sf::Keyboard::A && key <= sf::Keyboard::KeyCount);
#endif

		return (!oldKeyState[key] && newKeyState[key]); 
	}

	//get the current mouse position relative to the window
	sf::Vector2i MousePos() const 
	{
#if __MYDEBUG__
		assert(_Window != nullptr);
#endif

		return sf::Mouse::getPosition(*_Window);
	}

	sf::Vector2i MouseDeltaPosition() const
	{
		return sf::Mouse::getPosition(*_Window) - oldMousePos;
	}

private:
	sf::RenderWindow* _Window;

	std::vector<bool> oldKeyState;
	std::vector<bool> newKeyState;

	sf::Vector2i oldMousePos;
};