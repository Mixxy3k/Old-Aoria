#pragma once
#include <vector>
#include "TextureMenager.h"
#include "Player.h"
#include "Bullet.h"
#include "SI.h"
#include "Shield.h"
#include "Lvl.h"
#include "PowerUP.h"
#include "Gold.h"
#include "FilesMenager.h"
#include <sstream>
class Engine {
public:
  Engine(sf::RenderWindow &window, TextureMenager &TexMen,sf::Font &font); //tu bedo inne dane jescze, kiedys 
  void GameLoop(sf::RenderWindow &window, TextureMenager &TexMen, sf::Font &font);

private:
	Lvl lvl;
	powerup pow;
	FilesMenager files;
	int RedMoobAlive = 0;
	int BlueMoobAlive = 0;
	sf::Font GTfont;
	sf::Sprite BG;
	std::vector<Bullet*> plBullet;
	std::vector<Moob*>   BlueMoob;
	std::vector<Bullet*> MoobBullet;
	std::vector<Moob*>   RedMoob;
	std::vector<Shield*> Shields;
	std::vector<Money*>  money;

	void EventMenager(sf::RenderWindow &window, sf::Event &ev, Player &pl);
	void PlBulletMenager(Player &pl, TextureMenager & TexMen);
	void MoobsMenager(TextureMenager & TexMen);
	void MoobBulletMenager();
	void DestroyMenager(Player &pl, sf::RenderWindow &window, TextureMenager & TexMen);
	void LvlMenager(TextureMenager & TexMen, Player &pl);
	void PooverUpMenager(Player &pl, TextureMenager & TexMen);
	void MoneyMenager(Player &pl);
	float getFPS(const sf::Time& time) {
		return (1000000.0f / time.asMicroseconds());
	}
	void Clear() {
		BlueMoob.clear();
		RedMoob.clear();
		Shields.clear();
		BlueMoobAlive = 0;
		RedMoobAlive = 0;
	}
	std::string Convert(float number) {
		std::ostringstream buff;
		buff << number;
		return buff.str();
	}
	void Exit(){
		return;
	}
	float FPS = 90.f;

	bool scd = false; // start clock die
	bool fr = true; // first lvl after run game
	bool close = false;
	sf::Clock DieClock;
};