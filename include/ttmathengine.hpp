#ifndef TTMATHENGINE_HPP
#define TTMATHENGINE_HPP

#include <string>

#include "../src/charhelper.cpp"

namespace TTMathEngine {
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
			Vector3();
			Vector3(float iX, float iY, float iZ);
			
			~Vector3();
			
			
			//Copy constructors
			Vector3(const Vector3& v);
			Vector3& Vector3::operator=(const Vector3& v);
			
			//Functions
			//Comparators
			bool Vector3::operator==(const Vector3& v);
			bool Vector3::operator!=(const Vector3& v);
			
			//Alter and Assign
			void Vector3::operator+=(const Vector3& v);
			void Vector3::operator-=(const Vector3& v);
			void Vector3::operator%=(const Vector3& v);
			
			//Scalar
			void Vector3::operator*=(const float s);
			void Vector3::operator/=(const float s);
			
			//Algebraic
			Vector3 Vector3::operator+(const Vector3& v)const;
			Vector3 Vector3::operator-(const Vector3& v)const;
			
			//Scalar
			Vector3 Vector3::operator*(const float s)const;
			Vector3 Vector3::operator/(const float s)const;
			
			//Dot product
			float Vector3::operator*(const Vector3& v) const;
			
			//Cross product
			Vector3 Vector3::operator%(const Vector3& v)const;
			
			//This might be really stupid, but it might be really convenient
			//Override the bitwise shifts to just be "move left" and "move right"
			Vector3 Vector3::operator<<(const Vector3& v)const;
			Vector3 Vector3::operator>>(const Vector3& v)const;
			
			//From here is non-operator functions
			float Vector3::dot(Vector3 v);
			float Vector3::magnitutde();
			
			Vector3 Vector3::cross(Vector3 v);
			
			
			
			char* Vector3::toString();
	};

//TODO: Matricies


//TODO: Quaternions


//TODO: General Functions
	double squareroot(double x);
	double squareroot(float x);
	double squareroot(int x);

	float inverseSquareroot(double x);
	float inverseSquareroot(float x);
	float inverseSquareroot(int x);
}

#endif