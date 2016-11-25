#pragma once
#include "TextureMenager.h"
class Shield {
public:
	Shield(sf::Texture &texture, sf::Vector2f Pos,int HowMany,int MoobID) {
		S_Shield.setTexture(texture);
		S_Shield.setPosition(Pos);
		S_Shield.setOrigin(11, -10);
		Shields = HowMany;
		MID = MoobID;
		isGood = true;
	}
	void SetPos(sf::Vector2f &newPos) {
		S_Shield.setPosition(newPos);
	}
	void Draw(sf::RenderWindow &win) {
		win.draw(S_Shield);
	}
	int Shields;
	int MID;
	bool isGood;
private:
	sf::Sprite S_Shield;
};