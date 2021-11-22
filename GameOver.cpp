#include "GameOver.h"

GameOver::GameOver(float width, float height)
{
	if (!font.loadFromFile("font/font2.ttf")) {

	}

	type.loadFromFile("sound/SingleKey.wav");
	Type.setBuffer(type);
	Type.setVolume(35);

	GameOvermenu[0].setFont(font);
	GameOvermenu[0].setCharacterSize(25);
	GameOvermenu[0].setFillColor(sf::Color::Cyan);
	GameOvermenu[0].setString("LEADERBOARD");
	GameOvermenu[0].setOrigin(GameOvermenu[0].getLocalBounds().width / 2, GameOvermenu[0].getLocalBounds().height / 2);
	GameOvermenu[0].setPosition(sf::Vector2f(width / 2, height / 20 * 11.5));

	GameOvermenu[1].setFont(font);
	GameOvermenu[1].setCharacterSize(25);
	GameOvermenu[1].setFillColor(sf::Color::Black);
	GameOvermenu[1].setString("EXIT");
	GameOvermenu[1].setOrigin(GameOvermenu[1].getLocalBounds().width / 2, GameOvermenu[1].getLocalBounds().height / 2);
	GameOvermenu[1].setPosition(sf::Vector2f(width / 2, height / 20 * 13.5));

	gameover.loadFromFile("images/gameOver2.png");
	GAMEOVER.setTexture(gameover);
	GAMEOVER.setOrigin(GAMEOVER.getLocalBounds().width / 2, GAMEOVER.getLocalBounds().height / 2);
	GAMEOVER.setPosition(sf::Vector2f(width / 2, height / 20 * 8));
}

GameOver::~GameOver()
{
}

void GameOver::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++) {
		window.draw(GameOvermenu[i]);
	}
	window.draw(GAMEOVER);
}

void GameOver::MoveUp()
{
	if (selectedItem - 1 >= 0) {
		GameOvermenu[selectedItem].setFillColor(sf::Color::Black);
		selectedItem--;
		GameOvermenu[selectedItem].setFillColor(sf::Color::Cyan);
		Type.play();
	}

}

void GameOver::MoveDown()
{
	if (selectedItem + 1 < 2) {
		GameOvermenu[selectedItem].setFillColor(sf::Color::Black);
		selectedItem++;
		GameOvermenu[selectedItem].setFillColor(sf::Color::Cyan);
		Type.play();
	}

}