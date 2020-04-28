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

	float Vector3::magnitude() {
		float magnitude=std::sqrt(this->x*this->x
									+this->y*this->y
									+this->z*this->z);
		
		return magnitude;
	}
	
	Vector3 Vector3::cross(Vector3 v) {
		return Vector3(this->y*v.z-this->z*v.y,
						this->z*v.x-this->x*v.z,
						this->x*v.y-this->y*v.x);
	}

	void Vector3::normalize() {
		if((this->magnitude()) > 0.0f) {
			float inverseMag=1.0f/(this->magnitude());
			
			this->x=this->x*inverseMag;
			this->y=this->y*inverseMag;
			this->z=this->z*inverseMag;
		}
	}

	char* Vector3::toString() {
		std::string charArr = "Vector3(";
		charArr = charArr + std::to_string(this->x) + ", "
				+ std::to_string(this->y) + ", "
				+ std::to_string(this->z) + ")";

		char* returnable = charhelper::unconstchar(charArr.c_str());
		return returnable;
	}
	
	Vector3 TTMathEngine::VectorNormal(Vector3 v) {
		if((v.magnitude()) > 0.0f) {
			float inverseMag = 1.0f/(v.magnitude());
			
			return Vector3(v.x*inverseMag, v.y*inverseMag, v.z*inverseMag);
		}
	}
}