#include "Matrix3.h"

Matrix3::Matrix3()
{
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)
{
	A11 = Row1.X();
	A12 = Row1.Y();
	A13 = Row1.Z();

	A21 = Row2.X();
	A22 = Row2.Y();
	A23 = Row2.Z();

	A31 = Row3.X();
	A32 = Row3.Y();
	A33 = Row3.Z();
}

Matrix3::Matrix3(double _A11, double _A12, double _A13, double _A21, double _A22, double _A23, double _A31, double _A32, double _A33)
{
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;

	A21 = _A21;
	A22 = _A22;
	A23 = _A23;

	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

const Vector3 Matrix3::operator*(Vector3 v1)
{
	return Vector3( A11 * v1.X() + A12 * v1.Y() + A13 * v1.Z(),
					A21 * v1.X() + A22 * v1.Y() + A23 * v1.Z(),
					A31 * v1.X() + A32 * v1.Y() + A33 * v1.Z());
}

const Matrix3 Matrix3::Transpose()
{
	return Matrix3(	A11, A21, A31,
					A12, A22, A32,
					A13, A23, A33);
}

const Matrix3 Matrix3::operator+(Matrix3 m1)
{
	return Matrix3(	A11 + m1.A11, A12 + m1.A12, A13 + m1.A13,
					A21 + m1.A21, A22 + m1.A22, A23 + m1.A23,
					A31 + m1.A31, A32 + m1.A32, A33 + m1.A33);
}

const Matrix3 Matrix3::operator-(Matrix3 m1)
{
	return Matrix3( A11 - m1.A11, A12 - m1.A12, A13 - m1.A13,
					A21 - m1.A21, A22 - m1.A22, A23 - m1.A23,
					A31 - m1.A31, A32 - m1.A32, A33 - m1.A33);
}

const Matrix3 Matrix3::operator*(double x)
{
	Matrix3 answer = Matrix3();

	answer.A11 = A11 * x;
	answer.A12 = A12 * x;
	answer.A13 = A13 * x;

	answer.A21 = A21 * x;
	answer.A22 = A22 * x;
	answer.A23 = A23 * x;

	answer.A31 = A31 * x;
	answer.A32 = A32 * x;
	answer.A33 = A33 * x;

	return answer;
}

Vector3 Matrix3::row(int i)
{
	switch(i)
	{
	case 0:
		return Vector3(A11, A12, A13);
	case 1:
		return Vector3(A21, A22, A23);
	case 2:
	default:
		return Vector3(A31, A32, A33);
	}
}

Vector3 Matrix3::col(int i)
{
	switch (i)
	{
	case 0:
		return Vector3(A11, A21, A31);
	case 1:
		return Vector3(A12, A22, A32);
	case 2:
	default:
		return Vector3(A13, A23, A33);
	}
}

const Matrix3 Matrix3::operator*(Matrix3 m1)
{
	Matrix3 answer = Matrix3();

	answer.A11 = row(0) * m1.col(0);
	answer.A12 = row(0) * m1.col(1);
	answer.A13 = row(0) * m1.col(2);

	answer.A21 = row(1) * m1.col(0);
	answer.A22 = row(1) * m1.col(1);
	answer.A23 = row(1) * m1.col(2);

	answer.A31 = row(2) * m1.col(0);
	answer.A32 = row(2) * m1.col(1);
	answer.A33 = row(2) * m1.col(2);

	return answer;
}

const double Matrix3::determinant()
{
	return A11 * A22 * A33 - A11 * A32 * A23 + A21 * A32 * A13 - A31 * A22 * A13 + A31 * A12 * A23 - A21 * A12 * A33;
}

const Matrix3 Matrix3::inverse()
{
	double det = determinant();

	if (det == 0)
	{
		return Matrix3();
	}
	else
	{
		double scale = 1 / det;
		Matrix3 answer = Matrix3();
		answer.A11 = scale * (A22 * A33 - A23 * A32);
		answer.A12 = scale * (A13 * A32 - A12 * A33);
		answer.A13 = scale * (A12 * A23 - A13 * A22);

		answer.A21 = scale * (A23 * A31 - A21 * A33);
		answer.A22 = scale * (A11 * A33 - A13 * A31);
		answer.A23 = scale * (A13 * A21 - A11 * A23);

		answer.A31 = scale * (A21 * A32 - A22 * A31);
		answer.A32 = scale * (A12 * A31 - A11 * A32);
		answer.A33 = scale * (A11 * A22 - A12 * A21);

		return answer;
	}

	
}

const Matrix3 Matrix3::translate(int dx, int dy)
{
	Matrix3 answer = Matrix3();

	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;

	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;

	answer.A31 = dx;
	answer.A32 = dy;
	answer.A33 = 1;

	return answer;
}

const Matrix3 Matrix3::scale(double dx, double dy)
{
	Matrix3 answer = Matrix3();

	answer.A11 = dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 0;

	return answer;
}

const Matrix3 Matrix3::operator-()
{
	return Matrix3(A11 * -1, A12 * -1, A13 * -1, A21 * -1, A22 * -1, A23 * -1, A31 * -1, A32 * -1, A33 * -1);
}

const Matrix3 Matrix3::scale3D(double dx)
{
	Matrix3 answer = Matrix3();

	answer.A11 = dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;

	answer.A21 = 0;
	answer.A22 = dx / 100;
	answer.A23 = 0;
	
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = dx / 100;

	return answer;
}

