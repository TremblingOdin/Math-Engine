#include "ttmathengine.hpp"

namespace TTMathEngine {
	Vector3::Vector3():x(0.0),y(0.0),z(0.0){}
	Vector3::Vector3(float iX, float iY, float iZ):x(iX), y(iY), z(iZ){}

	Vector3::~Vector3(){}
	
	Vector3::Vector3(const Vector3& v):x(v.x), y(v.y), z(v.z){}
	Vector3& Vector3::operator=(const Vector3& v) {
		this->x=v.x;
		this->y=v.y;
		this->z=v.z;
		
		return *this;
	}
	
	//Comparators
	bool Vector3::operator==(const Vector3& v) {
		if(this->x == v.x && this->y == v.y && this->z == v.z) {
			return true;
		}
		
		return false;
	}
	
	bool Vector3::operator!=(const Vector3& v) {
		if(!(this->x == v.x && this->y == v.y && this->z == v.z)) {
			return true;
		}
		
		return false;
	}
	
	//Alter and assign
	void Vector3::operator+=(const Vector3& v) {
		this->x+=v.x;
		this->y+=v.y;
		this->z+=v.z;
	}
	
	void Vector3::operator-=(const Vector3& v) {
		this->x-=v.x;
		this->y-=v.y;
		this->z-=v.z;
	}
	
	//Cross product
	void Vector3::operator%=(const Vector3& v) {
		*this=cross(v);
	}
	
	//Scalar
	void Vector3::operator*=(const float s) {
		this->x*=s;
		this->y*=s;
		this->z*=s;
	}
	
	void Vector3::operator/=(const float s) {
		this->x/=s;
		this->y/=s;
		this->z/=s;
	}
	
	//Algebraic
	Vector3 Vector3::operator+(const Vector3& v)const {
		return Vector3(this->x+v.x,this->y+v.y,this->z+v.z);
	}
	
	Vector3 Vector3::operator-(const Vector3& v)const {
		return Vector3(this->x-v.x,this->y-v.y,this->z-v.z);
	}
	
	//Cross product
	Vector3 Vector3::operator%(const Vector3& v)const {
		return Vector3(this->y*v.z-this->z*v.y,
						this->z*v.x-this->x*v.z,
						this->x*v.y-this->y*v.x);
	}

	
	//Dot product
	float Vector3::operator*(const Vector3& v)const {
		return this->x*v.x+this->y*v.y+this->z*v.z;
	}
	
	//Scalar
	Vector3 Vector3::operator*(const float s)const {
		return Vector3(this->x*s, this->y*s, this->z*s);
	}
	
	Vector3 Vector3::operator/(const float s)const {
		return Vector3(this->x/s, this->y/s, this->z/s);
	}
	
	//The really stupid idea
	
	
	//Non-operator functions
	float Vector3::dot(Vector3 v) {
		return this->x*v.x+ this->y*v.y+ this->z*v.z;
	}

	float Vector3::magnitutde() {
		float magnitude=
	}
	
	Vector3 Vector3::cross(Vector3 v) {
		return Vector3(this->y*v.z-this->z*v.y,
						this->z*v.x-this->x*v.z,
						this->x*v.y-this->y*v.x);
	}



	char* Vector3::toString() {
		std::string charArr = "Vector3(";
		charArr = charArr + std::to_string(this->x) + ", "
				+ std::to_string(this->y) + ", "
				+ std::to_string(this->z) + ")";

		char* returnable = charhelper::unconstchar(charArr.c_str());
		return returnable;
	}
	
	
	
	double squareroot(double x) {
		return (1/inverseSquareroot((x));
	}
	
	double squareroot(float x) {
		return (1/inverseSquareroot((x));		
	}
	
	double squareroot(int x) {
		return (1/inverseSquareroot((x));		
	}

	double inverseSquareroot(double x) {
		double half = .5f * x;
		int i = *(int*)&x;
		
		//Why yes I do like Quake
		i = 0x5f3759df - (i >> i);
		x = *(float*)&i;
		x=x*(1.5f-half*x*x);
		
		return x;
	}
	
	double inverseSquareroot(float x) {
		double r;
		double half = .5f * x;
		int i = *(int*)&x;
		
		//Why yes I do like Quake
		i = 0x5f3759df - (i >> i);
		r = *(double*)&i;
		r = r*(1.5f-half*r*r);
		
		return r;
	}
	
	double inverseSquareroot(int i) {
		double half = .5f * x;
		int i = *(int*)&x;
		double r;
		
		//Why yes I do like Quake
		i = 0x5f3759df - (i >> i);
		r = *(float*)&i;
		r = r*(1.5f-half*r*r);
		
		return r;
	}
	
}