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
