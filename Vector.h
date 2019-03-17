#pragma once
#include <iostream>
using namespace std;
const int MAX = 1000;
class Vector
{
	int *p_data;
	int num;
public:
	int &operator [](int i);
	friend Vector operator +(Vector v1, Vector v2);
	friend Vector operator -(Vector v1, Vector v2);
	void *operator new(size_t size);
	const int get_num()const { return num; }
	Vector();
	Vector(int s);
	Vector(int s, int a[]);
	void display();
};