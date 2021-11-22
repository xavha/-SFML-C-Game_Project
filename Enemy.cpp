#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 1;

	body.setSize(sf::Vector2f(35.0f, 35.0f));
	body.setPosition(position);
	body.setTexture(texture);

}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime, int direction,bool gameover)
{
	sf::Vector2f movement(0.0f, 0.0f);

	sf::Vector2f pos = body.getPosition();
	bool checkenm;
	checkenm = checkcollision(pos, direction);

	//1=Left 2=Right 3=Up 4=Down

	if (!gameover) {
		if (checkenm == 1) {
			if (direction == 1) {
				movement.x -= speed * deltaTime;
				row = 1;
			}
			else if (direction == 2) {
				movement.x += speed * deltaTime;
				row = 2;
			}
			else if (direction == 3) {
				movement.y -= speed * deltaTime;
				row = 3;
			}
			else if (direction == 4) {
				movement.y += speed * deltaTime;
				row = 0;
			}
		}
		else {
			movement = { 0.f,0.f };
			//direction = rand() % 4 + 1;
		}
		collision = checkenm;

		animation.Update(row, deltaTime, 1);
	}
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Enemy::changespeed(float Speed) {
	speed = Speed;
}

int Enemy::checkcollision(sf::Vector2f pos,int direction) {

	int check[20][20]{
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
	3,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
	};

	sf::Vector2i a, b, c, d;
	a.x = pos.x / 32;				a.y = pos.y / 32;
	b.x = (pos.x + 35.f) / 32;		b.y = a.y;
	c.x = b.x;						c.y = (pos.y + 35.f) / 32;
	d.x = a.x;						d.y = c.y;

	sf::Vector2i i, j;

	if (direction == 1) {
		i.x = a.y;
		i.y = a.x;

		j.x = d.y;
		j.y = d.x;
	}
	else if (direction == 2) {
		i.x = b.y;
		i.y = b.x;

		j.x = c.y;
		j.y = c.x;
	}
	else if (direction == 3) {
		i.x = a.y;
		i.y = a.x;

		j.x = b.y;
		j.y = b.x;
	}
	else if (direction == 4) {
		i.x = c.y;
		i.y = c.x;

		j.x = d.y;
		j.y = d.x;
	}

	if (check[i.x][i.y] == 0 && check[j.x][j.y] == 0 && abs(i.x - j.x) <= 1 && abs(i.y - j.y) <= 1) {
		return 1;
	}
	if (check[i.x][i.y] == 0 || check[j.x][j.y] == 0) {
		if (i.x == j.x) {
			if (i.y - j.y == 2) {
				if (check[i.x][i.y - 1] == 0) {
					return 1;
				}
				else return 0;
			}
			else if (j.y - i.y == 2) {
				if (check[j.x][j.y - 1] == 0) {
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		else if (i.y == j.y) {
			if (i.x - j.x == 2) {
				if (check[i.x - 1][i.y] == 0) {
					return 1;
				}
				else return 0;
			}
			else if (j.x - i.x == 2) {
				if (check[j.x - 1][j.y] == 0) {
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}