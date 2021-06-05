#include "Jedai.h"
#include <cstring>
#include <fstream>
#pragma warning(disable : 4996)

Rank determinRank(const char* _rank) {  ///da sloja vutreeee
	if (strcmp(_rank, "Youngling") == 0) {
		return Rank::Youngling;
	}
	else if (strcmp(_rank, "Initate") == 0) {
		return Rank::Initate;
	}
	else if (strcmp(_rank, "Padawan") == 0) {
		return Rank::Padawan;
	}
	else if (strcmp(_rank, "Knight_Aspirant") == 0) {
		return Rank::Knight_Aspirant;
	}
	else if (strcmp(_rank, "Knight") == 0) {
		return Rank::Knight;
	}
	else if (strcmp(_rank, "Master") == 0) {
		return Rank::Master;
	}
	else if (strcmp(_rank, "Battle_Master") == 0) {
		return Rank::Battle_Master;
	}
	else if (strcmp(_rank, "Grand_Master") == 0)
	{
		return Rank::Grand_Master;
	}
	else {
		std::cout << "Invalid rank!" << std::endl;
		exit(0);
	}
}

Rank  determinRank(const myString& _rank) {  ///da sloja vutreeee
	if (_rank == "Youngling") {
		return Rank::Youngling;
	}
	else if (_rank == "Initate") {
		return Rank::Initate;
	}
	else if (_rank == "Padawan") {
		return Rank::Padawan;
	}
	else if (_rank == "Knight_Aspirant") {
		return Rank::Knight_Aspirant;
	}
	else if (_rank == "Knight") {
		return Rank::Knight;
	}
	else if (_rank == "Master") {
		return Rank::Master;
	}
	else if (_rank == "Battle_Master") {
		return Rank::Battle_Master;
	}
	else if (_rank == "Grand_Master")
	{
		return Rank::Grand_Master;
	}
	else {
		std::cout << "Invalid rank!" << std::endl;
		exit(0);
	}
}

char* EnumToCharArray(Rank rank, char* rankType) { //da sloja vutreeeee

	if (rank == Rank::Youngling) {
		strcpy(rankType, "Youngling");

		return rankType;
	}

	else if (rank == Rank::Initate) {
		strcpy(rankType, "Initate");

		return rankType;
	}

	else if (rank == Rank::Padawan) {
		strcpy(rankType, "Padawan");

		return rankType;
	}
	else if (rank == Rank::Master) {
		strcpy(rankType, "Master");

		return rankType;
	}
	else if (rank == Rank::Knight_Aspirant) {
		strcpy(rankType, "Knight_Aspirant");
		return rankType;
	}
	else if (rank == Rank::Knight) {
		strcpy(rankType, "Kinght");
		return rankType;
	}

	else if (rank == Rank::Grand_Master) {
		strcpy(rankType, "Grand_Master");
		return rankType;
	}

	else if (rank == Rank::Battle_Master) {
		strcpy(rankType, "Battle_Master");
		return rankType;
	}

}

void Jedai::copy(const Jedai& other) {
	this->set_jedai_name(other.jedai_name);
	this->set_jedai_rank(other.jedai_rank);
	this->set_jedai_age(other.jedai_age);
	this->set_saber_color(other.saber_color);
	this->set_jedai_strenght(other.jedai_strenght);
}

/*
void Jedai::destroy() {
	//delete[] jedai_name;
	//jedai_name = nullptr;
	//delete[] saber_color;
	//saber_color = nullptr;
}
*/


Jedai::Jedai() {
	//jedai_name = nullptr;
	jedai_rank = Rank::Youngling;
	jedai_age = 0;
	//saber_color = nullptr;
	jedai_strenght = 0;
}

/*
Jedai::~Jedai()
{
	//delete[] jedai_name;
	//jedai_name = nullptr;
	//delete[] saber_color;
	// = nullptr;
}
*/

