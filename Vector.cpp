#include"Vector.h"

Vector operator +(Vector v1, Vector v2)
{
	Vector v(v1.num);
	if (v1.num != v2.num)
		exit(-1);
	else
	{
		for (int i = 0; i < v1.num; i++)
			v[i] = v1[i] + v2[i];
	}
	return v;
}

Vector operator -(Vector v1, Vector v2)
{
	Vector v(v1.num);
	if (v1.num != v2.num)
		exit(-1);
	else
	{
		for (int i = 0; i < v1.num; i++)
			v[i] = v1[i] - v2[i];
	}
	return v;
}

int & Vector::operator [](int i)
{
	return p_data[i];
}

void * Vector::operator new(size_t size)
{
	void *p = malloc(size);
	memset(p, 0, size);
	return p;
}

Vector::Vector()
{
	num = 0;
	p_data = new int[MAX];
	for (int i = 0; i < MAX; i++)
		p_data[i] = 0;
}

Vector::Vector(int s)
{
	num = s;
	p_data = new int[s];
	for (int i = 0; i < num; i++)
		p_data[i] = 0;
}

Vector::Vector(int s, int a[]) {
	num = s;
	p_data = a;
}

void Vector::display()
{
	for (int i = 0; i < num; i++)
		cout << p_data[i] << " ";
	cout << endl;
}