#pragma once
#include <iostream>
#include <cstring>
#include "myString.h"


enum class Rank {
	Youngling,
	Initate,
	Padawan,
	Knight_Aspirant,
	Knight,
	Master,
	Battle_Master,
	Grand_Master
};

class Jedai {
private:  
	myString jedai_name;
	Rank jedai_rank;
	size_t jedai_age;
	myString saber_color;
	double jedai_strenght;

	void copy(const Jedai&);

public:
	Jedai();		
	void set_jedai_name(const char*);
	void set_jedai_name(const myString&);
	void set_jedai_rank(const char*);
	void set_jedai_rank(const Rank);
	void set_jedai_rank(const myString&);
	void set_jedai_rank(const int);
	void set_jedai_age(const size_t);
	void set_saber_color(const char*);
	void set_saber_color(const myString&);
	void set_jedai_strenght(const double);

	const myString& get_jedai_name()const;
	Rank get_jedai_rank()const;
	size_t get_jedai_age()const;
	const myString& get_saber_color()const;
	double get_jedai_strenght()const;
	bool chekRank()const;
	bool chekColor()const;
	myString getRankChar()const;
	Rank determinRank(const char* _rank);
	Rank determinRank(const myString& _rank);
	Jedai(const Jedai&);
	const Jedai& operator=(const Jedai&);
	Jedai(const char*, const char*, const size_t, const char*, const double);
	Jedai(const myString&, const myString&, const int, const myString&, const double);

	bool validateJedi();

	friend std::istream& operator>>(std::istream& in, Jedai&);
	friend std::ostream& operator<<(std::ostream& out, const Jedai&);
	void write_on_file(const char* fileName);

};
