#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class myVector {
private:
	T* vector;
	size_t curSize;
	size_t capacity;

	void copy(const myVector&);
	void resize();
	void destroy();
	T* copyDynamic(const myVector&);

public:
	void set_curSize(const size_t);
	void set_capacity(const size_t);
	size_t get_curSize()const;
	myVector();
	myVector(const myVector&);
	myVector& operator=(const myVector&);
	~myVector();
	void addElement(const T& element);
	const T operator[](size_t index)const;
	T& operator[](size_t index);
	myVector operator+(const myVector&)const;
	myVector& operator+=(const myVector&);
	void Print()const;
	friend std::ostream& operator>>(std::ostream&, const myVector&);



};
template <typename T>
void myVector<T>::set_curSize(const size_t _curSize) {
	this->curSize = _curSize;
}

template <typename T>
void myVector<T>::set_capacity(const size_t _capacity) {
	this->capacity = _capacity;
}

template<typename T>
T* myVector<T>::copyDynamic(const myVector& other) {
	T* toReturn = new T[other.capacity];
	size_t otherCapacity = other.capacity;
	for (size_t i = 0; i < otherCapacity; ++i) {
		toReturn[i] = other.vector[i];
	}
	return toReturn;
}


template <typename T>
void myVector<T>::copy(const myVector<T>& other) {
	this->curSize = other.curSize;
	this->capacity = other.capacity;
	this->vector = copyDynamic(other);
}


template <typename T>
void myVector<T>::resize() {
	this->capacity *= 2;
	T* newVect = new T[capacity];
	for (size_t i = 0; i < this->curSize; ++i) {
		newVect[i] = this->vector[i];
	}
	
	delete[] this->vector;
	vector = newVect;
}

template<typename T>
void myVector<T>::destroy() {
	delete[] this->vector;
	this->vector = nullptr;
	this->curSize = 0;
	this->capacity = 8;
}

template <typename T>
myVector<T>::myVector() {
	this->curSize = 0;
	this->capacity = 8;
	this->vector = new T[this->capacity];
}

template <typename T>
myVector<T>::myVector(const myVector<T>& other) {
	this->copy(other);
}

template <typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& other) {
	if (this != &other) {
		this->destroy();
		this->copy(other);
	}
	return *this;
}

template <typename T>
myVector<T>::~myVector() {
	this->destroy();
}

template <typename T>
void myVector<T>::addElement(const T& element) {
	if (this->curSize == this->capacity) {
		this->resize();
	}

	this->vector[curSize] = element;
	this->curSize++;

}

template <typename T>
size_t myVector<T>::get_curSize()const {
	return this->curSize;
}

template <typename T>
const T myVector<T>::operator[](size_t index)const {
	return this->vector[index];
}

template<typename T>
T& myVector<T>::operator[](size_t index) {
	return this->vector[index];
}


template <typename T>
myVector<T> myVector<T>::operator+(const myVector& _vector)const {

	myVector newVector(*this);
	newVector += _vector;

	return newVector;
}


template <typename T>
myVector<T>& myVector<T>::operator+=(const myVector& other) {

	for (int i = 0; i < other.curSize; ++i) {
		this->addElement(other.vector[i]);
	}
	return *this;
}

template <typename T>
void myVector<T>::Print()const {
	for (size_t i = 0; i < this->curSize; ++i) {
		std::cout << this->vector[i] << std::endl;
	}
}

template <typename T>
std::ostream& operator>>(std::ostream& out, const myVector<T>& data) {
	for (int i = 0; i < data.curSize; ++i) {
		out << data.vector[i] << std::endl;
	}
	return out;
}