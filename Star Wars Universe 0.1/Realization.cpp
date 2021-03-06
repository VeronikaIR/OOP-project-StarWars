#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdexcept>
#include "Realization.h"


myVector<Jedai>& sort_lexicographically(myVector<Jedai>& jediList) {

	Jedai temp;

	for (int i = 0; i < jediList.get_curSize(); ++i) {
		for (int p = 0; p < jediList.get_curSize() - i - 1; ++p) {
			int q = p + 1;
			if (jediList[p].get_jedai_name() > jediList[q].get_jedai_name()) {
				temp = jediList[p];
				jediList[p] = jediList[q];
				jediList[q] = temp;
			}
		}
	}

	return jediList;
}

void Realize::startUp() {

	bool isOpend = false;
	myString fileTosave;

	while (true) {

		std::cout << "Type function: " << std::endl;
		myString input;
		std::cin >> input;

		myVector<myString> arg;
		arg = input.split(' ');
		myString command = arg[0];

		if (command == "add_planet" && isOpend) {
			myString planet_name = arg[1];
			
			bool is_Exist_Planet_With_This_Name = chekPlanetName(planet_name);

			if (planet_name.chekString() && !(is_Exist_Planet_With_This_Name)) {
				Planet curPlanet;
				curPlanet.set_planetName(planet_name);
				planets.addElement(curPlanet);

				std::cout << "Planet " << arg[1] << " successfully added!" << std::endl;
			}
			else {
				std::cout << "Exist planet with this name or invalid planet name!" << std::endl;
			}
		}

		//create jedi
		else if (command == "create_jedi" && isOpend) {

			bool cheker = true;

			myString planet_name = arg[1];
			myString _jedai_name = arg[2];
			myString _jedai_rank = arg[3];
			int _jedai_age = -1;
			if (arg[4].isDigitInt()) {_jedai_age = arg[4].toInt();}
			myString _saber_color = arg[5];
			double _jedai_strenght = -1;
			if (arg[6].isDigit()) {_jedai_strenght = atof(arg[6].get_string());}

			Jedai curJedi(_jedai_name, _jedai_rank, _jedai_age, _saber_color, _jedai_strenght);

			if (curJedi.validateJedi() && planets.get_curSize() > 0){

			bool is_Exist_Jedi_With_This_Name = chekJediName(curJedi.get_jedai_name());

			bool is_Exist_Planet_With_This_Name = chekPlanetName(planet_name);

			if ((is_Exist_Jedi_With_This_Name == false) && (is_Exist_Planet_With_This_Name == true)) {
				std::cout << "Jedi " << _jedai_name << " was added successfully! " << std::endl;
				for (size_t i = 0; i < planets.get_curSize(); ++i) {
					if (planets[i].get_planetName() == planet_name) {
						planets[i].set_jedaiList(curJedi);
					}
				}
			}
			else {
				if ((is_Exist_Jedi_With_This_Name == true) && (is_Exist_Planet_With_This_Name == false)) {
					std::cout << "Jedi " << _jedai_name << " was added unsuccessfully! There is already a jedi with that name and there is no planet with that name (" << planet_name << ")!" << std::endl;
					std::cout << "Add jedi and planet with different name!" << std::endl;

				}
				else if (is_Exist_Jedi_With_This_Name == true) {
					std::cout << "There is already a jedi with that name (" << _jedai_name << ")! Add jedi with different name!" << std::endl;
				}
				else if (is_Exist_Planet_With_This_Name == false) {
					std::cout << "There is no planet with that name (" << planet_name << ")! Add planet with different name!" << std::endl;
				}
			}

		   }
			else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }
		}

		//remove_jedi
		else if (command == "removeJedi" && isOpend) {


			myString _jedai_name = arg[1];
			myString _planet_name = arg[2];

			bool is_Exist_Planet_With_This_Name = chekPlanetName(_planet_name);

			if (is_Exist_Planet_With_This_Name && planets.get_curSize() > 0) {

				bool is_Exist_Jedi_With_This_Name_On_This_Planet = false;

				for (int i = 0; i < planets.get_curSize(); ++i) {
					if (planets[i].get_planetName() == _planet_name) {

						myVector<Jedai> new_jedaiList;

						for (int p = 0; p < planets[i].get_sizeOfJedaiList(); ++p) {
							if (planets[i].get_jedaiList()[p].get_jedai_name() == _jedai_name) {
								is_Exist_Jedi_With_This_Name_On_This_Planet = true;
								continue;
							}

							new_jedaiList.addElement(planets[i].get_jedaiList()[p]);
						}

						planets[i].get_jedaiList() = new_jedaiList;
					}

				}

				if (is_Exist_Jedi_With_This_Name_On_This_Planet) {
					std::cout << "Jedi " << _jedai_name << " was removed successfully!" << std::endl;
				}
				else {
					std::cout << "There is no jedi with such a name (" << _jedai_name << ") on " << _planet_name << "!" << std::endl;
				}
			}
			else { std::cout << "Empty planet list or invalid arguments!"; }


		} //end of remove jedi

		//promote_jedi
		else if (command == "promote_jedi" && isOpend) {

			myString _jedai_name = arg[1];
			double multiplayer = atof(arg[2].get_string());

			bool is_Exist_Jedi_With_This_Name = chekJediName(_jedai_name);
			
			if (multiplayer > 0 && is_Exist_Jedi_With_This_Name && planets.get_curSize() > 0) {
				for (int i = 0; i < planets.get_curSize(); ++i) {
					for (int p = 0; p < planets[i].get_sizeOfJedaiList(); ++p) {
						if (planets[i].get_jedaiList()[p].get_jedai_name() == _jedai_name)
						{
							double newStrenght = planets[i].get_jedaiList()[p].get_jedai_strenght() + (multiplayer * planets[i].get_jedaiList()[p].get_jedai_strenght());
							planets[i].get_jedaiList()[p].set_jedai_strenght(newStrenght);

							if (planets[i].get_jedaiList()[p].get_jedai_rank() != Rank::Grand_Master) {
								planets[i].get_jedaiList()[p].set_jedai_rank(int(planets[i].get_jedaiList()[p].get_jedai_rank()) + 1);
	
							}
							std::cout << _jedai_name << " has been promoted successfully !" << std::endl;
						}
					}
				}
			}
			else {
				std::cout << "Empty planet list or invalid arguments!" << std::endl;
			}
		} //end of promote jedi


		//demoteJedi
		else if (command == "demote_jedi" && isOpend) {

			myString _jedai_name = arg[1];
			double multiplayer = atof(arg[2].get_string());
			
			bool is_Exist_Jedi_With_This_Name = chekJediName(_jedai_name);

			if (multiplayer > 0 && is_Exist_Jedi_With_This_Name && planets.get_curSize() > 0) {
	
				for (int i = 0; i < planets.get_curSize(); ++i) {
					for (int p = 0; p < planets[i].get_sizeOfJedaiList(); ++p) {
						if (planets[i].get_jedaiList()[p].get_jedai_name() == _jedai_name)
						{
							double newStrenght = planets[i].get_jedaiList()[p].get_jedai_strenght() - (multiplayer * planets[i].get_jedaiList()[p].get_jedai_strenght());
							if (newStrenght >= 0.0) {
								planets[i].get_jedaiList()[p].set_jedai_strenght(newStrenght);
							}
							else {
								planets[i].get_jedaiList()[p].set_jedai_strenght(0.0);
							}
							if (planets[i].get_jedaiList()[p].get_jedai_rank() != Rank::Youngling) {
								planets[i].get_jedaiList()[p].set_jedai_rank(int(planets[i].get_jedaiList()[p].get_jedai_rank()) - 1);
							}
							std::cout << _jedai_name << " has been demoted successfully !" << std::endl;
						}
					}
				}
			}
			else {
				std::cout << "Empty planet list or invalid arguments!" << std::endl;
			}


		}//end of demote jedi

				//get_strongest_jedi
		else if (command == "get_strongest_jedi" && isOpend) {

			myString planet_name = arg[1];

			bool is_Exist_Planet_With_This_Name = chekPlanetName(planet_name);

			if (is_Exist_Planet_With_This_Name) {

				double curBest = 0;
				int indexOfCurBest = 0;
				int indexOfPlanets = 0;
				bool flag = false;

				for (int i = 0; i < planets.get_curSize(); ++i) {
					if (planets[i].get_planetName() == planet_name) {
						indexOfPlanets = i;
						size_t size = planets[i].get_jedaiList().get_curSize();
						if (size > 0) {
							for (int p = 0; p < size; ++p) {
								if (p == 0) {
									curBest = planets[i].get_jedaiList()[p].get_jedai_strenght();
									indexOfCurBest = p;
									flag = true;
								}
								else {
									if (planets[i].get_jedaiList()[p].get_jedai_strenght() > curBest) {
										curBest = planets[i].get_jedaiList()[p].get_jedai_strenght();
										indexOfCurBest = p;
										flag = true;
									}
								}
							}
						}
						else { std::cout << "Empty jedi list!" << std::endl; }
					}
				}
				if (flag) {
					std::cout << "Strongest jedi on " << planet_name << " is: " << std::endl;
					std::cout << planets[indexOfPlanets].get_jedaiList()[indexOfCurBest] << std::endl;
				}
			}
			else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }

		}//end of get_strongest_jedi


				//get_youngest_jedi

		else if (command == "get_youngest_jedi" && isOpend) {

			myString planet_name = arg[1];
			myString jedi_rank = arg[2];

			bool is_Exist_Planet_With_This_Name = chekPlanetName(planet_name);
			bool chekRank = (jedi_rank == "Youngling" || jedi_rank == "Initiate" || jedi_rank == "Padawan" || jedi_rank == "Knight_Aspirant" || jedi_rank == "Knight" || jedi_rank == "Master" || jedi_rank == "Battle_Master" || jedi_rank == "Grand_Master");
			
			if (is_Exist_Planet_With_This_Name && chekRank) {

				size_t min_age = INT_MAX;

				for (int i = 0; i < planets.get_curSize(); ++i) {
					if (planets[i].get_planetName() == planet_name) {
						if (planets[i].get_jedaiList().get_curSize() > 0) {
							for (int p = 0; p < planets[i].get_jedaiList().get_curSize(); ++p) {
								if (planets[i].get_jedaiList()[p].getRankChar() == jedi_rank) {
									if (min_age >= planets[i].get_jedaiList()[p].get_jedai_age()) {
										min_age = planets[i].get_jedaiList()[p].get_jedai_age();
									}
								}
							}
						}
						else {
							std::cout << "There are no jedies on " << planet_name << " !" << std::endl;
						}
						break;
					}
				}
				myVector<Jedai> youngest_jedies;

				bool flag = false;

				for (int i = 0; i < planets.get_curSize(); ++i) {
					if (planets[i].get_planetName() == planet_name) {
						for (int p = 0; p < planets[i].get_jedaiList().get_curSize(); ++p) {
							if ((planets[i].get_jedaiList()[p].getRankChar() == jedi_rank) && planets[i].get_jedaiList()[p].get_jedai_age() == min_age) {
								youngest_jedies.addElement(planets[i].get_jedaiList()[p]);
								flag = true;
							}
						}
						break;
					}
				}
				//Jedai temp;

				youngest_jedies = sort_lexicographically(youngest_jedies);
				if (flag) {
					std::cout << "Youngest jedi on planet " << planet_name << " is:" << std::endl;
					std::cout << youngest_jedies[youngest_jedies.get_curSize() - 1] << std::endl;
				}
			}
			else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }

		}//end of get_youngest_jedi

	
	   //get_most_used_saber_color(const char* planet_name, const char* jedi_rank)
		else if (command == "get_most_used_saber_color" && isOpend) {

			myString planet_name = arg[1];
	
			bool is_Exist_Planet_With_This_Name = chekPlanetName(planet_name);

			int counter_white = 0;
			int counter_red = 0;
			int counter_green = 0;
			int counter_blue = 0;
			int counter_black = 0;

			if (arg.get_curSize() == 3) {

				myString jedi_rank = arg[2];

				
			 bool chekRank = (jedi_rank == "Youngling" || jedi_rank == "Initiate" || jedi_rank == "Padawan" || jedi_rank == "Knight_Aspirant" || jedi_rank == "Knight" || jedi_rank == "Master" || jedi_rank == "Battle_Master" || jedi_rank == "Grand_Master");

				if (is_Exist_Planet_With_This_Name && chekRank) {
					Planet curPlanet;

					for (int i = 0; i < planets.get_curSize(); ++i) {
						if (planets[i].get_planetName() == planet_name) {
							curPlanet = planets[i];
							for (int p = 0; p < planets[i].get_jedaiList().get_curSize(); ++p) {
								if (planets[i].get_jedaiList()[p].getRankChar() == jedi_rank) {
									if (planets[i].get_jedaiList()[p].get_saber_color() == "White") {
										counter_white++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Red") {
										counter_red++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Green") {
										counter_green++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Blue") {
										counter_blue++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Black") {
										counter_black++;
									}
								}
							}
						}
					}
					curPlanet.find_most_used_saber_color(planet_name, counter_white, counter_red, counter_green, counter_blue, counter_black);
				}
				else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }
			}
			
			else {
				if (is_Exist_Planet_With_This_Name && planets.get_curSize() > 0) {

					Planet curPlanet;

					for (int i = 0; i < planets.get_curSize(); ++i) {
						if (planets[i].get_planetName() == planet_name) {
							curPlanet = planets[i];
							for (int p = 0; p < planets[i].get_jedaiList().get_curSize(); ++p) {
								if (planets[i].get_jedaiList()[p].get_jedai_rank() == Rank::Grand_Master) {
									if (planets[i].get_jedaiList()[p].get_saber_color() == "White") {
										counter_white++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Red") {
										counter_red++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Green") {
										counter_green++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Blue") {
										counter_blue++;
									}
									else if (planets[i].get_jedaiList()[p].get_saber_color() == "Black") {
										counter_black++;
									}
								}
							}
						}
					}
					curPlanet.find_most_used_saber_color(planet_name, counter_white, counter_red, counter_green, counter_blue, counter_black);
				}
				else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }
				}
			
		}//end of get_most_used_saber_color


		else if (command == "print_planet" && isOpend) {
			myString planet_name = arg[1];

			myVector<Jedai> newSorted_jedaiList;

			bool is_Exist_Planet_With_This_Name = chekPlanetName(planet_name);

			if (is_Exist_Planet_With_This_Name) {

				for (int i = 0; i < planets.get_curSize(); ++i) {
					if (planets[i].get_planetName() == planet_name) {
						for (int q = 7; q >= 0; --q) {
							myVector<Jedai> currList;
							for (int p = 0; p < planets[i].get_jedaiList().get_curSize(); ++p) {

								if (int(planets[i].get_jedaiList()[p].get_jedai_rank()) == q) {
									currList.addElement(planets[i].get_jedaiList()[p]);
								}

							}
							currList = sort_lexicographically(currList);
							newSorted_jedaiList += currList;
						}
					}
				}
					std::cout << "PLanet " << planet_name << ":" << std::endl;
					std::cout << std::endl;
					for (int i = newSorted_jedaiList.get_curSize() - 1; i >= 0; --i) {
						std::cout << newSorted_jedaiList[i] << std::endl;
						std::cout << std::endl;
					}
			}
			else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }
		}//end of print planets


				//print jedi
		else if (command == "print_jedi" && isOpend) {

			myString jedai_name = arg[1];

			bool is_Exist_Jedi_With_This_Name = chekJediName(jedai_name);

			if (is_Exist_Jedi_With_This_Name) {

				for (int i = 0; i < planets.get_curSize(); ++i) {
					for (int p = 0; p < planets[i].get_sizeOfJedaiList(); ++p) {
						if (planets[i].get_jedaiList()[p].get_jedai_name() == jedai_name) {
							std::cout << planets[i].get_jedaiList()[p] << std::endl;
							std::cout << "Jedi's planet: " << planets[i].get_planetName() << std::endl;
							std::cout << std::endl;
							//return;
						}
					}
				}
			}
			else { std::cout << "Empty planet list or invalid arguments!" << std::endl; }

		}//end of print jedi

		else if (command == "open" && !isOpend) {

			if (isOpend) {
				std::cout << "File is opened!" << std::endl;
				continue;
			}
			isOpend = true;
			fileTosave = arg[1];
			read_from_file(fileTosave);
			std::cout << "File is opened!" << std::endl;
		}

		else if (command == "close" && isOpend) {
			planets.~myVector();

			myVector<Planet> newVect;
			this->planets = newVect;

			fileTosave.~myString();
			isOpend = false;
			std::cout << "File is closed!" << std::endl;
		}

		else if (command == "save" && isOpend) {
			write_on_file(fileTosave);
			std::cout << "File is saved!" << std::endl;
		}


		else if (command == "save_as" && isOpend) {
			myString directory = arg[1];
			write_on_file(directory);
			std::cout << "File is saved on " << directory << " directory!" << std::endl;
		}


		else if (command == "help") {
			std::cout << "This project supports the following commands:" << std::endl;
			std::cout << "add_planet <planet_name>" << std::endl;
			std::cout << "create_jedi <planet_name> <jedi_name> <jedi_rank> <jedi_age> <saber_color>(choose one of them: White, Red, Green, Blue, Black) <jedi_strength>" << std::endl;
			std::cout << "removeJedi <jedi_name> <planet_name>" << std::endl;
			std::cout << "promote_jedi <jedi_name> <multiplier>" << std::endl;
			std::cout << "demote_jedi <jedi_name> <multiplier>" << std::endl;
			std::cout << "get_strongest_jedi    <planet_name>" << std::endl;
			std::cout << "get_youngest_jedi <planet_name> <jedi_rank>" << std::endl;
			std::cout << "get_most_used_saber_color <planet_name> <jedi_rank>" << std::endl;
			std::cout << "get_most_used_saber_color <planet_name>" << std::endl;
			std::cout << "print_planet <planet_name>" << std::endl;
			std::cout << "print_jedi <jedi_name>" << std::endl;
			std::cout << "<planet_name> + <planet_name>" << std::endl;

		}

		else if (command == "exit") {
			exit(0);
		}

		else {

			myString symbol = arg[1];
			myString planetName2 = arg[2];

			if (symbol == "+") {

				bool isExistPlanetName1 = chekPlanetName(command);
				bool isExistPlanetName2 = chekPlanetName(planetName2);

				if (isExistPlanetName1 && isExistPlanetName2) {

					myVector<Jedai> newSortedJediList;

					for (int i = 0; i < planets.get_curSize(); ++i) {
						if ((planets[i].get_planetName() == command) || (planets[i].get_planetName() == planetName2)) {
							for (int p = 0; p < planets[i].get_jedaiList().get_curSize(); p++)
								newSortedJediList.addElement(planets[i].get_jedaiList()[p]);
						}
					}
					Jedai temp;

					newSortedJediList = sort_lexicographically(newSortedJediList);

					for (int i = newSortedJediList.get_curSize() - 1; i >= 0; --i) {
						std::cout << newSortedJediList[i] << std::endl;
						std::cout << std::endl;
					}

				}
				else {
					std::cout << "Invalid planet names!" << std::endl;
				}

			}//if +

			else {
				std::cout << "Invalid command!" << std::endl;
			}


		}//else

	} //while true

}//void startup


