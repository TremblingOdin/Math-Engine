#include <iostream>
#include <cassert>

#include "ttmathengine.hpp"
using namespace ttmathengine;

void vector_test();
void matrix_test();

int main(int argc, const char * argv[]) {
	vector_test();
	matrix_test();

	return 0;
}

void vector_test() {
	//Vector Tests
	std::cout << "****************Begin Vector Testing\n****************";
	std::cout << "Creating 3 dimensional vectors (if this goes wrong hoo boy)\n";

	Vector3* zero = new Vector3(0, 0, 0);
	Vector3* vector1 = new Vector3(1, 2, 3);
	Vector3* vector2 = new Vector3(2, 2, 2);
	Vector3* doubleVector2 = new Vector3(4, 4, 4);
	Vector3* vector3 = new Vector3(*zero);
	Vector3* crossVector = new Vector3(-2, 4, -2);

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
	std::cout << "vector1's normal evaluated to: " << vector1->ToString() << std::endl;
	std::cout << "****************End Vector Testing****************\n";
}

void matrix_test() {
	std::cout << "****************Begin Matrix Testing****************\n";
	std::cout << "Creating Matricies\n";

	float* dataArr1 = new float[9];
	float* miniArr1 = new float[3];
	float* miniArr2 = new float[3];
	float* miniArr3 = new float[3];
	float** dataArr2D = new float*[3];

	for (int i = 0; i < 3; i++) {
		miniArr1[i] = (float)(i * 3);
		miniArr2[i] = (float)(i * 2);
		miniArr3[i] = (float)(i * 5);
	}

	dataArr2D[0] = miniArr1;
	dataArr2D[1] = miniArr2;
	dataArr2D[2] = miniArr3;

	for (int i = 0; i < 9; i++) {
		dataArr1[i] = (float)i;
	}

	Matrix *m1 = new Matrix();
	m1->Show();
	std::cout << m1->ToString() << std::endl;
	Matrix *m2 = new Matrix(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	m2->Show();
	Matrix *neo = new Matrix(dataArr1);
	neo->Show();
	Matrix *reloaded = new Matrix(dataArr2D);
	reloaded->Show();
	Matrix *revolution = new Matrix(miniArr1, miniArr2, miniArr3);
	revolution->Show();

	float* dataArr2 = neo->GetMatrixData();
	for (int i = 0; i < 9; i++) {
		assert(dataArr1[i] == dataArr2[i]);
	}
}