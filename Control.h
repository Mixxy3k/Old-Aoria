#pragma once
#include "MainLoop.h"
class ControlTutorial {
public:
	ControlTutorial(TextureMenager &TexMen, sf::Font &font, sf::RenderWindow &window);
	void Tutorial(TextureMenager &TexMen, sf::Font &font, sf::RenderWindow &window);
};