#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,sf::Vector2f position);
	~Enemy();

	void Update(float deltaTime, int direction,bool gameover);
	void Draw(sf::RenderWindow& window);
	void Move(float dx, float dy) { body.move(dx, dy); }
	int checkcollision(sf::Vector2f,int direction);
	void changespeed(float Speed);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	//bool Collision() { return collision; }
	int Collision() { return collision; }

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	int collision;
};

