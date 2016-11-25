#include "SI.h"
Moob::Moob(int sX, int sY, sf::Texture &T_Moob, int idm, int MHP, float MoobSpeed)
{
	S_Moob.setTexture(T_Moob);
	S_Moob.setOrigin(S_Moob.getGlobalBounds().width / 2, S_Moob.getGlobalBounds().height / 2);
	S_Moob.setPosition(sX, sY);
	S_Moob.setRotation(180);
	action = true;
	next_shoot = 1 + (idm / 10);
	mHP = MHP;
	ID = idm;
	speed = MoobSpeed;
	ammo_wait.restart();
}

void Moob::MoobAction()
{
	if (action == true) {
		int id = (rand() % 4);
		int a = (rand() & 5)+1;
		wait = 1.4 / a;
		switch (id) {
		case 0:
			go = UP;
			break;
		case 1:
			go = DOWN;
			break;
		case 2:
			go = LEFT;
			break;
		case 3:
			go = RIGHT;
			break;
		}
		time = sf::Time::Zero;
		czekaj.restart();
		//cout << "GO=" << go << " Wait=" << wait << " ID=" << id << endl;
		action = false;
	}
	if (action == false) {
		switch (go)
		{
		case Moob::UP:
			if (S_Moob.getPosition().y > 0) {
				ruch(sf::Vector2f(0, -1));
			}
			break;
		case Moob::DOWN:
			if (S_Moob.getPosition().y < 512/1.5) {
				ruch(sf::Vector2f(0, 1));
			}
			break;
		case Moob::LEFT:
			if (S_Moob.getPosition().x > 0) {
				ruch(sf::Vector2f(-1, 0));
			}
			break;
		case Moob::RIGHT:
			if (S_Moob.getPosition().x < 1024) {
				ruch(sf::Vector2f(1, 0));
			}
			break;
		default:
			break;
		}
		if (S_Moob.getPosition().x <= 0) {
			go = RIGHT;
		}
		if (S_Moob.getPosition().x >= 1024) {
			go = LEFT;
		}
		if (S_Moob.getPosition().y <= 0) {
			go = DOWN;
		}
		if (S_Moob.getPosition().y >= 512/1.5) {
			go = UP;
		}
	}
}
void Moob::Wait()
{
	time = czekaj.getElapsedTime();
	if (time.asSeconds() >= wait) {
		action = true;
	}
}

void Moob::DrawMoob(sf::RenderWindow &window)
{
	window.draw(S_Moob);
}

bool Moob::NewShoot()
{
	BulletTime = ammo_wait.getElapsedTime();
	if (BulletTime.asSeconds() >= next_shoot) {
		ammo_wait.restart();
		return true;
	}

	return false;
}
