#include "Bullet.h"

Bullet::Bullet(sf::Texture & texture, bool isPL, sf::Vector2f pos, int BDMG, float LT, float SPEED)
{
	S_Bullet.setTexture(texture);
	S_Bullet.setPosition(pos);
	S_Bullet.setOrigin(S_Bullet.getGlobalBounds().width / 2, S_Bullet.getGlobalBounds().height / 2);
	isPlayer = isPL;
	livetime = LT;
	DMG = BDMG;
	speed = SPEED;
	desstroyclass = false;
	clock.restart();
}

void Bullet::MoveBullet()
{
	if (isPlayer == true) {
		S_Bullet.move(sf::Vector2f(0.f, -10) * 1.f / 60.f * speed);
	}
	if (isPlayer == false) {
		S_Bullet.move(sf::Vector2f(0.f, 10) * 1.f / 60.f * speed);
	}
}

void Bullet::DestroyHuH()
{
	time = clock.getElapsedTime();
	if (time.asSeconds() >= livetime) {
		desstroyclass = true;
	}
}
