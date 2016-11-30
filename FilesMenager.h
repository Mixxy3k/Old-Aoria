#pragma once
#include <fstream>
#include <iostream>
class FilesMenager {
public:
	void Save(int hp, int lvl) {
		std::fstream plik(fileName, std::ios::out);
		if (plik.good() == false) {
			std::cout << "Cannot read file!" << std::endl;
			NewFile();
		}
		else {
			plik << hp << std::endl;
			plik << lvl << std::endl;
		}
		plik.close();
	}
	void Load() {
		std::fstream plik(fileName, std::ios::in);
		if (plik.good() == false) {
			if (NewFile() == false) {
				std::cout << "Cannot create file" << std::endl;
			}
		}
		else {
			plik >> hp >> lvl;
		}
		plik.close();
	}
	bool NewFile() {
		std::fstream plik(fileName);
		if (plik.good() == false) {
			std::cout << "Cannot create file" << std::endl;
			return false;
		}
		return true;
	}
	int HP() {
		return hp;
	}
	int LVL() {
		return lvl;
	}
private:
	std::string fileName = "Stats.txt";
	int hp;
	int lvl;
};