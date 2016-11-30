#pragma once
#include "TextureMenager.h"
#include <iostream>
class Player {
public:
	Player(TextureMenager &TexMen, sf::RenderWindow &window,float FPS, float SpeedC = 360.f);
	int hp = 150;
	int Money = 0;
	void Logic(sf::Event &event);
	void Draw(sf::RenderWindow &window);
	bool NewShoot(float CD = 0.4f);
	void SetSpeed(float s = 360.f) {
		Speed = s;
	}
	sf::Vector2f GetPos(){
		return S_Player.getPosition();
	}
	sf::FloatRect PlRect() {
		return S_Player.getGlobalBounds();
	}
	int Gun_Type() {
		if (gun == KINETIC) {
			return 1;
		}
		if (gun == LASER) {
			return 2;
		}
	}
	bool shoot;
	bool B_Die = false;
private:
	enum gun { KINETIC = 1, LASER = 2 };
	gun gun;
	sf::Clock shootclock;
	sf::Clock changebulletclok;
	sf::Time sbTime;
	sf::Time shoottime;
	void WhatPress();
	void Move(sf::Vector2f &ruch);
	sf::Sprite S_Player;
	float Speed = 360.f;
	float fps;
};