#pragma once

//for logging function
#include "Logger.h"
//for resources IDs
#include "GameDefenitions.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

public:
	//load game resources
	//return true if loading is good
	bool LoadResources();

	//return a reference to the requested texture
	const sf::Texture& getTexture(Textures::Texture) const;

private:
	//load the paths to the textures from the settings file
	bool loadPaths();

private:
	std::map<Textures::Texture, sf::Texture> textures;
	std::map<Textures::Texture, std::string> texturesLocations;
};