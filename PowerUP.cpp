#include "PowerUP.h"

powerup::powerup()
{
	PowerUP.setOrigin(sf::Vector2f(10, 10));
	DestroyPowerUP = false;
}

powerup::~powerup()
{
	heal = 0;
}

void powerup::Generate(TextureMenager &TexMen)
{
	int powtype = (rand() % 2) + 1;
	//int powtype = 2;
	switch (powtype)
	{
	case 1:
		type = HEAL;
		break;
	case 2:
		type = AS;
		break;
	default:
		std::cout << "BAD" << std::endl;
		break;
	}
	switch (type)
	{
	case powerup::HEAL:
		PowerUP.setTexture(TexMen.getRef("Heal"));
		heal = (rand() % 10) + 5;
		break;
	case powerup::AS:
		ResetSpeed = false;
		chance = (rand() % 100);
		chance = chance / 10;
		if (chance >= 7) {
			Speed = 300.f - rand() % 300;
		}
		else {
			Speed = 360.f + rand() % 360;
		}
		PowerUP.setTexture(TexMen.getRef("Speed"));
		SpeedClock.restart();
		break;
	default:
		break;
	}
	X = (rand() % 1024);
	Y = (rand() % 200);
	PowerUP.setPosition(X, Y);
	powertaken = false;
	clock.restart();
}

void powerup::PowerTimer(TextureMenager & TexMen, float fps)
{
	Y += 150.f * 1.f / fps;
	PowerUP.setPosition(X, Y);
	Timer = clock.getElapsedTime();
	speedtime = SpeedClock.getElapsedTime();
	if (speedtime.asSeconds() >= 3.f) {
		Speed = 360.f;
		ResetSpeed = true;
	}
	if (Timer.asSeconds() >= 12.f) {
		DestroyPowerUP = true;
		heal = 0;
		Speed = 360.f;
		clock.restart();
		Generate(TexMen);
	}
}

void powerup::DrawPowerUP(sf::RenderWindow &window)
{
	window.draw(PowerUP);
}
