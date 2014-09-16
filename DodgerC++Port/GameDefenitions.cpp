#include "PreCompiled.h"

//game definitions
#include "GameDefenitions.h"

void centerOrigin(sf::Sprite& sprite)
{
	sf::Vector2f origin = sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setOrigin(origin);
}

void centerScreen(sf::Sprite& sprite, sf::Vector2u screenSize)
{
	sprite.setPosition((float)screenSize.x / 2.f, (float)screenSize.y / 2.f);
}

void operator >> (const YAML::Node& node, Settings::GameSettings& settings)
{
	settings.screenWidth = node["screenWidth"].as<int>();
	settings.screenHeight = node["screenHeight"].as<int>();
	settings.windowTitle = node["windowTitle"].as<std::string>();
	settings.isFullScreen = node["isFullScreen"].as<bool>();
	settings.fps = node["FPS"].as<int>();
}