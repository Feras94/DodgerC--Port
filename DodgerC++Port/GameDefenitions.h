#ifndef _GAMEDEFS_
#define _GAMEDEFS_

//forward declarations
namespace sf
{
	class Sprite;
}

namespace YAML
{
	class Node;
}

class ScreenManager;
class Application;
class ResourceManager;
class Input;


namespace Textures
{
	//Textures IDs
	enum class Texture
	{
		PlayerSheet,
		PowerUp,
		EnemyBlades,
		EnemyDisk,
		EnemyPlus,
		EnemySkull,
		SplashScreen,
		TexturesCount,
	};
}

namespace Settings
{
	struct GameSettings
	{
		int screenWidth;
		int screenHeight;
		std::string windowTitle;
		bool isFullScreen;
		int fps;
	};
}

namespace Screens
{
	enum class IDs
	{
		UNKNOWN = -1,
		SplashScreen,
		MainMenu,
		Options,
		InGame,
		Paused,
		HighScores,
		ScreensCount,	//keep at bottom
	};
}

namespace Constants
{
	const std::string SettingsFilePath  = "Data/Settings/settings.yaml";
	const std::string ResourcesFilePath = "Data/Settings/Resources.yaml";
}

//context struct for giving to the screens
struct Context
{
	ScreenManager* screenManager;
	Application* application;
	ResourceManager* resManager;
	Input* inputManager;
};


//operator For settings
void operator >> (const YAML::Node& node, Settings::GameSettings& settings);

void centerOrigin(sf::Sprite& sprite);
void centerScreen(sf::Sprite& sprite, sf::Vector2u screenSize);


#endif		//_GAMEDEFS_