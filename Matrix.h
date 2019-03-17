#pragma once
#include "Vector.h"
class Matrix
{
	Vector *p_data;
	int row, col;
public:
	Matrix() {
		p_data = NULL;
	}
	Matrix(int r, int c);
	Matrix(int r, Vector v[]);
	Vector &operator[](int i);
	friend Matrix operator +(Matrix m1, Matrix m2);
	friend Matrix operator -(Matrix m1, Matrix m2);
	friend Vector operator *(Vector v, Matrix m);
	friend Matrix operator *(Matrix m1, Matrix m2);
	void display();
};
