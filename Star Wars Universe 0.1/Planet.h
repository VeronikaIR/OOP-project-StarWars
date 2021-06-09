#pragma once
#include <iostream>
#include <cstring>
#include "Jedai.h"
#include "myVector.h"
#include "myString.h"

class Planet {
private:
	myString planetName;
	myVector<Jedai> jedaiList;

public:
	void set_planetName(const myString&);
	void set_planetName(const char*);
	void set_jedaiList(Jedai&);

	int get_sizeOfJedaiList()const;
	myVector<Jedai>& get_jedaiList();

	Planet& operator=(const Planet&);
	const myString& get_planetName()const;
	void find_most_used_saber_color(const myString& planet_name, const int counter_white, const int counter_red, const int counter_green, const int counter_blue, const int counter_black);

	void write_on_file(const char* fileName);

	friend std::istream& operator>>(std::istream& in, Planet&);
	friend std::ostream& operator<<(std::ostream& out, const Planet&);

};
