#include "Menu.h"
Menu::Menu(sf::RenderWindow &window, TextureMenager & TexMen, sf::Font &font)
{
	GTfont = font;
	MainMenu(window, TexMen);
}
float getFPS(const sf::Time& time) {
	return (1000000.0f / time.asMicroseconds());
}
void Menu::MainMenu(sf::RenderWindow & window, TextureMenager &TexMen)
{
	sf::Sprite BGM;
	BGM.setTexture(TexMen.getRef("TloGry"));
	BGM.setPosition(0, -300);
	sf::Text MainText("Aoria", GTfont, 75);
	sf::Text FpsInf("", GTfont, 10);
	sf::Text creator("Create by Mixxy3k DO NOT DISTRIBUTE V 1.6 ALPHA", GTfont, 8);
	creator.setColor(sf::Color::Black);
	creator.setPosition(0, 500);
	MainText.setPosition(sf::Vector2f(1024 / 2 - MainText.getGlobalBounds().width / 2, 20));
	sf::Clock clock;
	sf::Clock FPSClock;
	for (;;) {
		const int ile = 3;

		sf::Text tekst[ile];

		std::string str[] = { "Play","Control","Exit" };
		for (int i = 0; i < ile; i++)
		{
			tekst[i].setFont(GTfont);
			tekst[i].setCharacterSize(65);

			tekst[i].setString(str[i]);
			tekst[i].setPosition(1024 / 2 - tekst[i].getGlobalBounds().width / 2, 170 + i * 120);
		}

		while (1)
		{
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed &&
					event.key.code == sf::Keyboard::Escape) {
					choice = 0;
					return;
				}

				else if (tekst[2].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				{
					choice = 0;
					return;
				}
				else if (tekst[0].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				{
					choice = 1;
					return;
				}
				else if (tekst[1].getGlobalBounds().contains(mouse) && event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left)
				{
					choice = 2;
					return;
				}
			}
			for (int i = 0; i < ile; i++)
				if (tekst[i].getGlobalBounds().contains(mouse))
					tekst[i].setColor(sf::Color::Cyan);
				else tekst[i].setColor(sf::Color::White);

				int fps = getFPS(FPSClock.restart());
				FpsInf.setString(Convert(fps));
				window.clear();
				window.draw(BGM);
				window.draw(FpsInf);
				window.draw(MainText);
				window.draw(creator);
				for (int i = 0; i < ile; i++)
					window.draw(tekst[i]);

				window.display();
				Sleep(10);
		}
	}
}
