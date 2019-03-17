#include"Matrix.h"

Matrix operator +(Matrix m1, Matrix m2)
{
	Matrix m(m1.row, m1.col);
	if (m1.row != m2.row || m1.col != m2.col)
		exit(-1);
	else
	{
		for (int i = 0; i < m.row; i++)
			for (int j = 0; j < m.col; j++)
				m[i][j] = m1[i][j] + m2[i][j];
	}
	return m;
}

Matrix operator -(Matrix m1, Matrix m2)
{
	Matrix m(m1.row, m1.col);
	if (m1.row != m2.row || m1.col != m2.col)
		exit(-1);
	else
	{
		for (int i = 0; i < m.row; i++)
			for (int j = 0; j < m.col; j++)
				m[i][j] = m1[i][j] - m2[i][j];
	}
	return m;
}

Vector operator *(Vector v, Matrix m)
{
	Vector _V(m.col);
	if (m.row != v.get_num())
		exit(-1);
	else
	{
		for (int i = 0; i < m.col; i++)
			for (int j = 0; j < m.row; j++)
				_V[i] += (v[j]) * (m[i][j]);
	}
	return _V;
}

Matrix operator *(Matrix m1, Matrix m2)
{
	Matrix m(m1.row, m2.col);
	if (m1.col != m2.row)
		exit(-1);
	else {
		for (int i = 0; i < m1.row; i++)
			for (int j = 0; j < m2.col; j++)
				for (int k = 0; k < m1.col; k++)
					m[i][j] += m1[i][k] + m2[k][j];
	}
	return m;
}


Matrix::Matrix(int r, int c){
	row = r; col = c;
	p_data = new Vector[r];
}

Matrix::Matrix(int r, Vector v[]) {
	row = r; col = v[0].get_num();
	p_data = new Vector[r];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < v[0].get_num(); j++)
			p_data[i][j] = v[i][j];
}

Vector & Matrix::operator[](int i)
{
	return p_data[i];
}

void Matrix::display()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << p_data[i][j] << " ";
		cout << endl;
	}
}