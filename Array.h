#pragma once
template <class T>
class Array {
	int size;
	T* arr;
public:
	Array() {
		this->size = 0;
		this->arr = nullptr;
	}
	Array(const Array & other) {
		this->size = other.size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = other.arr[i];
	}

	int getSize()const { return this->size; }
	T * getArr() const { return this->arr; }

	const Array & operator=(const Array & other) {
		if (this != &other) {
			delete[] this->arr;
			size = other.size;
			this->arr = new T[size];
			for (int i = 0; i < size; i++)
				this->arr[i] = other.arr[i];
		}
		return *this;
	}
	const Array & operator+=(const T & newEl) {
		T * newArr = new T[this->size + 1];
		for (int i = 0; i < this->size; i++)
			newArr[i] = this->arr[i];
		newArr[this->size] = newEl;
		this->size++;
		delete[] this->arr;
		this->arr = newArr;
		return *this;
	}

	~Array() {
		delete[] this->arr;
	}
};