/*
void Jedai::set_jedai_name(const char* _jedai_name) {
	if (_jedai_name == nullptr)
	{
		return;
	}
	//if (this->jedai_name != nullptr) {
	//	delete[] this->jedai_name;
	//}
	this->jedai_name = new char[strlen(_jedai_name) + 1];
	strcpy(jedai_name, _jedai_name);
}
*/


void Jedai::set_jedai_name(const char* _jedai_name) {  ///???????
	this->jedai_name.set_string(_jedai_name);
}

void Jedai::set_jedai_name(const myString& _jedai_name)
{
	this->jedai_name = _jedai_name;
}

void Jedai::set_jedai_rank(const char* _rank) {
	this->jedai_rank = determinRank(_rank);
}

void Jedai::set_jedai_rank(const myString& _rank) {

	if (_rank == "Youngling") { this->jedai_rank = Rank::Youngling; }
	else if (_rank == "Initiate") { this->jedai_rank = Rank::Initate; }
	else if (_rank == "Padawan") { this->jedai_rank = Rank::Padawan; }
	else if (_rank == "Knight_Asporant") { this->jedai_rank = Rank::Knight_Aspirant; }
	else if (_rank == "Knight") { this->jedai_rank = Rank::Knight; }
	else if (_rank == "Master") { this->jedai_rank = Rank::Master; }
	else if (_rank == "Battle_Master") { this->jedai_rank = Rank::Battle_Master; }
	else { this->jedai_rank = Rank::Grand_Master; }

}

void Jedai::set_jedai_rank(const Rank _rank) {
	this->jedai_rank = _rank;
}

void Jedai::set_jedai_rank(const int number) {
	if (number == 0) { this->jedai_rank = Rank::Youngling; }
	else if (number == 1) { this->jedai_rank = Rank::Initate; }
	else if (number == 2) { this->jedai_rank = Rank::Padawan; }
	else if (number == 3) { this->jedai_rank = Rank::Knight_Aspirant; }
	else if (number == 4) { this->jedai_rank = Rank::Knight; }
	else if (number == 5) { this->jedai_rank = Rank::Master; }
	else if (number == 6) { this->jedai_rank = Rank::Battle_Master; }
	else if (number == 7) { this->jedai_rank = Rank::Grand_Master; }
	else { std::cout << "Invalid rank!" << std::endl; }

}

void Jedai::set_jedai_age(const size_t _jedai_age) {
	this->jedai_age = _jedai_age;
}

void Jedai::set_saber_color(const char* _saber_color) {

	this->saber_color.set_string(_saber_color);
}

void Jedai::set_saber_color(const myString& _saber_color) {
	this->saber_color = _saber_color;
}

void Jedai::set_jedai_strenght(const double _jedai_strenght) {
	this->jedai_strenght = _jedai_strenght;

}

/*
char* Jedai::get_jedai_name()const {
	return this->jedai_name;
}
*/

const myString& Jedai::get_jedai_name()const {
	return this->jedai_name;
}

Rank Jedai::get_jedai_rank()const {
	return this->jedai_rank;
}

size_t Jedai::get_jedai_age()const {
	return  this->jedai_age;
}

const myString& Jedai::get_saber_color()const {
	return this->saber_color;
}

double Jedai::get_jedai_strenght()const {
	return this->jedai_strenght;
}

Jedai::Jedai(const Jedai& other) {
	this->copy(other);
}

const Jedai& Jedai:: operator=(const Jedai& other) {
	if (this != &other) {
		//this->destroy();
		this->copy(other);
	}
	return *this;
}

Jedai::Jedai(const char* _name, const char* _rank, const size_t _age, const char* _color, const double _strenght) {

	this->set_jedai_name(_name);
	this->set_jedai_rank(_rank);
	this->set_jedai_age(_age);
	this->set_saber_color(_color);
	this->set_jedai_strenght(_strenght);
}