void Realize::write_on_file(const myString& fileName) {
	size_t newLength = fileName.get_string_size();
	char* fileNameCharArr = new char[newLength + 1];

	for (int i = 0; i < newLength; ++i) {
		fileNameCharArr[i] = fileName[i];
	}

	fileNameCharArr[newLength] = '\0';

	std::ofstream myFile(fileNameCharArr, std::ios::out | std::ios::trunc);

	if (planets.get_curSize() == 0) {
		return;
	}

	size_t size = planets.get_curSize();
	for (int i = 0; i < size; ++i) {
		this->planets[i].write_on_file(fileNameCharArr);
	}
	myFile.close();

	delete[] fileNameCharArr;

}


void Realize::read_from_file(const myString& fileName) { //mystring

	std::ifstream input;
	bool fileExist = false;
	size_t newLength = fileName.get_string_size();
	char* fileNameCharArr = new char[newLength + 1];

	for (int i = 0; i < newLength; ++i) {
		fileNameCharArr[i] = fileName[i];
	}
	fileNameCharArr[newLength] = '\0';

	input.open(fileNameCharArr);
	char buffer[64];

	while (input.getline(buffer, 64, '\n')) //zarejdam inf
	{
		input.getline(buffer, 64, '\n');
		Planet p;
		p.set_planetName(buffer);

		while (input.getline(buffer, 64, '\n')) {
			if (!strcmp(buffer, "Jedi:")) {

				Jedai jedi;
				int i = 0;
				while (input.getline(buffer, 64, '\n')) {
					if (i == 0) { jedi.set_jedai_name(buffer); i++; }
					else if (i == 1) { jedi.set_jedai_rank(buffer); i++; }
					else if (i == 2) { jedi.set_jedai_age(atoi(buffer));  i++; }
					else if (i == 3) { jedi.set_saber_color(buffer);  i++; }
					else if (i == 4) { jedi.set_jedai_strenght(atof(buffer)); }
				}
				p.set_jedaiList(jedi);
			}
			else { break; }
		}

		planets.addElement(p);
	}

	input.close();
	delete[] fileNameCharArr;

	if (!fileExist) {
		write_on_file(fileName);
	}

}

