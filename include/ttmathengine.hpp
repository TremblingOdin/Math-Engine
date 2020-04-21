#ifndef TTMATHENGINE_HPP
#define TTMATHENGINE_HPP

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
			void Vector3::operator*=(const Vector3& v);
			void Vector3::operator/=(const Vector3& v);
			
			//Algebraic
			Vector3 Vector3::operator+(const Vector3& v)const;
			Vector3 Vector3::operator-(const Vector3& v)const;
			Vector3 Vector3::operator*(const Vector3& v)const;
			Vector3 Vector3::operator/(const Vector3& v)const;
			
			//This might be really stupid, but it might be really convenient
			//Override the bitwise shifts to just be "move left" and "move right"
			Vector3 Vector3::operator<<(const Vector3 v)const;
			Vector3 Vector3::operator>>(const Vector3 v)const;
	};

//TODO: Matricies


//TODO: Quaternions

}

#endif