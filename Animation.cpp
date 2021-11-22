#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);

}

Animation::~Animation()
{

}

void Animation::Update(int row, float deltatime,bool enmAnimation) {
	// bool faceRight
	currentImage.y = row;
	totalTime += deltatime;

	if (enmAnimation == 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (totalTime >= switchTime) {
				totalTime -= switchTime;
				currentImage.x++;

				if (currentImage.x >= imageCount.x) {
					currentImage.x = 0;
				}
			}
		}
		else currentImage.x = 1;
	}
	else {
		if (totalTime >= switchTime) {
			totalTime -= switchTime;
			currentImage.x++;

			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
			}
		}
	}


	uvRect.top = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.width = abs(uvRect.width);

	/*
	if (faceRight) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
	*/
}
