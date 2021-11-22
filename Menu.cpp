#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("font/font2.ttf")) {

	}

	type.loadFromFile("sound/SingleKey.wav");
	Type.setBuffer(type);
	Type.setVolume(35);

	menu[0].setFont(font);
	menu[0].setCharacterSize(25);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("PLAY");
	menu[0].setOrigin(menu[0].getLocalBounds().width/2,menu[0].getLocalBounds().height/2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / 20 * 9.3));

	menu[1].setFont(font);
	menu[1].setCharacterSize(18);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("HOW TO PLAY");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / 20 * 11.4));

	menu[2].setFont(font);
	menu[2].setCharacterSize(18);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("LEADERBOARD");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / 20 * 12.4));

	menu[3].setFont(font);
	menu[3].setCharacterSize(18);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("EXIT");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 2, menu[3].getLocalBounds().height / 2);
	menu[3].setPosition(sf::Vector2f(width / 2, height / 20 * 13.4));

	//back.setFont(font);
	//back.setCharacterSize(18);
	//back.setFillColor(sf::Color::Black);
	//back.setString("Press B to back");
	//back.setPosition(sf::Vector2f(32*2, height / 20 * 18));

}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItem - 1 >= 0) {
		menu[selectedItem].setFillColor(sf::Color::Black);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		Type.play();
	}
		
}

void Menu::MoveDown()
{
	if (selectedItem + 1 < 4) {
		menu[selectedItem].setFillColor(sf::Color::Black);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		Type.play();
	}

}
