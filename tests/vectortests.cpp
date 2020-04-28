#include <iostream>
#include <cassert>

#include "ttmathengine.hpp"
using namespace TTMathEngine;

int main(int argc, const char * argv[]) {
	//Vector Tests
	std::cout << "*****Begin Vector Testing\n******";
	std::cout << "Creating 3 dimensional vectors (if this goes wrong hoo boy)\n";

	Vector3 *zero = new Vector3(0, 0, 0);
	Vector3 *vector1 = new Vector3(1, 2, 3);
	Vector3 *vector2 = new Vector3(2, 2, 2);
	Vector3 *doubleVector2 = new Vector3(4, 4, 4);
	Vector3* vector3 = new Vector3(*zero);
	Vector3 *crossVector = new Vector3(-2, 4, -2);

	float scalar = 2.0f;
	float magnitudeVerification = std::sqrt(12.0f);
	float dot = 12.0f;

	std::cout << "Testing arithmatic, assignment and equivalence operators\n";
	*vector3 += *vector1;
	assert(*zero + *vector1 == *vector1);
	assert(*zero != *vector1);
	assert(*vector3 == *vector1);
	assert(*vector3 - *vector1 == *zero);

	*vector3 -= *vector1;
	assert(*vector3 == *zero);

	vector3 = vector2;
	assert(*vector3 == *vector2);

	std::cout << "Testing Vector math, normals, cross products, dot products, scalars, magnitude\n";
	assert(*vector2 * scalar == *doubleVector2);
	assert(*doubleVector2 / scalar == *vector2);

	*vector2 *= scalar;
	assert(*vector2 == *doubleVector2);

	*vector2 /= scalar;
	assert(*doubleVector2 / scalar == *vector2);
	
	assert((*vector1) * (*vector2) == dot);
	assert(vector1->dot(*vector2) == dot);
	
	assert(*vector1 % *vector2 == *crossVector);
	assert(vector1->cross(*vector2) == *crossVector);

	float mag = vector2->magnitude();
	assert(mag == magnitudeVerification);

	Vector3 vecNormal = VectorNormal(*vector1);
	vector1->normalize();
	assert(vecNormal == *vector1);
	std::cout << "vector1's normal evaluated to: " << vector1->toString() << std::endl;


	return 0;
}