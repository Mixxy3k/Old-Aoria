#pragma once
#include "TextureMenager.h"
#include "Control.h"
#include "GameEngine.h"
#include "Menu.h"
class MainLoop {
public:
	MainLoop() {

	}
	void LoadAllFiles();
	void InitMenu(sf::RenderWindow& window);
	void InitGame(sf::RenderWindow& window);
	void InitTutorial(sf::RenderWindow& window);
	void OutErr(const std::string& Err, sf::RenderWindow& window);


private:
	const std::string TitleName = "Aoria v1.6 PREALPHA ";
	TextureMenager TexMen;
	sf::Font font_good_times;
};