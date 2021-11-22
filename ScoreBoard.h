#include<sfml/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#pragma once

class ScoreBoard
{
public:
	ScoreBoard();

	void draw(sf::RenderWindow& window);
	void scoreRead();
	void scoreAdd(const char* playername, int score);
	void scoreSort();

private:
	FILE* fp;
	struct ScoreData
	{
		char name[20];
		int score;
	}data[6];

	sf::Font font;
	sf::Text UserName[5];
	sf::Text UserScore[5];
};

