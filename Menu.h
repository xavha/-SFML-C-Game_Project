#pragma once
#include<sfml/Graphics.hpp>
#include<SFML/Audio.hpp>

class Menu
{
public:
	Menu(float width,float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getpressItem() { return selectedItem; }

private:
	int selectedItem = 0;
	sf::Font font;
	sf::Text menu[4]; //0 play game 1 how to play 2 leaderboard 3 exit
	sf::Text back;
	sf::SoundBuffer type;
	sf::Sound Type;
};