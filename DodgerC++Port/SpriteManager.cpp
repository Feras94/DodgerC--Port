#include "PreCompiled.h"
#include "SpriteManager.h"

#include "GameObject.h"

SpriteManager::SpriteManager(const GameObject& player)
: player(player)
{
	this->enemyMinSpawnTime = 1000;
	this->enemyMaxSpawnTime = 2000;

	this->enemyMinSpeed = 3;
	this->enemyMaxSpeed = 8;

	this->enemyNextSpwanTime = 0;

	this->automatedChance = 65;
	this->chasingChance = 30;
	this->evadingChance = 5;

	this->automatedScore = 100;
	this->chasingScore = 250;
	this->evadingScore = 500;

	this->nextSpwanTimeChange = 5000;
	this->timeSinceLastSpawnChange = 0;

	resetSpawnTime();
}

SpriteManager::~SpriteManager()
{

}

void SpriteManager::update(sf::Time dt)
{

}

void SpriteManager::draw(sf::RenderTarget& target)
{

}

void SpriteManager::resetSpawnTime()
{
	enemyNextSpwanTime = thor::random(
		enemyMinSpawnTime,
		enemyMaxSpawnTime);
}

void SpriteManager::adjustSpawnTime()
{

}

void SpriteManager::spawnEnemy()
{

}

void SpriteManager::updateObjects()
{

}
