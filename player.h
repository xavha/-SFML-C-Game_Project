#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture *texture, sf::Vector2u imageCount,float switchTime,float speed);
	~Player();

	void Update(float deltaTime,bool check,bool gameover);
	void Draw(sf::RenderWindow& window);
	void Move(float dx, float dy) { body.move(dx, dy); }
	void SetPosition(sf::Vector2f pos);
	void changespeed(float Speed);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	//Collider playerCollider = player.GetCollider();
	//Collider GetCollider() { return Collider(body); }

private :
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;

};

