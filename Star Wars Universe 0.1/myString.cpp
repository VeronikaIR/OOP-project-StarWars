#include <iostream>
#include "myString.h"
#pragma warning(disable:4996)

void myString::destroy() {
	delete[] this->string;
	this->string = nullptr;
}

void myString::resize() {
	this->string_capacity *= 2;
	char* newString = new char[string_capacity + 1];
	for (size_t i = 0; i < string_size; ++i) {
		newString[i] = this->string[i];
	}
	this->destroy();
	string = newString;
}

void myString::copy(const myString& other) {
	this->string_size = other.string_size;
	this->string_capacity = other.string_capacity;
	//delete[] this->string;
	this->string = new char[this->string_capacity + 1];
	for (int i = 0; i < this->string_size; i++)
	{
		this->string[i] = other.string[i];
	}
}

void myString::set_string(const char* _string) {
	this->destroy();
	this->string = new char[strlen(_string) + 1];
	strcpy(this->string, _string);
	this->string_size = strlen(_string);
}

//???
/*
void myString::set_string_capacity(const size_t _capacity) {
	this->string_capacity = _capacity;
}
*/

char* myString::get_string()const {
	return this->string;
}

int myString::get_string_size()const {
	return this->string_size;
}

/*
size_t myString::get_string_capacity()const {
	return this->string_capacity;
}
*/

myString::myString() {
	this->string = nullptr;
	this->string_size = 0;
	this->string_capacity = 8; //???
}


myString::myString(const myString& other) {
	this->copy(other);
}

myString& myString::operator=(const myString& other) {
	if (this != &other) {
		this->destroy();
		this->copy(other);
	}
	return *this;
}

myString::~myString() {
	this->destroy();
}

const char myString::operator[](const size_t index)const {
	return this->string[index];
}

char& myString::operator[](const size_t index) {
	return this->string[index];
}

void myString::addElement(const char& x) {
	if (string_size >= string_capacity) {
		while (string_size >= string_capacity) {
			this->resize();
		}
	}
	if (this->string == nullptr) {
		this->string = new char[this->string_capacity];
	}

	this->string[string_size] = x;
	this->string_size++;
}

void myString::addCharArr(const char* array) {
	int prevSize = this->string_size;
	int newSize = prevSize + strlen(array);

	if (newSize >= this->string_capacity) {
		while (newSize >= string_capacity) {
			this->resize();
		}
	}
	int j = 0;
	for (int i = prevSize; i < newSize; ++i) {
		this->string[i] = array[j];
		j++;
	}
	this->string_size = newSize;
}


void myString::concatStrings(const myString& _string) {
	int prevSize = this->get_string_size();
	int newSize = prevSize + _string.get_string_size();

	if (newSize >= this->string_capacity) {
		while (newSize >= string_capacity) {
			this->resize();
		}
	}
	int j = 0;
	for (int i = prevSize; i < newSize; ++i) {
		this->string[i] = _string[j];
		j++;
	}
	this->string_size = newSize;
}

myString myString::convertAllLettersToSmall(myString& string) {
	int i = 0;
	while (string[i] != '\0') {
		if (string[i] >= 'A' && string[i] <= 'Z') {
			string[i] -= 'A' - 'a';
		}
		i++;
	}
	return string;
}

bool myString::operator>(const myString& other)const {

	int i = 0;
	if (other.string != nullptr) {
		while (this->string[i] != '\0' && other.string[i] != '\0') {
			if (this->string[i] != other.string[i]) {
				if (this->string[i] >= other.string[i]) {
					return false;
				}
				else {
					return true;
				}
			}
			i++;
		}
		if (this->string_size > other.string_size) {
			return false;
		}
		return true;
	}
}

bool myString::operator==(const myString& st2)const {

	if (this->string_size == st2.get_string_size()) {
		int i = 0;

		while (i < this->string_size) {
			if (this->string[i] != st2[i]) {
				return false;
			}
			++i;
		}

		return true;
	}
	else {
		return false;
	}
}

bool myString::operator==(const char* arr)const {
	if (this->string_size == strlen(arr)) {
		int i = 0;

		while (i < this->string_size) {
			if (this->string[i] != arr[i]) {
				return false;
			}
			++i;
		}
		return true;
	}
	else {
		return false;
	}
}


int countParts(const myString& str, const char& symbol) {

	int countWS = 0;
	int i = 0;

	while (i != str.get_string_size()) {
		if (str[i] == symbol) {
			countWS++;
		}
		i++;
	}
	return countWS;

}

myVector<myString> myString::split(const char& symbol) {

	int i = 0;
	int countSpaces = countParts(*this, symbol);  //counter for spaces

	myVector<myString> vector;

	int j = 0;

	for (i = 0; i < countSpaces + 1; i++) {
		myString currString;

		while (this->string[j] != symbol && this->string[j] != '\0') {

			currString.addElement(this->string[j]);
			j++;
		}
		vector.addElement(currString);
		j++;
	}

	return vector;

}

int myString::toInt() {
	
	bool flag = true;

	int size = this->get_string_size();
	for (int i = 0; i < size; ++i) {
		if (this->string[i] >= '0' && this->string[i] <= '9') { continue; }
		else {
			flag =false;
		}
	}
	
	if (flag) {
		int result = 0;

		for (int i = 0; i < this->string_size && (this->string[i] >= '0' && this->string[i] <= '9'); ++i) {
			int currDigit = this->string[i] - '0';
			result = currDigit + result * 10;
		}
		return result;
	}
	else { std::cout << "Invalid number!" << std::endl; exit(0); }
}


bool myString::chekString()const {
	int curSize = this->get_string_size();

	for (int i = 0; i < curSize; ++i) {
		if ((this->string[i] >= 'A' && this->string[i] <= 'Z') || (this->string[i] >= 'a' && this->string[i] <= 'z') || (this->string[i] == '-')) {}
		else {
			return false;
		}
	}
	return true;
}


bool myString::isDigit()const {
	int counter = 0;
	int size = this->get_string_size();
	for (int i = 0; i < size; ++i) {
		if ((this->string[i] >= '0' && this->string[i] <= '9') || this->string[i] == '.') { if (this->string[i] == '.') { counter++; } }
		else {
			return false;
		}
	}
	if (counter <= 1) {
		return true;
	}
	else {
		return false;
	}
}

std::istream& operator>>(std::istream& in, myString& _string) {
	std::cout << "Enter your string: " << std::endl;
	char buff[64];
	in.getline(buff, 64);
	_string.set_string(buff);

	return in;
}

std::ostream& operator<<(std::ostream& out, const myString& _string) {
	for (int i = 0; i < _string.string_size; ++i) {
		out << _string.string[i];
	}
	return out;
}
