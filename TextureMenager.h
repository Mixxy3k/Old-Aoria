#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <windows.h>
class TextureMenager {
public:
	void LoadTexture(const std::string& Name,const std::string& Pos) {
		sf::Texture Texture;
		if (!Texture.loadFromFile(Pos)) {
			system("cls");
			std::cout << "Cannot Load File " + Pos << std::endl;
			Beep(759, 300);
			Sleep(3000);
			exit(1);
		}
		else {
			MapTexture[Name] = Texture;
			std::cout << "Load File: Aoria.exe Position/" + Pos << std::endl;
		}
	}
	sf::Texture& getRef(const std::string& texture) {

		return this->MapTexture.at(texture);
	}
private:
	std::map<std::string, sf::Texture> MapTexture;
};
