#ifndef _ARRAY_H
#define _ARRAY_H

//class T as to have copy c`tor
//class T as to have operator=

template<class T>
class Array
{
private:
	int phySize, logSize;
	char delimiter;
	T * arr;

	void myRealloc(int size);

public:
	Array(int size = 1, char delimiter = ' ');
	Array(const Array & copy);
	Array(Array && move);
	~Array();

	//getters 
	int getLogSize() const { return this->logSize; }
	int getPhySize() const { return this->phySize; }
	char getDelimiter() const { return this->delimiter; }

	const Array& operator=(const Array & other);
	const Array& operator=(Array && other);
	const Array& operator+=(const T & value);

	friend ostream& operator<<(ostream & os, const Array& arr)
	{
		for (int i = 0; i < arr.getLogSize(); i++)
		{
			os << arr.arr[i] << arr.delimiter;
		}
		return os;
	}

	const T & operator[](int index);
	void addValue(const T & add);
};

//defult c`tor + c`tor 
template<class T>
Array<T>::Array(int size, char delimiter) 
{
	this->logSize = 0;
	this->phySize = size;
	this->delimiter = delimiter;
	this->arr = new T[this->phySize];
}

//copy c`tor
template<class T>
Array<T>::Array(const Array & copy)
{
	*this = copy;
}

//move c`tor
template<class T>
Array<T>::Array(Array && move)
{
	*this = move;
}

//d`ctor
template<class T>
Array<T>::~Array()
{
	delete[] arr;
}

template<class T>
const Array<T>& Array<T>::operator=(const Array & other)
{
	if (this != &other)
	{
		this->logSize = other.logSize;
		this->phySize = other.phySize;
		this->arr = new T[this->phySize];

		//loop to copy all copy array values
		for (int i = 0; i < this->logSize; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	return *this;
}

template<class T>
const Array<T>& Array<T>::operator=(Array && other)
{
	if (this != &other)
	{
		this->logSize = other.logSize;
		this->phySize = other.phySize;
		this->arr = other.arr;

		other.logSize = 0;
		other.arr = nullptr;

	}
	return *this;
}

//realloc to arr
template<class T>
void Array<T>::myRealloc(int size)
{
	T * temp = new T[size];
	for (int i = 0; i < this->logSize; i++)
	{
		temp[i] = this->arr[i];
	}

	delete[] this->arr;
	this->arr = new T[size];
	this->phySize = size;

	for (int i = 0; i < this->logSize; i++)
	{
		this->arr[i] = temp[i];
	}

	delete[] temp;
}

template<class T>
const Array<T>& Array<T>::operator+=(const T & value)
{
	//duplicate the place in arr
	if (this->logSize == this->phySize)
	{
		this->myRealloc(this->phySize * 2);
	}

	//insert value to arr
	this->arr[this->logSize] = value;
	this->logSize++;

	return *this;
}

template<class T>
void Array<T>::addValue(const T & add)
{
	*this += add;
}

template<class T>
const T & Array<T>::operator[](int index)
{
	return this->arr[index];
}

#endif // !_ARRAY_H
