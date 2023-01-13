#include<iostream>

using namespace std;
class Point
{	
public:
	Point();
	Point(int x, int y);
	~Point();
	friend ostream& operator <<(ostream& os, const Point& obj);
private:
	int x;
	int y;
};
Point::Point() : x(0), y(0){}
Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}
Point::~Point()
{
}

template<typename T>
class IntArray

{
private:

	int length;
	T* data;
public:

	IntArray() : length(0), data(nullptr)

	{

	}

	IntArray(int length) : length(length)

	{
		data = new int[length];
	}

	IntArray(const std::initializer_list<int>& list) :

		IntArray(list.size())

	{
		int i = 0;
		for (auto element : list)

		{
			data[i] = element;
			i++;
		}
	}

	~IntArray()

	{
		delete[] data;
	}

	int& operator[](int index)

	{
		return data[index];
	}

	int getLength() const

	{
		return length;
	}

};

template<>
class IntArray<Point>
{
public:

	IntArray() : length(0), data(nullptr)

	{

	}

	IntArray(int length) : length(length)

	{
		data = new Point[length];
	}

	IntArray(const std::initializer_list<Point>& list) :

		IntArray(list.size())

	{
		size_t i = 0;
		for (auto element : list)

		{

			data[i] = element;

			i++;
		}
	}

	~IntArray()

	{
		delete[] data;
	}

	Point& operator[](int index)

	{
		return data[index];
	}

	int getLength() const

	{
		return length;
	}
private:
	int length;
	Point* data;
};
ostream& operator <<(ostream& os, const Point& obj)
{
	os << "X: " << obj.x << endl;
	os << "Y: " << obj.y << endl;
	return os;
}


int main()

{

	IntArray<Point> array{ {7, 6}, {5, 4}, {3, 2} }; // вызов конструктора

	for (int i = 0; i < 3; i++)
	{
		cout << array[i];
	}
	cout << endl;

}

