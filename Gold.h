#pragma once
#include "TextureMenager.h"
class Money {
public:
	Money(sf::Vector2f Pos, TextureMenager &TexMen, float FPS) {
		sGold.setTexture(TexMen.getRef("Money"));
		sGold.setOrigin(8, 8);
		PosX = Pos.x;
		PosY = Pos.y;
		sGold.setPosition(Pos);
		speed = 200.f;
		fps = FPS;
	}
	void Draw(sf::RenderWindow &window) {
		window.draw(sGold);
	}
	void UpdatePos() {
		PosY += speed*(1.f / fps);
		sGold.setPosition(PosX, PosY);
	}
	void Colision(sf::FloatRect PL){
		if (sGold.getGlobalBounds().intersects(PL)) {
			deleteclass = true;
		}
	}
	bool deleteclass = false;
private:
	float PosY;
	float PosX;
	sf::Sprite sGold;
	float speed;
	int TakeGold; // Random
	float fps;

};