#include "Textbox.h"

Textbox::Textbox(int size, sf::Color color, bool sel, sf::Font& font, sf::Vector2f position)
{
	type.loadFromFile("sound/SingleKey.wav");
	Type.setBuffer(type);
	Type.setVolume(35);

	textbox.setFont(font);
	textbox.setPosition(position.x-20,position.y);
	textbox.setCharacterSize(size-3);


	body.setSize(sf::Vector2f(200.0f, 40.0f));
	//body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(position.x - 5, position.y - 5);
	body.setFillColor(color);
	isSelected = sel;
	limit = 20 - 1;
	if (sel)
	{
		textbox.setString("_");
	}
}

void Textbox::resetString() {
	text.str("");
	textbox.setString("_");
}

void Textbox::setSelected(bool sel)
{
	isSelected = sel;
	if (!sel)
	{
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length(); i++)
		{
			newT += t[i];
		}
		textbox.setString(newT);
	}
}

void Textbox::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(textbox);
}

void Textbox::typedOn(sf::Event input)
{
	if (isSelected) {
		int charType = input.text.unicode;
		if (charType < 128) {
			if (text.str().length() <= limit) {
				inputLogic(charType);
				Type.play();
			}
			else if (text.str().length() > limit && charType == DELETE_KEY) {
				deleteLastChar();
				Type.play();
			}
		}
	}
}

void Textbox::inputLogic(int charTyped)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY)
	{
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY)
	{
		if (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	textbox.setString(text.str() + "_");
}

void Textbox::deleteLastChar()
{
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.length() - 1; i++)
	{
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}