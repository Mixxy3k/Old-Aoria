#pragma once
#include "TextureMenager.h"
class Moob {
public:
	Moob(int sX, int sY, sf::Texture &T_Moob, int idm, int MHP = 5, float MoobSpeed = 340.f);
	void MoobAction();
	void Wait();
	void DrawMoob(sf::RenderWindow &window);
	bool NewShoot();
	bool HaveShield = true;
	sf::Vector2f GetPosSI() {
		return S_Moob.getPosition();
	}
	sf::FloatRect MoobRect() {
		return S_Moob.getGlobalBounds();
	}
	int mHP;
	int ID;
private:
	sf::Sprite S_Moob;
	float next_shoot;
	sf::Clock czekaj;
	sf::Clock ammo_wait;
	sf::Time time;
	sf::Time BulletTime;
	enum go{UP,DOWN,LEFT,RIGHT};
	go go;
	float wait = NULL;
	bool action;
	float speed;
	void ruch(sf::Vector2f ruch)
	{
		S_Moob.move(ruch * 1.f/60.f * speed);
	}
};