#include "player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture,imageCount,switchTime)
{
	this->speed = speed;
	row = 1;

	body.setSize(sf::Vector2f(48.0f, 48.0f));
	body.setPosition(640-32-48,640-32-48);
	body.setTexture(texture);

}

Player::~Player()
{
}

void Player::Update(float deltaTime,bool check,bool gameover)
{
	sf::Vector2f movement(0.0f, 0.0f);

	sf::Vector2f pos = body.getPosition();

	if (!gameover) {
		if (check == 1) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				movement.x -= speed * deltaTime;
				row = 1;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				movement.x += speed * deltaTime;
				row = 2;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				movement.y -= speed * deltaTime;
				row = 3;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				movement.y += speed * deltaTime;
				row = 0;
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				row = 1;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				row = 2;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				row = 3;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				row = 0;
			}
		}
		animation.Update(row, deltaTime, 0);
	}

	//animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::changespeed(float Speed) {
	speed = Speed;
}

void Player::SetPosition(sf::Vector2f pos)
{
	body.setPosition(pos.x,pos.y);
}
