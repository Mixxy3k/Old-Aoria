#pragma once
#include "TextureMenager.h"
class Money {
public:
	Money(sf::Vector2f Pos, TextureMenager &TexMen) {
		sGold.setTexture(TexMen.getRef("Money"));
		sGold.setOrigin(8, 8);
		PosX = Pos.x;
		PosY = Pos.y;
		sGold.setPosition(Pos);
		speed = 120.f;
	}
	void Draw(sf::RenderWindow &window) {
		window.draw(sGold);
	}
	void UpdatePos() {
		PosY += speed*1.f / 60.f;
	}
private:
	float PosY;
	float PosX;
	sf::Sprite sGold;
	float speed;
	int TakeGold; // Random

};