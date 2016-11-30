#pragma once
#include "TextureMenager.h"
class powerup {
public:
	powerup();
	~powerup();
	void Generate(TextureMenager &TexMen);
	void PowerTimer(TextureMenager & TexMen, float fps);
	void DrawPowerUP(sf::RenderWindow &window);
	bool DestroyPowerUP;
	bool powertaken;
	int heal = 10;
	float Speed;
	bool ResetSpeed = false;
	enum Type { HEAL = 1, AS = 2 };
	Type type;
	sf::Sprite PowerUP;
private:
	float chance;
	float Y;
	float X;
	sf::Time Timer = sf::Time::Zero;
	sf::Clock clock;
	sf::Time speedtime = sf::Time::Zero;
	sf::Clock SpeedClock;
};