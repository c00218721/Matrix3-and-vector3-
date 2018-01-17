//callum lynch
//login: c00218721

#include <iostream>
#include "Vector3.h"
#include <math.h>

class Matrix3
{

public:
	Vector3 vector3;
	

	const double PI = 3.14159;
	//class has nine variables 3 for rows an dcolumns

	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;


	//constructer to creat a zero matrix
	Matrix3();

	//constructer 2
	Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3);

	//constructaor 3
	Matrix3(	double _A11, double _A12, double _A13,
				double _A21, double _A22, double _A23,
				double _A31, double _A32, double _A33);

	//an overload operaor * to return the product of the matrix by a vector
	const Vector3 operator* (Vector3 v1);

	//a method to transpose a given matrix
	const Matrix3 Transpose();

	// An overloaded operator + to return the  sum of two matrix 
	const Matrix3 operator+(Matrix3 m1);

	//an overload operator - to return the differneces of a matrix
	const Matrix3 operator-(Matrix3 m1);

	//an overload operator * to multiply the product by a scalr
	const Matrix3 operator* (double x);

	//a method to return a Row as a vector 3
	Vector3 row(int i);

	//a method to return a Col as a vector 3
	Vector3 col(int i);

	//an overload operator * to return the product of 2 matrixes
	const Matrix3 operator* (Matrix3 m1);

	//method to return the determinant of a  3x3 matrix
	const double determinant();

	//method to return the inverse of a matrix if exists else zero vector
	const Matrix3 inverse();

	//transalates
	const Matrix3 translate(int dx, int dy);

	//scales
	const Matrix3 scale(double dx, double dy);

	//multiplies everything by -1
	const Matrix3 operator-();

	const Matrix3 scale3D(double dx);

	//rotates
	const Matrix3 rotation(int _angle);

	//rotates x axis
	const Matrix3 RotationX(int _angle);

	//rotates y axis
	const Matrix3 RotationY(int _angle);

	//rotates z axis
	const Matrix3 RotationZ(int _angle);
};