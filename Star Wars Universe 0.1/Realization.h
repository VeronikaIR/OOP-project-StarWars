#pragma once
#include <iostream>
#include "Jedai.h"
#include "Planet.h"
#include "myVector.h"
#include "myString.h"
#pragma warning(disable:4996)

class Realize {
private:
	myVector<Planet> planets;

public:

	void startUp();

	size_t get_planetsSize()const;

	void read_from_file(const myString& fileName);
	void write_on_file(const myString& fileName);

	bool chekJediName(const myString&);
	bool chekPlanetName(const myString&);

};
