#include "Vector3.h"

double Vector3::X()
{
	return x;
}

double Vector3::Y()
{
	return y;
}

double Vector3::Z()
{
	return z;
}

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}

double Vector3::Length()
{
	return sqrt( x * x + y * y + z * z);
}

double Vector3::LengthSquared()
{
	return x * x + y * y + z * z;
}

void Vector3::Normalise()
{
	//check if its devided by zero
	if (Length() > 0.0)
	{
		double magnit = Length();
		x /= magnit;
		y /= magnit;
		z /= magnit;
	}
}

const Vector3 Vector3::operator+(Vector3 v1) 
{
	return Vector3(x + v1.x, y + v1.y, z + v1.z);
}

const Vector3 Vector3::operator-(Vector3 v1)
{
	return Vector3(x - v1.x, y - v1.y, z - v1.z);
}

const Vector3 Vector3::operator-()
{
	return Vector3(-x, -y, -z);
}

const double Vector3::operator*(Vector3 v1)
{
	return (x * v1.x + y * v1.y + z * v1.z);
}

const Vector3 Vector3::operator*(double k)
{
	return Vector3(x * k, y * k, z * k);
}

const Vector3 Vector3::operator*(float k)
{
	return Vector3(x * k, y * k, z * k);
}

const Vector3 Vector3::operator*(int k)
{
	return Vector3(x * k, y * k, z * k);
}

const Vector3 Vector3::operator^(Vector3 v1)
{
	return Vector3(y * v1.z - z * v1.y, z * v1.x - x * v1.z, x * v1.y - y * v1.x);
}

const Vector3 Vector3::operator*(Matrix3 M1)
{
	return Vector3(		M1.A11 * X() + M1.A21 * Y() + M1.A31 * Z(),
						M1.A12 * X() + M1.A22 * Y() + M1.A32 * Z(),
						M1.A13 * X() + M1.A23 * Y() + M1.A33 * Z());
}

std::string Vector3::ToString()
{
	return std::string("(" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + ")");
}


