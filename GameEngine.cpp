#include "GameEngine.h"
Engine::Engine(sf::RenderWindow & window, TextureMenager & TexMen, sf::Font &font)
{
	BG.setTexture(TexMen.getRef("TloGry"));
	GTfont = font;
	GameLoop(window, TexMen, font);
}

void Engine::GameLoop(sf::RenderWindow &window, TextureMenager & TexMen,sf::Font &font)
{
	sf::Clock FPSClock;
	sf::Clock clock;
	sf::Text FpsInf("", GTfont, 10);
	sf::Text HP("", GTfont, 10);
	HP.setColor(sf::Color::Green);
	sf::Text MoobsInfo("", GTfont, 8);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	FpsInf.setPosition(0, 17);
	HP.setPosition(0, 8);
	Player pl(TexMen, window);
	while (pl.B_Die == false && window.isOpen())
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			sf::Event event;
			EventMenager(window, event);
			LvlMenager(TexMen,pl);
			if (pl.hp >= 0) {
				pl.Logic(event);
			}
			MoobsMenager(TexMen);
			MoobBulletMenager();
			PlBulletMenager(pl, TexMen);
			PooverUpMenager(pl,TexMen);
			DestroyMenager(pl, window, TexMen);
			pl.shoot = false;
			timeSinceLastUpdate -= TimePerFrame;
		}
		int fps = getFPS(FPSClock.restart());
		FpsInf.setString("FPS " + Convert(fps));
		MoobsInfo.setString("Red Moob " + Convert(RedMoobAlive) + " Blue Moob " + Convert(BlueMoobAlive));
		HP.setString("HP = " + Convert(pl.hp));
		window.clear();
		window.draw(BG);
		for (int i = 0; i < plBullet.size(); i++) {
			plBullet[i]->DrawBullet(window);
		}
		for (int i = 0; i < money.size(); i++) {
			money[i]->Draw(window);
		}
		for (int i = 0; i < BlueMoob.size(); i++) {
			BlueMoob[i]->DrawMoob(window);
		}
		for (int i = 0; i < RedMoob.size(); i++) {
			RedMoob[i]->DrawMoob(window);
		}
		for (int i = 0; i < MoobBullet.size(); i++) {
			MoobBullet[i]->DrawBullet(window);
		}
		for (int i = 0; i < Shields.size(); i++) {
			if (Shields[i]->isGood == true)
				Shields[i]->Draw(window);
		}
		if (pow.powertaken == false) {
			pow.DrawPowerUP(window);
		}
		if (pl.hp >= 0) {
			pl.Draw(window);
		}
		window.draw(MoobsInfo);
		window.draw(FpsInf);
		window.draw(HP);
		window.display();
	}
}

void Engine::EventMenager(sf::RenderWindow &window, sf::Event & ev)
{
	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed || ev.type == sf::Event::KeyPressed &&
			ev.key.code == sf::Keyboard::Escape) {
			window.close();
		}
	}
}

void Engine::PlBulletMenager(Player & pl, TextureMenager & TexMen)
{
	switch (pl.Gun_Type())
	{
	case 1:
		if (pl.NewShoot(0.5) == true) {
			plBullet.push_back(new Bullet(TexMen.getRef("Bullet"), true, pl.GetPos(),1,1.4,80.f));
		}
		break;
	case 2:
		if (pl.NewShoot(0.8f) == true) {
			plBullet.push_back(new Bullet(TexMen.getRef("Laser"), true, pl.GetPos(), 3,1.7,50.f));
		}
		break;
	default:
		break;
	}
	for (int i = 0; i < plBullet.size(); i++) {
		plBullet[i]->MoveBullet();
		plBullet[i]->DestroyHuH();
		if (plBullet[i]->desstroyclass == true) {
			plBullet.erase(plBullet.begin() + i);
		}
	}
}

void Engine::MoobsMenager(TextureMenager & TexMen)
{
	for (int i = 0; i < BlueMoob.size(); i++) {
		if (BlueMoob[i]->NewShoot() == true) {
			MoobBullet.push_back(new Bullet(TexMen.getRef("Bullet"), false, BlueMoob[i]->GetPosSI(), 2, 1.7, 60.f));
		}
		BlueMoob[i]->MoobAction();
		BlueMoob[i]->Wait();
		Shields[i]->SetPos(BlueMoob[i]->GetPosSI());
	}
	for (int i = 0; i < RedMoob.size(); i++) {
		if (RedMoob[i]->NewShoot() == true) {
			MoobBullet.push_back(new Bullet(TexMen.getRef("Bullet"), false, RedMoob[i]->GetPosSI(), 5, 0.9f, 90.f));
		}
		RedMoob[i]->MoobAction();
		RedMoob[i]->Wait();
		Shields[i + BlueMoobAlive]->SetPos(RedMoob[i]->GetPosSI());
	}
}

