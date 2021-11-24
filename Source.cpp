#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<windows.h>
#include "Animation.h"
#include "player.h"
#include "Tilemap.h"
#include "Enemy.h"
#include "Menu.h"
#include "GameOver.h"
#include "TextBox.h"
#include "ScoreBoard.h"

#include <sstream>
//#include "Platform.h"

const int level1[] =
{
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,2,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,2,0,0,2,0,0,0,0,0,0,2,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,2,2,2,2,0,0,0,0,2,2,2,2,2,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
};

const int level2[] =
{
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,2,0,0,0,0,0,2,2,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,2,2,0,0,0,0,0,2,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,2,2,2,2,0,0,2,2,2,2,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
};

const int level3[] = {
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,2,2,2,0,0,0,0,0,0,0,0,2,2,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,2,2,2,2,0,0,0,0,2,0,0,3,
3,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,3,
3,0,0,2,0,0,2,2,0,0,0,0,2,2,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,2,2,0,0,0,0,2,2,0,0,2,0,0,3,
3,0,0,0,0,0,2,2,0,0,0,0,2,2,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,3,
3,0,0,2,0,0,0,0,2,2,2,2,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,2,2,0,0,0,0,0,0,0,0,2,2,2,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

const int level4[] = {
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,3,
3,0,0,2,2,2,0,0,0,2,2,0,0,0,2,2,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,2,2,0,0,0,2,2,0,0,0,0,0,3,
3,0,0,2,0,0,0,2,2,0,0,0,2,2,0,0,2,0,0,3,
3,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,3,
3,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,3,
3,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,3,
3,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,3,
3,0,0,2,0,0,0,2,2,0,0,0,2,2,0,0,2,0,0,3,
3,0,0,0,0,0,0,2,2,0,0,0,2,2,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,2,2,0,0,0,2,2,0,0,0,2,2,2,0,0,3,
3,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,3,
3,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

const int level5[] = {
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,0,0,0,2,0,0,2,2,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,2,2,2,0,0,2,0,0,0,0,0,0,2,0,0,2,2,2,3,
3,2,2,2,0,0,2,0,0,0,0,0,0,2,0,0,2,2,2,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,2,2,0,0,2,0,0,0,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,3,
3,0,0,2,0,0,2,0,0,2,2,0,0,2,0,0,2,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

int check[20][20];
void makeArrayCheck(int level) {
	int k = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			switch (level) {
			case 1: {
				check[i][j] = level1[k];
				break;
			}
			case 2: {
				check[i][j] = level2[k];
				break;
			}
			case 3: {
				check[i][j] = level3[k];
				break;
			}
			case 4: {
				check[i][j] = level4[k];
				break;
			}
			case 5: {
				check[i][j] = level5[k];
				break;
			}
			}
			k++;
		}
	}
}

int checkcollision(sf::Vector2i a, sf::Vector2i b) {
	if (check[a.x][a.y] == 0 && check[b.x][b.y] == 0 && abs(a.x-b.x)<=1 && abs(a.y-b.y)<=1) {
		return 1;
	}
	if (check[a.x][a.y] == 0 || check[b.x][b.y] == 0) {
		if (a.x == b.x) {
			if (a.y - b.y == 2) {
				if (check[a.x][a.y - 1] == 0) {
					return 1;
				}
				else return 0;
			}
			else if (b.y - a.y == 2) {
				if (check[b.x][b.y - 1] == 0) {
					return 1;
				}
				else return 0;
			}
			else return 0;
		}
		else if (a.y == b.y) {
			if (a.x - b.x == 2) {
				if (check[a.x - 1][a.y] == 0) {
					return 1;
				}
				else return 0;
			}
			else if (b.x - a.x == 2) {
				if (check[b.x - 1][b.y] == 0) {
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

int enmVSplayer(sf::Vector2f enmpos1,sf::Vector2f enmpos2,sf::Vector2f enmpos3,sf::Vector2f enmpos4,sf::Vector2f pos) {
	if (abs((pos.x + 24.f) - (enmpos1.x + 12.5)) - 32 <= 0 && abs((pos.y + 24.f) - (enmpos1.y + 12.5)) - 32 <= 0) {
		return 0;
	}
	else if (abs((pos.x + 24.f) - (enmpos2.x + 12.5)) - 32 <= 0 && abs((pos.y + 24.f) - (enmpos2.y + 12.5)) - 32 <= 0) {
		return 0;
	}
	else if (abs((pos.x + 24.f) - (enmpos3.x + 12.5)) - 32 <= 0 && abs((pos.y + 24.f) - (enmpos3.y + 12.5)) - 32 <= 0) {
		return 0;
	}
	else if (abs((pos.x + 24.f) - (enmpos4.x + 12.5)) - 32 <= 0 && abs((pos.y + 24.f) - (enmpos4.y + 12.5)) - 32 <= 0) {
		return 0;
	}
	else return 1;
}

sf::Sprite apple[10];
sf::Vector2f applepos[10];

void makeApple( ) {
	for (int i = 0; i < 10; i++) {
		int x, y;
		x = rand() % 17;
		y = rand() % 20;
		while (check[x][y] != 0 ) {
			x = rand() % 17;
			y = rand() % 20;
		}
		std::cout << x << std::endl << y << std::endl;
		sf::Vector2f position = {y*32.f,x*32.f};
		apple[i].setPosition(sf::Vector2f(position));
		applepos[i] = apple[i].getPosition();
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << check[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

sf::Sprite ice;

void makeIce() {
	int x, y;
	x = rand() % 17;
	y = rand() % 20;
	while (check[x][y] != 0) {
		x = rand() % 17;
		y = rand() % 20;
	}
	sf::Vector2f position = { y * 32.f,x * 32.f };
	ice.setPosition(sf::Vector2f(position));
}

sf::Sprite ChangeSpeed;

void makeSpeed() {
	int x, y;
	x = rand() % 17;
	y = rand() % 20;
	while (check[x][y] != 0) {
		x = rand() % 17;
		y = rand() % 20;
	}
	sf::Vector2f position = { y * 32.f,x * 32.f };
	ChangeSpeed.setPosition(sf::Vector2f(position));
}


int main() {
	float windowWidth = 640;
	float windowHeight = 640;

	int score = 0;

	std::stringstream ssScore;
	ssScore.str();
	//ssScore << "SCORE : " << score;

	bool checkplayer = 1;

	// 1 Left 2 Right 3 Up 4 Down
	int direction[4] = { 4,2,4,1 };
	bool checkenemy[4] = { 1,1,1,1 };

	//---------GameItem----------------------------------------------------------------
	bool unIce = 0;
	sf::Clock cl;
	float timeIce = 0;

	bool unSpeed = 0;
	sf::Clock cl2;
	float timeSpeed = 0;

	int numApple = 10;
	int level = 0;
	int newGame = 0;

	bool gameover = 0;

	int mode = 0;

	srand(time(NULL));

	newGame = level;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Playground Game!", sf::Style::Close | sf::Style::Resize);

	//---------Texture-Enemy-Player-Map-Item-------------------------------------------------
	sf::Texture playerTexture;
	playerTexture.loadFromFile("images/Female2.png");
	Player player(&playerTexture, sf::Vector2u(3, 4), 0.2f, 160.0f);

	sf::Texture PlatformTexture;
	PlatformTexture.loadFromFile("images/IceTileset1.png");

	sf::Texture EnemyTexture1;
	EnemyTexture1.loadFromFile("images/Enemy1.png");
	Enemy enemy1(&EnemyTexture1, sf::Vector2u(3, 4), 0.25f, 0.015f, sf::Vector2f{ 32.f * 4,32.f * 4 });

	sf::Texture EnemyTexture2;
	EnemyTexture2.loadFromFile("images/Enemy2.png");
	Enemy enemy2(&EnemyTexture2, sf::Vector2u(3, 4), 0.25f, 0.015f, sf::Vector2f{ 32.f * 5,32.f * 4 });

	sf::Texture EnemyTexture3;
	EnemyTexture3.loadFromFile("images/Enemy3.png");
	Enemy enemy3(&EnemyTexture3, sf::Vector2u(3, 4), 0.25f, 0.015f, sf::Vector2f{ 32.f * 14,32.f * 4 });

	sf::Texture EnemyTexture4;
	EnemyTexture4.loadFromFile("images/Enemy4.png");
	Enemy enemy4(&EnemyTexture4, sf::Vector2u(3, 4), 0.25f, 0.015f, sf::Vector2f{ 32.f * 15,32.f * 4 });

	sf::Texture IceTexture;
	IceTexture.loadFromFile("images/poison.png");

	sf::Texture SpeedTexture;
	SpeedTexture.loadFromFile("images/poison2.png");

	sf::Texture firstPage;
	firstPage.loadFromFile("images/MENU1.png");
	sf::Sprite Background;
	Background.setTexture(firstPage);

	sf::Texture howtoplay;
	howtoplay.loadFromFile("images/HOWTOPLAY2.png");
	sf::Sprite BackgroundHTP;
	BackgroundHTP.setTexture(howtoplay);

	sf::Texture leaderboard;
	leaderboard.loadFromFile("images/Leaderboard2.png");
	sf::Sprite BackgroundLDB;
	BackgroundLDB.setTexture(leaderboard);

	sf::Texture name;
	name.loadFromFile("images/name2.png");
	sf::Sprite BackgroundName;
	BackgroundName.setTexture(name);

	TileMap map;

	sf::Texture AppleTexture;
	AppleTexture.loadFromFile("images/fruitty.png");

	//----------------------------Menu----------------------------------------------------
	sf::Font font;
	font.loadFromFile("font/font2.ttf");
	sf::Text SCORE;
	SCORE.setFont(font);
	SCORE.setString(ssScore.str());
	SCORE.setCharacterSize(10);
	SCORE.setFillColor(sf::Color::White);
	SCORE.setPosition(sf::Vector2f(32 * 16.4, 10));

	sf::Text textName;
	textName.setFont(font);
	textName.setString("64010002 Kanokporn Supapon");
	textName.setCharacterSize(10);
	textName.setFillColor(sf::Color::White);
	textName.setPosition(sf::Vector2f(10, 10));

	std::string playerN;
	sf::Text playerName;
	playerName.setFont(font);
	playerName.setString(playerN);

	Menu menu(windowWidth, windowHeight);
	//MenuName menuname(windowWidth, windowHeight);
	GameOver gameovermenu(windowWidth, windowHeight);

	Textbox text(20, sf::Color::Transparent, true, font, sf::Vector2f{ 32*6.3,32*8.8 });

	ScoreBoard scoreboard;
	scoreboard.scoreRead();
	
	//------------------------------Sound-----------------------------------------------
	sf::SoundBuffer bufferPoison;
	if (!bufferPoison.loadFromFile("sound/Apple.wav")) {
	
	}

	sf::SoundBuffer bufferApple;
	bufferApple.loadFromFile("sound/Poison.wav");

	sf::SoundBuffer bufferGameOver;
	bufferGameOver.loadFromFile("sound/GameOver.wav");

	sf::SoundBuffer bufferOpen;
	bufferOpen.loadFromFile("sound/Open2.wav");

	sf::SoundBuffer bufferBackground;
	bufferBackground.loadFromFile("sound/Background.wav");

	sf::SoundBuffer bufferClick;
	bufferClick.loadFromFile("sound/Click.wav");

	sf::Sound Applesound;
	Applesound.setBuffer(bufferApple);
	Applesound.setVolume(30);

	sf::Sound Poisonsound;
	Poisonsound.setBuffer(bufferPoison);
	Poisonsound.setVolume(50);

	sf::Sound gameoverSound;
	gameoverSound.setBuffer(bufferGameOver);
	gameoverSound.setVolume(50);

	sf::Sound openSound;
	openSound.setBuffer(bufferOpen);
	openSound.setVolume(50);

	sf::Sound BackgroundSound;
	BackgroundSound.setBuffer(bufferBackground);
	BackgroundSound.setVolume(40);
	BackgroundSound.setLoop(true);

	sf::Sound Click;
	Click.setBuffer(bufferClick);
	BackgroundSound.setVolume(25);

	float deltaTime = 0.0f;
	sf::Clock clock;

	sf::Clock cl3;
	float deltaTime2 = 1.1f;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::KeyReleased:
				if (mode == 0 ) {
					switch (evnt.key.code) {
					case sf::Keyboard::Up:
						menu.MoveUp();
						break;
					case sf::Keyboard::Down:
						menu.MoveDown();
						break;
					case sf::Keyboard::Return:
						Click.play();
						ssScore.str() = "";
						SCORE.setString(ssScore.str());
							switch (menu.getpressItem()) {
							case 0:
								mode = 3;
								break;
							case 1:
								std::cout << "HOW TO PLAY" << std::endl;
								mode = 1;
								break;
							case 2:
								std::cout << "LEADERBOARD" << std::endl;
								mode = 2;
								break;
							case 3:
								window.close();
								break;
							}
						break;
					}
				}
				
				else if (mode == 4) {
					switch (evnt.key.code) {
					case sf::Keyboard::Up:
							gameovermenu.MoveUp();
							break;
					case sf::Keyboard::Down:
							gameovermenu.MoveDown();
							break;
					case sf::Keyboard::Return:
						Click.play();

						scoreboard.scoreAdd(text.getText().c_str(), score);
						scoreboard.scoreRead();
						text.resetString();
						score = 0;
						newGame = 1;
						level = 1;

						player.SetPosition(sf::Vector2f(1000, 1000));

						switch (gameovermenu.getpressItem()) {
						case 0:
							std::cout << gameovermenu.getpressItem() << std::endl;
							gameover = 0;
							mode = 2;
							std::cout << mode << std::endl;
							break;
						case 1:
							std::cout << gameovermenu.getpressItem() << std::endl;
							gameover = 0;
							mode = 0;
							std::cout << mode << std::endl;
							break;
						}

						break;
					}
				}
				break;
			case sf::Event::TextEntered:
				if (mode == 3) {
					text.typedOn(evnt);
				}
				break;
			case sf::Event::KeyPressed:
				if (evnt.key.code == sf::Keyboard::Escape) {
					mode = 0;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		sf::Vector2i a, b, c, d;
		sf::Vector2f pos = player.GetPosition();

		a.x = pos.x / 32;
		a.y = pos.y / 32;

		b.x = (pos.x + 48.f) / 32;
		b.y = a.y;

		c.x = b.x;
		c.y = (pos.y + 48.f) / 32;

		d.x = a.x;
		d.y = c.y;

		//std::cout << a.x<< "  :  " << a.y<< "   " << b.x << "  :  " << b.y << "   " << c.x << "  :  " << c.y << "   " << d.x << "  :  " << d.y << "   " << std::endl;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			checkplayer = checkcollision(sf::Vector2i{ a.y,a.x }, sf::Vector2i{ d.y,d.x });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			checkplayer = checkcollision(sf::Vector2i{ b.y,b.x }, sf::Vector2i{ c.y,c.x });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			checkplayer = checkcollision(sf::Vector2i{ a.y,a.x }, sf::Vector2i{ b.y,b.x });
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			checkplayer = checkcollision(sf::Vector2i{ d.y,d.x }, sf::Vector2i{ c.y,c.x });
		}

		//checkenemy = checkcollisionenm
		checkenemy[0] = enemy1.Collision();
		checkenemy[1] = enemy2.Collision();
		checkenemy[2] = enemy3.Collision();
		checkenemy[3] = enemy4.Collision();
		for (int i = 0; i < 4; i++) {
			if (checkenemy[i] == 0) {
				int newdirection = rand() % 4 + 1;
				while (newdirection == direction[i]) {
					newdirection = rand() % 4 + 1;
				}
				direction[i] = newdirection;
			}
			enemy1.Update(deltaTime2, direction[0],gameover);
			enemy2.Update(deltaTime2, direction[1],gameover);
			enemy3.Update(deltaTime2, direction[2],gameover);
			enemy4.Update(deltaTime2, direction[3],gameover);
		}

		enemy1.Update(deltaTime2, direction[0], gameover);
		enemy2.Update(deltaTime2, direction[1], gameover);
		enemy3.Update(deltaTime2, direction[2], gameover);
		enemy4.Update(deltaTime2, direction[3], gameover);

		//---------------------------Enemy_VS_Player--------------------------------------------
		if (enmVSplayer(enemy1.GetPosition(), enemy2.GetPosition(), enemy3.GetPosition(), enemy4.GetPosition(), player.GetPosition()) == 0 && mode ==5) {
			if (!gameover) {
				BackgroundSound.stop();
				gameoverSound.play();
				mode = 4;
			}
			gameover = 1;
			newGame = 0;
			level = 0;
		}

		player.Update(deltaTime, checkplayer,gameover);


		//check apple
		for (int i = 0; i < 10; i++) {
			if (abs((player.GetPosition().x + 24.f) - (applepos[i].x + 12.5)) <= 15 && abs((player.GetPosition().y + 24.f) - (applepos[i].y + 12.5)) <= 15) {
				Applesound.play();
				
				if (i >= 0 && i < 5) {
					score += i + 3;
				}
				else {
					score += i - 2;
				}
				ssScore.str("");
				SCORE.setString(ssScore.str());
				ssScore << "SCORE : " << score;
				SCORE.setString(ssScore.str());

				applepos[i] = { -10000.0f,-10000.0f };
				//apple[i].setColor(sf::Color::Transparent);
				apple[i].setPosition(sf::Vector2f{ applepos[i] });
				numApple--;
			}
		}

		if (abs((player.GetPosition().x + 24.f) - (ice.getPosition().x + 12.5)) <= 15 && abs((player.GetPosition().y + 24.f) - (ice.getPosition().y + 12.5)) <= 15) {
			sf::Vector2f posIce = { -10000.0f,-10000.0f };
			ice.setPosition(sf::Vector2f{ posIce });
			Poisonsound.play();
			unIce = 1;
			enemy1.changespeed(0.01);
			enemy2.changespeed(0.01);
			enemy3.changespeed(0.01);
			enemy4.changespeed(0.01);
			cl.restart().Zero;
			//timeIce = cl.getElapsedTime().asSeconds();
			//std::cout << timeIce << std::endl;
		}

		timeIce = cl.getElapsedTime().asSeconds();

		if (abs((player.GetPosition().x + 24.f) - (ChangeSpeed.getPosition().x + 12.5)) <= 15 && abs((player.GetPosition().y + 24.f) - (ChangeSpeed.getPosition().y + 12.5)) <= 15) {
			sf::Vector2f posSpeed = { -10000.0f,-10000.0f };
			Poisonsound.play();
			ChangeSpeed.setPosition(sf::Vector2f{ posSpeed });
			unSpeed = 1;
			player.changespeed(250.0f);
			cl2.restart().Zero;
			//timeIce = cl.getElapsedTime().asSeconds();
			//std::cout << timeIce << std::endl;
		}

		timeSpeed = cl2.getElapsedTime().asSeconds();

		if (unIce == 1) {
			if (level <= 3) {
				if (timeIce >= 3) {
					unIce = 0;
				}
			}
			else {
				if (timeIce >= 5) {
					unIce = 0;
				}
			}
		}

		if (unSpeed == 1) {
			if (timeSpeed >= 3) {
				unSpeed = 0;
			}
		}

		if (unIce == 0) {
			enemy1.changespeed(0.015);
			enemy2.changespeed(0.015);
			enemy3.changespeed(0.015);
			enemy4.changespeed(0.015);
		}

		if (unSpeed == 0) {
			player.changespeed(160.0);
		}

		if (numApple == 0) {
			level++;
			openSound.play();
			unSpeed = 0;
			unIce = 0;
			newGame = level;
		}

		window.clear();

		switch (mode) {
		case 0:
			BackgroundSound.stop();
			//std::cout << mode << "   " << newGame << "   " << level << "  " <<gameover<< std::endl;
			window.draw(Background);
			menu.draw(window);
			break;
		case 1:
			BackgroundSound.stop();
			window.draw(BackgroundHTP);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
				Click.play();
				mode = 0;
			}
			break;
		case 2:
			BackgroundSound.stop();
			//std::cout << mode << "   " << newGame << "   " << level << "  " << gameover << std::endl;
			window.draw(BackgroundLDB);
			scoreboard.scoreRead();
			scoreboard.draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
				Click.play();
				mode = 0;
			}
			break;
		case 3:
			BackgroundSound.stop();
			window.draw(BackgroundName);
			text.Draw(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				gameover = 0;
				SCORE.setString("");
				level = 1;
				openSound.play();
				newGame = 1;
				mode = 5;
			}
			break;
		case 4:
			BackgroundSound.stop();
			//std::cout << mode << std::endl;

			player.Update(deltaTime, checkplayer, gameover);

			enemy1.Update(deltaTime2, direction[0], gameover);
			enemy2.Update(deltaTime2, direction[1], gameover);
			enemy3.Update(deltaTime2, direction[2], gameover);
			enemy4.Update(deltaTime2, direction[3], gameover);

			break;
		case 5: 
			switch (newGame) {
			case 1:
				BackgroundSound.setLoop(true);
				map.load("images/IceTileset1.png", sf::Vector2u(32, 32), level1, 20, 20);
				makeArrayCheck(level);
				makeApple();
				for (int i = 0; i < 10; i++) {
					apple[i].setTexture(AppleTexture);
				}
				makeIce();
				BackgroundSound.play();
				ice.setTexture(IceTexture);
				makeSpeed();
				ChangeSpeed.setTexture(SpeedTexture);
				numApple = 10;
				newGame = 100;
				player.SetPosition(sf::Vector2f(560, 560));
				break;
			case 2:
				map.load("images/IceTileset1.png", sf::Vector2u(32, 32), level2, 20, 20);
				makeArrayCheck(level);
				makeApple();
				for (int i = 0; i < 10; i++) {
					apple[i].setTexture(AppleTexture);
				}
				makeIce();
				BackgroundSound.play();
				ice.setTexture(IceTexture);
				makeSpeed();
				ChangeSpeed.setTexture(SpeedTexture);
				numApple = 10;
				newGame = 100;
				player.SetPosition(sf::Vector2f(560, 560));
				break;
			case 3:
				map.load("images/IceTileset1.png", sf::Vector2u(32, 32), level3, 20, 20);
				makeArrayCheck(level);
				makeApple();
				for (int i = 0; i < 10; i++) {
					apple[i].setTexture(AppleTexture);
				}
				makeIce();
				BackgroundSound.play();
				ice.setTexture(IceTexture);
				makeSpeed();
				ChangeSpeed.setTexture(SpeedTexture);
				numApple = 10;
				newGame = 100;
				player.SetPosition(sf::Vector2f(560, 560));
				break;
			case 4:
				map.load("images/IceTileset1.png", sf::Vector2u(32, 32), level4, 20, 20);
				makeArrayCheck(level);
				makeApple();
				BackgroundSound.play();
				for (int i = 0; i < 10; i++) {
					apple[i].setTexture(AppleTexture);
				}
				makeIce();
				ice.setTexture(IceTexture);
				makeSpeed();
				ChangeSpeed.setTexture(SpeedTexture);
				numApple = 10;
				newGame = 100;
				player.SetPosition(sf::Vector2f(560, 560));
				break;
			case 5:
				map.load("images/IceTileset1.png", sf::Vector2u(32, 32), level5, 20, 20);
				makeArrayCheck(level);
				makeApple();
				BackgroundSound.play();
				for (int i = 0; i < 10; i++) {
					apple[i].setTexture(AppleTexture);
				}
				makeIce();
				ice.setTexture(IceTexture);
				makeSpeed();
				ChangeSpeed.setTexture(SpeedTexture);
				numApple = 10;
				newGame = 100;
				player.SetPosition(sf::Vector2f(560, 560));
				break;
			case 6:
				scoreboard.scoreAdd(text.getText().c_str(), score);
				scoreboard.scoreRead();
				text.resetString();
				
				Applesound.stop();
				Poisonsound.stop();
				gameoverSound.stop();
				openSound.stop();
				BackgroundSound.setLoop(false);


				level = 0;
				newGame = 100;
				score = 0;
				player.SetPosition(sf::Vector2f(560, 560));
				mode = 2;

				break;
			}
		}

		if (mode==5) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				newGame = 0;
				mode = 0;
				level = 0;
				text.resetString();
				score = 0;
			}
			window.draw(map);
			//window.draw(shape);

			for (int i = 0; i < 10; i++) {
				window.draw(apple[i]);
			}
			window.draw(ice);
			window.draw(ChangeSpeed);

				enemy1.Draw(window);
				enemy2.Draw(window);
				enemy3.Draw(window);
				enemy4.Draw(window);

				player.Draw(window);

				window.draw(SCORE);
		}
		
		if (mode == 4) {
			window.draw(map);
			//window.draw(shape);

			for (int i = 0; i < 10; i++) {
				window.draw(apple[i]);
			}
			window.draw(ice);
			window.draw(ChangeSpeed);

			enemy1.Draw(window);
			enemy2.Draw(window);
			enemy3.Draw(window);
			enemy4.Draw(window);

			player.Draw(window);

			window.draw(SCORE);

			gameovermenu.draw(window);
		}
		
		window.draw(textName);

		window.display();
	}
}
