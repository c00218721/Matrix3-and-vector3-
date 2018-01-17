//callum lynch
//login:c00218721

#pragma once


#include <iostream>
#include <math.h>
#include <string>
#include "Matrix3.h"

class Vector3
{
public:
	//this has 3 variables
	double x;
	double y;
	double z;

	double X();
	double Y();
	double Z();

	//constructor 1
	Vector3();


	//constructor 2 
	Vector3(double x1, double y1, double z1);


	//to retrun the length of the vector
	double Length();

	//to return the length squarded of the vector
	double LengthSquared();

	//a method to reduce the length of the vector to 1.0
	void Normalise();

	//an overload operator + to retunr the sum of 2 vectors
	const Vector3 operator+ (Vector3 v1);

	// an overload operator - to return the difference of 2 vectors
	const Vector3 operator- (Vector3 v1);

	// An overloaded operator - to return the negation of a single vector
	const Vector3 operator- ();

	//An overload  operator * to return the scalar product of 2 vectors
	const double operator*(Vector3 v1);

	//An overload operator * to retunr the product of a scalar vector
	const  Vector3 operator*(double k);

	//an overlaod operator * to return the product of a scalr by a vector
	const Vector3 operator* (float k);

	//an overload oerator * to return the product of a scalar by a vector
	const Vector3 operator* (int k);

	//an overload operator ^ to return the vector product of 2 vectors
	const Vector3 operator^ (Vector3 v1);

	//an overload operator * to return the product of the matrix by a vector
	//brought this over from the matrix class cos it wasnt working properly
	const Vector3 operator* (Matrix3 M1);


	 std::string ToString();
};

