#include "PreCompiled.h"

//class header file
#include "ResourceManager.h"

ResourceManager::ResourceManager()
: textures()
, texturesLocations()
{
}

ResourceManager::~ResourceManager()
{
}

bool ResourceManager::LoadResources()
{
	if (!loadPaths())
	{
		LOGERROR("could not load Textures locations");
		return false;
	}

	LOG("Beginning To Load Textures");
	sf::Texture tmpTexture;

	int locationsCount = static_cast<int>(texturesLocations.size());
	int requiredTexturesCount = (int)Textures::Texture::TexturesCount;
	LOG("Stored Locations Count = " + std::to_string(locationsCount));
	LOG("Required Textures Count = " + std::to_string(requiredTexturesCount));

	if (locationsCount != requiredTexturesCount)
	{
		LOGERROR("Texture Locations Variable count does not match the textures count");
		return false;
	}

	for (auto itr = texturesLocations.begin(); itr != texturesLocations.end(); itr++)
	{
		if (!tmpTexture.loadFromFile(itr->second))
		{
			LOGERROR("could not find texture : " + itr->second);
			return false;
		}

		LOG("Loaded Texture : " + itr->second);
		tmpTexture.setRepeated(false);
		tmpTexture.setSmooth(true);

		textures[itr->first] = std::move(tmpTexture);
	}

	return true;
}

bool ResourceManager::loadPaths()
{
	LOG("Beginning to load textures paths");

	try		//try loading the paths file and inserting the paths
	{
		YAML::Node baseNode;
		baseNode = YAML::LoadFile(Constants::ResourcesFilePath);

		//loading good, begin with getting the info
		baseNode = baseNode["Resources"];
		//get the count of the paths
		int pathsCount = baseNode["Count"].as<int>();
		//get the paths Node
		YAML::Node pathsNode = baseNode["Paths"];

		Textures::Texture tex;
		std::string path = "";

		for (int i = 0; i < pathsCount; i++)
		{
			//to check if finding is good
			tex = Textures::Texture::TexturesCount;
			path = "";

			tex = static_cast<Textures::Texture>(pathsNode[i][0].as<int>());
			path = pathsNode[i][1].as<std::string>();

			if (path == "" || tex == Textures::Texture::TexturesCount)
			{
				LOGERROR("could not load Texture #" + std::to_string(i) + " Path or ID");
				return false;
			}

			//path loaded, add it to the paths
			LOG("Path For Texture #" + std::to_string(i) + " : " + path);
			texturesLocations.insert(std::make_pair(tex, path));
		}
	}
	catch (YAML::ParserException& ex)
	{
		LOGERROR(ex.what());
		return false;
	}
	catch (YAML::Exception& ex)
	{
		LOGERROR(ex.what());
		return false;
	}

	return true;
}

const sf::Texture& ResourceManager::getTexture(Textures::Texture texture) const
{
	//check if the requested texture exist in our map
	auto found = textures.find(texture);
	assert(found != textures.end());

	return found->second;
}