void Engine::MoobBulletMenager()
{
	for (int i = 0; i < MoobBullet.size(); i++) {
		MoobBullet[i]->MoveBullet();
		MoobBullet[i]->DestroyHuH();
		if (MoobBullet[i]->desstroyclass == true) {
			MoobBullet.erase(MoobBullet.begin() + i);
		}
	}
}
void Engine::DestroyMenager(Player &pl, sf::RenderWindow &window, TextureMenager & TexMen)
{
	//Kolizja Gracza
	for (int i = 0; i < MoobBullet.size(); i++) {
		if (pl.hp >= 0) {
			if (pl.PlRect().intersects(MoobBullet[i]->BulletRec())) {
				pl.hp -= MoobBullet[i]->ReadDMG();
				MoobBullet.erase(MoobBullet.begin() + i);
			}
		}
	}
	if (pl.hp <= 0) {
		if (scd == false) {
			DieClock.restart();
			scd = true;
		}
		if (DieClock.getElapsedTime().asSeconds() >= 2.5f) {
			std::cout << "ja" << std::endl;
			pl.B_Die = true;
		}
	}
	bool del = false;
	for (int i = 0; i < plBullet.size(); i++) {
		for (int j = 0; j < BlueMoob.size(); j++) {
			//Kolizja SI BLUE
			if (plBullet[i]->BulletRec().intersects(BlueMoob[j]->MoobRect())) {
				//Tarcze 
				if (BlueMoob[j]->HaveShield == true && Shields[j]->isGood == true && BlueMoob[j]->ID == Shields[j]->MID) {
					Shields[j]->Shields -= plBullet[i]->ReadDMG();
					if (Shields[j]->Shields <= 0) {
						Shields[j]->isGood = false;
						BlueMoob[j]->HaveShield = false;
						std::cout << "Shields off for moob" << std::endl;
					}
				}
				if (Shields[j]->isGood == false && BlueMoob[j]->HaveShield == false && BlueMoob[j]->ID == Shields[j]->MID) {
					BlueMoob[j]->mHP -= plBullet[i]->ReadDMG();
				}
				if (BlueMoob[j]->mHP <= 0) {
					money.push_back(new Money(BlueMoob[j]->GetPosSI(), TexMen));
					BlueMoobAlive--;
					BlueMoob.erase(BlueMoob.begin() + j);
					Shields.erase(Shields.begin() + j);
				}
				plBullet.erase(plBullet.begin() + i);
				del = true;
			}
		}
		if (del == false) {
			for (int j = 0; j < RedMoob.size(); j++) {
				if (plBullet[i]->BulletRec().intersects(RedMoob[j]->MoobRect())) {
					if (RedMoob[j]->HaveShield == true && Shields[j + BlueMoobAlive]->isGood == true && RedMoob[j]->ID == Shields[j + BlueMoobAlive]->MID) {
						Shields[j + BlueMoobAlive]->Shields -= plBullet[i]->ReadDMG();
						if (Shields[j + BlueMoobAlive]->Shields <= 0) {
							Shields[j + BlueMoobAlive]->isGood = false;
							RedMoob[j]->HaveShield = false;
							std::cout << "Shields off for moob" << std::endl;
						}
					}
					if (Shields[j + BlueMoobAlive]->isGood == false && RedMoob[j]->HaveShield == false && RedMoob[j]->ID == Shields[j + BlueMoobAlive]->MID) {
						RedMoob[j]->mHP -= plBullet[i]->ReadDMG();
					}
					if (RedMoob[j]->mHP <= 0) {
						money.push_back(new Money(RedMoob[j]->GetPosSI(), TexMen));
						RedMoobAlive--;
						RedMoob.erase(RedMoob.begin() + j);
						Shields.erase(Shields.begin() + (j + BlueMoobAlive));
					}
					plBullet.erase(plBullet.begin() + i);
				}
			}
			del = false;
		}
	}
}

void Engine::LvlMenager(TextureMenager & TexMen, Player &pl)
{
	if (RedMoob.empty() && BlueMoob.empty()) {
		lvl.lvl++;
		if (fr == true) {
			files.Load();
			lvl.lvl = files.LVL();
			fr = false;
		}
		lvl.lvlskl();
		std::cout << "lvl: " << lvl.lvl << std::endl;
		Clear();
		for (int i = 0; i < lvl.BlueMoobResp; i++) {
			BlueMoob.push_back(new Moob(814, 200, TexMen.getRef("Moob1"), i, 2, lvl.BlueSpeed));
			Shields.push_back(new Shield(TexMen.getRef("Tarcza"), sf::Vector2f(814, -200), 2, i));
			BlueMoobAlive++;
		}
		for (int i = 0; i < lvl.RedMoobResp; i++) {
			RedMoob.push_back(new Moob(200, 200, TexMen.getRef("Moob2"), i + BlueMoobAlive, 4, lvl.RedSpeed));
			Shields.push_back(new Shield(TexMen.getRef("Tarcza"), sf::Vector2f(200, -200), 2, i + BlueMoobAlive));
			RedMoobAlive++;
		}
		files.Save(pl.hp, lvl.lvl);
	}
}

void Engine::PooverUpMenager(Player &pl, TextureMenager & TexMen)
{
	pow.PowerTimer(TexMen);
	if (pow.PowerUP.getGlobalBounds().intersects(pl.PlRect())) {
		if (pow.type == 1 && pow.powertaken == false) {
			pl.hp += pow.heal;
			pow.powertaken = true;
		}
		if (pow.type == 2 && pow.powertaken == false) {
			std::cout << pow.Speed << std::endl;
			pl.SetSpeed(pow.Speed);
			pow.powertaken = true;
		}
	}
	if (pow.ResetSpeed == true) {
		pl.SetSpeed();
		pow.ResetSpeed = false;
	}
}
void Engine::MoneyMenager()
{
	for (int i = 0; i < money.size(); i++) {
		money[i]->UpdatePos();
	}
}
