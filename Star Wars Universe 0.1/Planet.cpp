#include "Planet.h"
#include <cstring>
#include <fstream>
#pragma warning(disable : 4996)


myString convertCharToString(char* arr) {

	myString newString;
	newString.addCharArr(arr);

	return newString;
}


char* stringToChar(const myString& _string) {
	int size = _string.get_string_size();
	char* newArr = new char[size];
	for (size_t i = 0; i < size; ++i) {
		newArr[i] = _string[i];
	}
	return newArr;
}

void Planet::set_planetName(const myString& _planetName) {
	this->planetName = _planetName;

}

void Planet::set_planetName(const char* _planetName) {
	this->planetName.set_string(_planetName);
}

void Planet::set_jedaiList(Jedai& curJedi) {
	this->jedaiList.addElement(curJedi);
}

const myString& Planet::get_planetName()const {
	return this->planetName;
}


int Planet::get_sizeOfJedaiList()const {
	return this->jedaiList.get_curSize();
}


myVector<Jedai>& Planet::get_jedaiList() {
	return this->jedaiList;
}

Planet& Planet::operator=(const Planet& other) {
	if (this != &other) {
		this->planetName = other.planetName;
		this->jedaiList = other.jedaiList;
	}
	return *this;
}


void Planet::find_most_used_saber_color(const myString& planet_name, const int counter_white, const int counter_red, const int counter_green, const int counter_blue, const int counter_black) {

	int most_used_saber_color = 0;

	if (most_used_saber_color < counter_white) {
		most_used_saber_color = counter_white;
	}
	else if (most_used_saber_color < counter_red) {
		most_used_saber_color = counter_red;
	}
	else if (most_used_saber_color < counter_green) {
		most_used_saber_color = counter_green;
	}
	else if (most_used_saber_color < counter_blue) {
		most_used_saber_color = counter_blue;
	}
	else if (most_used_saber_color < counter_black) {
		most_used_saber_color = counter_black;
	}
	if (most_used_saber_color != 0) {
		if (most_used_saber_color == counter_white) { std::cout << "Most used saber color on planet " << planet_name << " is white!" << std::endl; }
		else if (most_used_saber_color == counter_red) { std::cout << "Most used saber color on planet " << planet_name << " is red!" << std::endl; }
		else if (most_used_saber_color == counter_green) { std::cout << "Most used saber color on planet " << planet_name << " is green!" << std::endl; }
		else if (most_used_saber_color == counter_blue) { std::cout << "Most used saber color on planet " << planet_name << " is blue!" << std::endl; }
		else if (most_used_saber_color == counter_black) { std::cout << "Most used saber color on planet " << planet_name << " is black!" << std::endl; }
		else if (most_used_saber_color == 0) { std::cout << "There are no Jedies on this planet " << planet_name << "!" << std::endl; }
	}
	else {
		std::cout << "There are no Jedi with this rank!" << std::endl;
	}
}


std::istream& operator>>(std::istream& in, Planet& planet) {
	std::cout << "Enter planet name: " << std::endl;
	char name[64];
	in.getline(name, 64);
	planet.set_planetName(name);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Planet& planet) {
	out << std::endl;
	out << "Planet name: " << planet.planetName << std::endl;
	if (planet.jedaiList.get_curSize() > 0) {
		out << "Jedies in this planet: " << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < planet.jedaiList.get_curSize(); ++i) {
			std::cout << planet.jedaiList[i] << std::endl;
			std::cout << std::endl;
		}
	}
	return out;
}


void Planet::write_on_file(const char* fileName) {

	std::ofstream myFile(fileName, std::ios::app);
	myFile << "Planet:" << std::endl;
	myFile << this->get_planetName() << std::endl;
	int size = this->get_jedaiList().get_curSize();
	for (int i = 0; i < size; ++i) {
		this->jedaiList[i].write_on_file(fileName);
	}
	myFile.close();
}