#pragma once
#include <iostream>
class Lvl {
public:
	bool end = false;
	int lvl = 0;
	std::string lvls = "ERROR";
	int BlueMoobResp = NULL;
	int RedMoobResp = NULL;
	float BlueSpeed = NULL;
	float RedSpeed = NULL;
	void lvlskl() {
		switch (lvl) {
		case 1:
			BlueMoobResp = 1;
			RedMoobResp = 1;
			BlueSpeed = 300.f;
			RedSpeed = 350.f;
			break;
		case 2:
			BlueMoobResp = 2;
			RedMoobResp = 2;
			BlueSpeed = 340.f;
			RedSpeed = 340.f;
		//	lvls = "EZ ;)";
			break;
		case 3:
			BlueMoobResp = 5;
			RedMoobResp = 5;
			BlueSpeed = 330.f;
			RedSpeed = 330.f;
		//	lvls = "Harder";
			break;
		case 4:
			BlueMoobResp = 10;
			RedMoobResp = 3;
			BlueSpeed = 360.f;
			RedSpeed = 360.f;
		//	lvls = "EPIC";
			break;
		case 5:
			BlueMoobResp = 3;
			RedMoobResp = 3;
			BlueSpeed = 500.f;
			RedSpeed = 500.f;
		//	lvls = "SPEEED";
			break;
		case 6:
			BlueMoobResp = 10;
			RedMoobResp = 10;
			BlueSpeed = 340.f;
			RedSpeed = 340.f;
		//	lvls = "WTF Mixxy?";
			break;
		case 7:
			BlueMoobResp = 15;
			RedMoobResp = 15;
			BlueSpeed = 400.f;
			RedSpeed = 400.f;
		//	lvls = "OMG";
			break;
		case 8:
			end = true;
			break;
		}
	}
};