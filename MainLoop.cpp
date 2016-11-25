#include "MainLoop.h"
void MainLoop::LoadAllFiles()
{
	TexMen.LoadTexture("TloGry", "data/textures/GameBG.png");
	TexMen.LoadTexture("Player", "data/textures/Player.png");
	TexMen.LoadTexture("Bullet", "data/textures/Pocisk.png");
	TexMen.LoadTexture("Moob1",  "data/textures/Moob1.png");
	TexMen.LoadTexture("Moob2",  "data/textures/Moob2.png");
	TexMen.LoadTexture("Tarcza", "data/textures/shield.png");
	TexMen.LoadTexture("Heal",   "data/textures/Heal.png");
	TexMen.LoadTexture("Speed",  "data/textures/Speed+.png");
	TexMen.LoadTexture("Laser",  "data/textures/Laser.png");
	TexMen.LoadTexture("Money",  "data/textures/MoneY.png");
	std::string GTPOS = "data/Fonts/good times/good times rg.ttf";
	if (!font_good_times.loadFromFile(GTPOS)) {
		system("cls");
		std::cout << "Cannot Load File " + GTPOS << std::endl;
		Beep(50000, 9999999);
		Sleep(3000);
		exit(1);
	}
	else std::cout << "Load File: Aoria.exe Position/" + GTPOS << std::endl;
	sf::RenderWindow window(sf::VideoMode(1024, 512), TitleName + "- Init", sf::Style::Close);
	window.setFramerateLimit(1000);
	InitMenu(window);
}

void MainLoop::InitMenu(sf::RenderWindow& window)
{
	bool exit = false;
	while (exit == false && window.isOpen()) {
		window.setTitle(TitleName + "- Menu");
		Menu men(window, TexMen, font_good_times);
		int whattodo = men.choice;
		switch (whattodo)
		{
		case 0:
			window.setTitle(TitleName);
			exit = true;
			break;
		case 1:
			window.setTitle(TitleName + "- In Game");
			InitGame(window);
			break;
		case 2:
			window.setTitle(TitleName + "- in ControlTutorial");
			InitTutorial(window);
			break;
		default:
			window.setTitle(TitleName + "- ERROR ");
			OutErr("Menu - choose [bad intiger]",window);
			break;
		}
	}
	return;
	//Sleep(1000);
}

void MainLoop::InitGame(sf::RenderWindow& window)
{
	Engine engine(window, TexMen, font_good_times);
}

void MainLoop::InitTutorial(sf::RenderWindow& window)
{
	ControlTutorial ct(TexMen, font_good_times, window);
}

void MainLoop::OutErr(const std::string & Err, sf::RenderWindow& window)
{
	std::cerr << "ERROR: " + Err << std::endl;
	Sleep(4000);
}
