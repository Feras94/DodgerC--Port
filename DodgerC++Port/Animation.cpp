#include "PreCompiled.h"
#include "Animation.h"


Animation::Animation(int frameWidth, int frameHeight, sf::Time frameTime, sf::Sprite& sprite, const sf::Texture& spriteSheet)
: sprite(sprite)
{
	this->nFrameWidth = frameWidth;
	this->nFrameHeight = frameHeight;

	this->frameTime = frameTime;
	this->currentFrameTime = sf::Time::Zero;
	this->nCurrentFrame = 0;

	this->nFramesPerRow = spriteSheet.getSize().x / nFrameWidth;
	this->nFramesTotal =
		spriteSheet.getSize().y / nFrameHeight *
		spriteSheet.getSize().x / nFrameWidth - 1;

	this->bIsPaused = false;
	this->bLoop = false;

	updateSourceRect();
}


Animation::~Animation()
{
}

void Animation::update(sf::Time dt)
{
	if (bIsPaused)
		return;

	currentFrameTime += dt;
	if (currentFrameTime > frameTime)
	{
		while (currentFrameTime > frameTime)
		{
			currentFrameTime -= frameTime;
			if (bLoop)
			{
				nCurrentFrame = ++nCurrentFrame % nFramesTotal;
			}
			else
			{
				nCurrentFrame++;
				if (nCurrentFrame >= nFramesTotal)
				{
					nCurrentFrame = nFramesTotal;
					bIsPaused = true;
					break;
				}
			}
		}
		updateSourceRect();
	}
}

void Animation::updateSourceRect()
{
	sf::IntRect rect(
		(nCurrentFrame % nFramesPerRow) * nFrameWidth,
		(nCurrentFrame / nFramesPerRow) * nFrameHeight,
		nFrameWidth,
		nFrameHeight);

	sprite.setTextureRect(rect);
}

void Animation::play(bool loop)
{
	bIsPaused = false;
	bLoop = loop;

	currentFrameTime = sf::Time::Zero;
}

void Animation::pause()
{
	bIsPaused = true;
}

void Animation::stop()
{
	nCurrentFrame = 0;
	bIsPaused = true;
}
