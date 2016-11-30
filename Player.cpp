#include "Player.h"

Player::Player(TextureMenager & TexMen, sf::RenderWindow &window,float FPS,float SpeedC)
{
	S_Player.setTexture(TexMen.getRef("Player"));
	S_Player.setOrigin(32, 32);
	S_Player.setPosition(512, 256);
	Speed = SpeedC;
	fps = FPS;
	shoot = false;
	shootclock.restart();
	gun = KINETIC;
}

void Player::Logic(sf::Event & event)
{
	WhatPress();
}

void Player::Move(sf::Vector2f &ruch)
{
	S_Player.move(ruch * 1.f/fps * Speed);
}

void Player::WhatPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && S_Player.getPosition().y >= 0 + 32)
	{
		Move(sf::Vector2f(0, -1.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && S_Player.getPosition().y <= 512 - 32)
	{
		Move(sf::Vector2f(0, 1.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && S_Player.getPosition().x >= 0 + 32)
	{
		Move(sf::Vector2f(-1.f, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && S_Player.getPosition().x <= 1024 - 32)
	{
		Move(sf::Vector2f(1.f, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		shoot = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
		bool change = false;
		if (changebulletclok.getElapsedTime().asSeconds() >= 3.f) {
			if (gun == KINETIC) {
				gun = LASER;
				change = true;
				changebulletclok.restart();
			}
			if (change == false) {
				if (gun == LASER) {
					gun = KINETIC;
					changebulletclok.restart();
				}
			}
		}
	}
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(S_Player);
}



bool Player::NewShoot(float CD)
{
	shoottime = shootclock.getElapsedTime();
	if (shoottime.asSeconds() >= CD && shoot == true) {
		shootclock.restart();
		shoot = false;
		return true;
	}
	return false;
}
