#pragma once
#include "TextureMenager.h"
class Bullet {
public:
	Bullet(sf::Texture & texture, bool isPL, sf::Vector2f pos, int BDMG = 1, float LT = 1.7f, float SPEED = 60.f);
	void MoveBullet();
	void DrawBullet(sf::RenderWindow &win) {
		win.draw(S_Bullet);
	}
	void DestroyHuH();
	bool desstroyclass;
	sf::FloatRect BulletRec() {
		return S_Bullet.getGlobalBounds();
	}
	int ReadDMG() {
		return DMG;
	}
private:
	sf::Clock clock;
	sf::Time time;
	sf::Sprite S_Bullet;
	int DMG;
	bool isPlayer;
	float speed;
	float livetime;
};
