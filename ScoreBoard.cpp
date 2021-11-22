#define _CRT_SECURE_NO_WARNINGS
#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() {
	if (!font.loadFromFile("font/font2.ttf")) {

	}

	for (int i = 0; i < 5; i++) {
		UserName[i].setFont(font);
		UserName[i].setCharacterSize(20);
		UserName[i].setFillColor(sf::Color::Black);
		UserName[i].setString(data[i].name);
		UserName[i].setPosition(sf::Vector2f(130, 32 * (7 + i)));

		UserScore[i].setFont(font);
		UserScore[i].setCharacterSize(20);
		UserScore[i].setFillColor(sf::Color::Black);
		UserScore[i].setString(to_string(data[i].score));
		UserScore[i].setPosition(sf::Vector2f(450, 32 * (7 + i)));
	}
}

void ScoreBoard::scoreRead()
{
	FILE* fp = NULL;
	int err = fopen_s(&fp, "files/Score.txt", "r");
	if (err)
	{
		fopen_s(&fp, "files/Score.txt", "w");
		return;
	}
	for (int i = 0; i < 5 && !feof(fp) && fp != NULL; i++)
	{
		fscanf_s(fp, "%[^,],", data[i].name, _countof(data[i].name));
		fscanf_s(fp, "%d\n", &data[i].score);
		UserName[i].setString(data[i].name);
		UserScore[i].setString(to_string(data[i].score));
		//std::cout << data[i].name << "   " << data[i].score << std::endl;
	}
	fclose(fp);
}

void ScoreBoard::scoreAdd(const char* playername, int score)
{
	FILE* fp = NULL;
	fopen_s(&fp, "files/Score.txt", "w");
	strcpy_s(data[5].name, 19, playername);
	data[5].score = score;
	scoreSort();
	for (int i = 0; i < 5 && fp != NULL; i++)
	{
		fprintf_s(fp, "%s,%d\n", data[i].name, data[i].score);
	}
	fclose(fp);
}

void ScoreBoard::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++) {
		window.draw(UserName[i]);
		window.draw(UserScore[i]);

		//std::cout << data[i].name << "   " << data[i].score << std::endl;
	}
}

void ScoreBoard::scoreSort()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (data[j].score > data[i].score)
			{
				ScoreData temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}
}