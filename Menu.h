#pragma once
#include "MainLoop.h"
#include <sstream>

class Menu {
public:
	int choice = NULL;
	Menu(sf::RenderWindow& window, TextureMenager &TexMen, sf::Font &font);
	void MainMenu(sf::RenderWindow &window, TextureMenager &TexMen);
private:
	sf::Font GTfont; //good times font
	std::string Convert(float number) {
		std::ostringstream buff;
		buff << number;
		return buff.str();
	}
};