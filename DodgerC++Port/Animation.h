#pragma once

class Animation
{
public:
	Animation(int frameWidth, int frameHeight, sf::Time frameTime, sf::Sprite& sprite, const sf::Texture& texture);
	~Animation();

private:

	// the frame width
	int nFrameWidth;
	// the frame height
	int nFrameHeight;
	// the current frame index
	int nCurrentFrame;

	// number of frames per row
	int nFramesPerRow;
	// total number of frames
	int nFramesTotal;

	// the sprite to animate
	sf::Sprite& sprite;

	// the frameTime
	sf::Time frameTime;
	// current frame time
	sf::Time currentFrameTime;

	// is the animation paused
	bool bIsPaused;
	// does the animation loop
	bool bLoop;

private:

	// update the sprite source rectangle based on the current frame index
	void updateSourceRect();

public:
	
	// update the animation
	void update(sf::Time dt);

	// play the animation
	void play(bool loop);
	// pause the animation
	void pause();
	// stop the animation and reset it
	void stop();

	//Helper methods
public:

	// is the animation playing
	bool isPlaying() { return !bIsPaused; }

	float getFrameWidth() { return nFrameWidth; }
	float getFrameHeight() { return nFrameHeight; }
};