bool Realize:: chekJediName(const myString& jediName) {
	
	bool is_Exist_Jedi_With_This_Name = false;

	for (int i = 0; i < this->get_planetsSize(); ++i) {
		for (int p = 0; p < planets[i].get_sizeOfJedaiList(); ++p) {
			if (planets[i].get_jedaiList()[p].get_jedai_name() == jediName) {
				is_Exist_Jedi_With_This_Name = true;
				break;
			}
		}
	}
	return is_Exist_Jedi_With_This_Name;
}

bool Realize::chekPlanetName(const myString& planet_name) {
	bool is_Exist_Planet_With_This_Name = false;

	for (size_t i = 0; i < this->get_planetsSize(); ++i) {
		if (planets[i].get_planetName() == planet_name) {
			is_Exist_Planet_With_This_Name = true;
			break;
		}
	}
	return is_Exist_Planet_With_This_Name;
}

size_t Realize::get_planetsSize()const {
	return this->planets.get_curSize();
}

myString convertAllLettersToSmall(myString string) {

	myString newString;

	for (int i = 0; i < string.get_string_size(); ++i) {
		if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')) {
			if (string[i] >= 'A' && string[i] <= 'Z') {
				string[i] -= 'A' - 'a';
			}
			newString.addElement(string[i]);
		}
	}
	return newString;
}