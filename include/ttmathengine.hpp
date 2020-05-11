#ifndef TTMATHENGINE_HPP
#define TTMATHENGINE_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "../src/charhelper.cpp"

namespace ttmathengine {
//TODO: Vectors
	class Vector3 {
		private:
		
		public:
			//Vars
			//public coords for ease of access and writing
			float x;
			float y;
			float z;
			
			
			//Constructors and Deconstructors
			Vector3::Vector3();
			Vector3::Vector3(float, float, float);
			
			Vector3::~Vector3();
			
			
			//Copy constructors
			Vector3(const Vector3&);
			Vector3& Vector3::operator=(const Vector3&);
			
			//Functions
			//Comparators
			bool Vector3::operator==(const Vector3&);
			bool Vector3::operator!=(const Vector3&);
			
			//Alter and Assign
			void Vector3::operator+=(const Vector3&);
			void Vector3::operator-=(const Vector3&);
			void Vector3::operator%=(const Vector3&);
			
			//Scalar
			void Vector3::operator*=(const float);
			void Vector3::operator/=(const float);
			
			//Algebraic
			Vector3* Vector3::operator+(const Vector3&)const;
			Vector3* Vector3::operator-(const Vector3&)const;
			
			//Scalar
			Vector3* Vector3::operator*(const float)const;
			Vector3* Vector3::operator/(const float)const;
			
			//Dot product
			float* Vector3::operator*(const Vector3&) const;
			
			//Cross product
			Vector3* Vector3::operator%(const Vector3&)const;
			
			//This might be really stupid, but it might be really convenient
			//Override the bitwise shifts to just be "move left" and "move right"
			Vector3* Vector3::operator<<(const Vector3&)const;
			Vector3* Vector3::operator>>(const Vector3&)const;
			
			//From here is non-operator functions
			float Vector3::dot(Vector3);
			float Vector3::magnitude();
			
			Vector3 Vector3::cross(Vector3);
			
			void Vector3::normalize();
			
			char* Vector3::ToString();
	};

//TODO: Matricies
	class Matrix {
		private:
			float matrix_data[9] = { 0.0 };

		public:
			//Constructors
			Matrix::Matrix();
			Matrix::Matrix(float, float, float, float, float, float, float, float, float);
			Matrix::Matrix(float*);
			Matrix::Matrix(float**);
			Matrix::Matrix(float*, float*, float*);
			
			//Copy Constructors
			Matrix::Matrix(const Matrix&);
			Matrix& Matrix::operator=(const Matrix&)const;

			Matrix::~Matrix();
			
			//Comparators
			bool Matrix::operator==(const Matrix&);
			bool Matrix::operator!=(const Matrix&);
			
			//Arithmatic
			Matrix* Matrix::operator+(const Matrix&)const;
			Matrix* Matrix::operator-(const Matrix&)const;
			Matrix* Matrix::operator*(const Matrix&)const;
			Matrix* Matrix::operator/(const Matrix&)const;
			
			Matrix* Matrix::operator*(const float)const;
			Matrix* Matrix::operator/(const float)const;
			
			//Add and assign
			void Matrix::operator+=(const Matrix&)const;
			void Matrix::operator-=(const Matrix&)const;
			void Matrix::operator*=(const Matrix&)const;
			void Matrix::operator/=(const Matrix&)const;
			
			void Matrix::operator*=(const float)const;
			void Matrix::operator/=(const float)const;
			
			float* Matrix::GetMatrixData();

			Matrix* Matrix::Inverse();
			Matrix* Matrix::MinorMatrix();
			Matrix* Matrix::Adjugate();

			void Matrix::Cofactor();

			//Two display functions
			void Matrix::Show();
			char* Matrix::ToString();
	};

//TODO: Quaternions
	class Quaternion {
		private:
		
		public:
			float scalar;
			
			Vector3 vector;
			
			//Constructors
			Quaternion();
			Quaternion(float, Vector3&);
			
			//Copy Constructor
			Quaternion(const Quaternion&);
			Quaternion& Quaternion::operator=(const Quaternion&);
			
			~Quaternion();
	};

//TODO: General Functions
	Vector3 VectorNormal(Vector3);
}

#endif