Jedai::Jedai(const myString& _name, const myString& _rank, const int _age, const myString& _color, const double _strenght) {

	this->set_jedai_name(_name);
	this->set_jedai_rank(_rank);
	this->set_jedai_age(_age);
	this->set_saber_color(_color);
	this->set_jedai_strenght(_strenght);

}

bool Jedai::chekRank()const {

	if (!(this->get_jedai_rank() == Rank::Youngling || this->get_jedai_rank() == Rank::Initate || this->get_jedai_rank() == Rank::Padawan || this->get_jedai_rank() == Rank::Knight_Aspirant || this->get_jedai_rank() == Rank::Knight || this->get_jedai_rank() == Rank::Master || this->get_jedai_rank() == Rank::Battle_Master || this->get_jedai_rank() == Rank::Grand_Master)) {
		return false;
	}

	return true;
}

bool Jedai::chekColor()const {
	if (!(this->get_saber_color() == "Red" || this->get_saber_color() == "White" || this->get_saber_color() == "Green" || this->get_saber_color() == "Blue" || this->get_saber_color() == "Black")) {
		return false;
	}
	else return true;
}


std::istream& operator>>(std::istream& in, Jedai& jedai) {
	std::cout << "Enter the name of the Jedai : " << std::endl;
	char name[32];
	in >> name;
	jedai.set_jedai_name(name);


	std::cout << "Enter the rank of the Jedai (choose one of them: Youngling, Initate, Padawan, Knight_Aspirant, Kinght, Master, Battle_Master or Grand_Master) : " << std::endl;
	char jediRank[32];
	in >> jediRank;
	jedai.set_jedai_rank(jediRank);

	std::cout << "Enter the age of the Jedai (age must be positive integer): " << std::endl;
	size_t jediAge;
	in >> jediAge;
	jedai.set_jedai_age(jediAge);

	std::cout << "Enter the color of the lightsaber (choose one of them: White, Red, Green, Blue or Black): " << std::endl;
	char saberColor[32];
	in >> saberColor;
	jedai.set_saber_color(saberColor);

	std::cout << "Enter Jedai's strength (strength must be real number) : " << std::endl;
	double jediStrength;
	in >> jediStrength;
	//if(strength != real number)
	jedai.set_jedai_strenght(jediStrength);

	return in;

}

std::ostream& operator<<(std::ostream& out, const Jedai& other) {

	out << "Jedi's name: " << other.get_jedai_name() << std::endl;
	out << "Jedi's rank: ";
	switch (other.jedai_rank) {
	case Rank::Youngling:out << "Youngling" << std::endl; break;
	case Rank::Initate:out << "Initate" << std::endl; break;
	case Rank::Padawan:out << "Padawan " << std::endl; break;
	case Rank::Knight_Aspirant:out << "Kight_Aspirant" << std::endl; break;
	case Rank::Knight:out << "Kinght" << std::endl; break;
	case Rank::Master:out << "Master" << std::endl; break;
	case Rank::Battle_Master:out << "Battle_Master" << std::endl; break;
	case Rank::Grand_Master:out << "Grand_Master" << std::endl; break;
	}
	out << "Jedi's age: " << other.get_jedai_age() << std::endl;
	out << "Jedi's saber color: " << other.get_saber_color() << std::endl;
	out << "Jedi's strenght: " << other.get_jedai_strenght();

	return out;
}

void Jedai::write_on_file(const char* fileName) {

	std::ofstream myFile(fileName, std::ios::app);
	myFile << "Jedi:" << std::endl;
	myFile << this->get_jedai_name() << std::endl;

	char* rankType = new char[32];
	rankType = EnumToCharArray(this->get_jedai_rank(), rankType);
	myFile << rankType << std::endl;

	myFile << this->get_jedai_age() << std::endl;
	myFile << this->get_saber_color() << std::endl;
	myFile << this->get_jedai_strenght() << std::endl;
	myFile << std::endl;

	delete[]rankType;
	myFile.close();
}
