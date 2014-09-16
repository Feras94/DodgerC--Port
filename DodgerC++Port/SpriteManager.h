#pragma once

class GameObject;

class SpriteManager
{
public:
	
	SpriteManager(const GameObject& player);
	virtual ~SpriteManager();

public:

	void update(sf::Time dt);
	void draw(sf::RenderTarget& target);

private:

	void resetSpawnTime();
	void adjustSpawnTime();
	void spawnEnemy();
	void updateObjects();


private:
	// the player
	const GameObject& player;
	int livesRemaining;
	// out objects list
	std::list<GameObject> objectsList;

	int enemyMinSpawnTime;
	int enemyMaxSpawnTime;
	int enemyNextSpwanTime;

	int enemyMinSpeed;
	int enemyMaxSpeed;

	int automatedChance;
	int chasingChance;
	int evadingChance;

	int automatedScore;
	int chasingScore;
	int evadingScore;

	int nextSpwanTimeChange;
	int timeSinceLastSpawnChange;

	std::vector<GameObject> livesLeft;
};

