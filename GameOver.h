#pragma once
#include<sfml/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameOver
{
public:
	GameOver(float width, float height);
	~GameOver();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getpressItem() { return selectedItem; }

private:
	int selectedItem = 0;
	sf::Font font;
	sf::Text GameOvermenu[3];
	sf::Texture gameover;
	sf::Sprite GAMEOVER;

	sf::SoundBuffer type;
	sf::Sound Type;
};

