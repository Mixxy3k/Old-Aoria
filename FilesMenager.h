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
	}
	void Load() {
		std::fstream plik(fileName, std::ios::in);
		if (plik.good() == false) {
			std::cout << "Cannot save file!" << std::endl;
			NewFile();
		}
		else {
			plik >> hp >> lvl;
		}
	}
	void NewFile() {
		std::fstream plik(fileName);
		if (plik.good() == false) {
			std::cout << "Cannot create file" << std::endl;
		}
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