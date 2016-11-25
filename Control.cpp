#include "Control.h"

ControlTutorial::ControlTutorial(TextureMenager & TexMen, sf::Font & font,sf::RenderWindow &window)
{
	Tutorial(TexMen, font, window);
}

void ControlTutorial::Tutorial(TextureMenager & TexMen, sf::Font & font, sf::RenderWindow &window)
{
	sf::Sprite BGM;
	BGM.setTexture(TexMen.getRef("TloGry"));
	BGM.setPosition(0, -300);
	sf::Text MainText("Aoria - Control", font, 75);
	sf::Text FpsInf("", font, 10);
	sf::Text creator("Create by Mixxy3k DO NOT DISTRIBUTE V 1.0 ALPHA", font, 8);
	creator.setColor(sf::Color::Black);
	creator.setPosition(0, 500);
	MainText.setPosition(sf::Vector2f(1024 / 2 - MainText.getGlobalBounds().width / 2, 20));
	sf::Clock clock;
	sf::Clock FPSClock;
	for (;;) {
		const int ile = 5;

		sf::Text tekst[ile];

		std::string str[] = {
			"Press SPACE to shot a bullet ",
			"Use WSAD System to move player",
			"Take PowerUps",
			"Press LShift to change gun",
			"Say YeY and go menu ;P"
		};
		for (int i = 0; i < ile; i++)
		{
			tekst[i].setFont(font);
			tekst[i].setCharacterSize(40);

			tekst[i].setString(str[i]);
			tekst[i].setPosition(1024 / 2 - tekst[i].getGlobalBounds().width / 2, 170 + i * 60);
		}
		while (1)
		{
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
					event.key.code == sf::Keyboard::Escape) {
					exit(0);
					return;
				}

  				else if (tekst[4].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				{
					return;
				}
			}
			for (int i = 0; i < ile; i++) {
				if (tekst[i].getGlobalBounds().contains(mouse) && i == 4)
					tekst[i].setColor(sf::Color::Cyan);
				else tekst[i].setColor(sf::Color::White);
			}
				window.clear();
				window.draw(BGM);
				window.draw(MainText);
				window.draw(creator);
				for (int i = 0; i < ile; i++)
					window.draw(tekst[i]);
				window.display();
				Sleep(10);
		}
	}
}

