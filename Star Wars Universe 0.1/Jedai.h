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

Rank determinRank(const char* _rank);
Rank determinRank(const myString& _rank);

class Jedai {
private:   //private dates
	myString jedai_name;  //change jedai_name -> to myString
	Rank jedai_rank;
	size_t jedai_age;
	myString saber_color;
	double jedai_strenght;

	void copy(const Jedai&);
	//void destroy(); 

public:             //public functions
	Jedai();		//default constructor
	//~Jedai();        //destructor

	//srtters
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

	//getters

	//char* get_jedai_name()const;
	const myString& get_jedai_name()const;
	Rank get_jedai_rank()const;
	size_t get_jedai_age()const;
	const myString& get_saber_color()const;
	double get_jedai_strenght()const;
	bool chekRank()const;
	bool chekColor()const;


	//Rank determinRank(const char* _rank);
	//Rank determinRank(const myString& _rank);

	//Rank determinRank(const char* _rank);


	Jedai(const Jedai&);				                                      //copy constructor
	const Jedai& operator=(const Jedai&);                                           //overloaded operator=
	Jedai(const char*, const char*, const size_t, const char*, const double);//constructior with parameters
	Jedai(const myString&, const myString&, const int, const myString&, const double);

	friend std::istream& operator>>(std::istream& in, Jedai&);
	friend std::ostream& operator<<(std::ostream& out, const Jedai&);

	//void ReadFromFile(const char* fileName, int& position);
	void write_on_file(const char* fileName);


	//ofstream& 
//todo ofstram

};
