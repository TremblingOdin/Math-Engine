#include "ttmathengine.hpp"

namespace ttmathengine {
	//Vector functions
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
		float returnable = this->x*v.x+this->y*v.y+this->z*v.z;
		
		return returnable;
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

	std::string Vector3::ToString() {
		std::string charArr = "Vector3(";
		charArr = charArr + std::to_string(this->x) + ", "
				+ std::to_string(this->y) + ", "
				+ std::to_string(this->z) + ")";

		char* returnable = charhelper::unconstchar(charArr.c_str());
		return returnable;
	}
	
	//Matrix functions
	/*The matrix function
		0	3	6
		1	4	7
		2	5	8
	*/
	Matrix::Matrix(int x, int y) {
		this->x = x;
		this->y = y;

		this->matrix_data = std::vector<std::vector<float>>(y, std::vector<float>(x));
		
		//Empty constructor so initializing everything to 0 doesn't need to be in the top left - bottom right fashion
		for (int i = 0; i < y; i++) {
			std::vector<float> initializer;
			for (int j = 0; j < x; j++) {
				initializer.push_back(0);
			}

			matrix_data.push_back(initializer);
		}
	}

	Matrix::Matrix(int x, int y, std::vector<std::vector<float>> data) {
		this->x = x;
		this->y = y;

		this->matrix_data = std::vector<std::vector<float>>(y, std::vector<float>(x));

		int tempY;
		if (data.size() < this->y) {
			tempY = data.size();
		}

		std::vector<int> tempXes = std::vector<int>(tempY);

		// if the data vectors aren't of the same size we should figure out when we'd need to start filling them with 0
		for (int i = 0; i < tempY; i++) {
			tempXes.push_back(data[i].size());
		}

		for (int i = 0; i < y; i++) {
			std::vector<float> insert = std::vector<float>(y);
			for (int j = 0; j < x; j++) {
				if (i > tempY || j > tempXes[i]) {
					insert.push_back(0);
				}

				insert.push_back(data[i][j]);
			}
			
			this->matrix_data.push_back(insert);
		}
	}


	std::vector<std::vector<float>> Matrix::GetMatrixData() {
		return matrix_data;
	}

	void Matrix::Show() {
		std::cout << "[\t";

		for (int i = 0; i < this->y; i++) {
			for (int j = 0; j < this->x; j++) {
				std::cout << matrix_data[i][j] << ",\t";
			}

			std::cout << "\n";
		}

		std::cout << "\t]\n";
	}

	std::string Matrix::ToString() {
		std::string matrixString = "{";

		for (int i = 0; i < this->x; i++) {
			matrixString += " (";

			for (int j = 0; j < this->y; j++) {
				matrixString += " " + std::to_string(matrix_data[i][j]) + " ";
			}

			matrixString += ") ";
		}

		matrixString += "}";

		return matrixString;
	}


	//Matrix::Matrix() {
	//	for (int i = 0; i < 9; i++) {
	//		this->matrix_data[i] = 0.0f;
	//	}

	//	this->matrix_data[0] = this->matrix_data[4] = this->matrix_data[8] = 1.0f;
	//}

	//Matrix::Matrix(float f0, float f3, float f6, float f1, 
	//	float f4, float f7, float f2, float f5, float f8) {
	//	matrix_data[0] = f0;
	//	matrix_data[1] = f3;
	//	matrix_data[2] = f6;
	//	matrix_data[3] = f1;
	//	matrix_data[4] = f4;
	//	matrix_data[5] = f7;
	//	matrix_data[6] = f2;
	//	matrix_data[7] = f5;
	//	matrix_data[8] = f8;
	//}

	///**
	//* This assumes that dataArr is properly formatted
	//*/
	//Matrix::Matrix(float* dataArr) {
	//	for (int i = 0; i < 9; i++) {
	//		this->matrix_data[i] = dataArr[i];
	//	}
	//}

	///**
	//* This reads each array in the 2DArray as a column in the matrix
	//*/
	//Matrix::Matrix(float** dataArr2D) {
	//	int matDIndex = 0;
	//	
	//	for (int i = 0; i < 3; i++) {
	//		for (int j = 0; j < 3; j++) {
	//			this->matrix_data[matDIndex++] = dataArr2D[j][i];
	//		}
	//	}
	//}

	//Matrix::Matrix(float* data1, float* data2, float* data3) {
	//	int matDIndex = 0;

	//	for (int i = 0; i < 3; i++) {
	//		this->matrix_data[matDIndex] = data1[i];
	//		this->matrix_data[matDIndex] = data2[i];
	//		this->matrix_data[matDIndex] = data3[i];
	//		matDIndex++;
	//	}
	//}
	//
	//Matrix::~Matrix() {
	//	delete [] matrix_data;
	//}
	//
	////Comparators
	//bool Matrix::operator==(const Matrix& other_m) {
	//	float* other_matrix = other_m.GetMatrixData;
	//	
	//	for(int i = 0; i < 9; i++) {
	//		if(this->matrix_data[i] != other_matrix[i]) {
	//			return false;
	//		}
	//	}
	//	
	//	delete [] other_matrix;
	//	
	//	return true;
	//}

	//bool Matrix::operator!=(const Matrix& other_m) {
	//	float* other_matrix = other_m.GetMatrixData;
	//	
	//	for(int i = 0; i < 9; i++) {
	//		if(this->matrix_data[i] != other_matrix[i]) {
	//			return true;
	//		}
	//	}
	//	
	//	delete [] other_matrix;
	//	
	//	return false;
	//}
	//
	////Arithmatic
	//Matrix* Matrix::operator+(const Matrix& other_m)const {
	//	float* matrix_data_new = new float[9];
	//	float* other_matrix_data = other_m.GetMatrixData;
	//	
	//	for(int i = 0; i < 9; i++) {
	//		matrix_data_new[i] = other_matrix_data[i] + this->matrix_data[i];
	//	}
	//	
	//	Matrix* returnable = new Matrix(matrix_data_new);
	//	
	//	delete [] other_matrix_data;
	//	delete [] matrix_data_new;
	//	
	//	return returnable;
	//}
	//
	//Matrix* Matrix::operator-(const Matrix& other_m)const {
	//	float* matrix_data_new = new float[9];
	//	float* other_matrix_data = other_m.GetMatrixData;
	//	
	//	for(int i = 0; i < 9; i++) {
	//		matrix_data_new[i] = other_matrix_data[i] - this->matrix_data[i];
	//	}
	//	
	//	Matrix* returnable = new Matrix(matrix_data_new);
	//	
	//	delete [] other_matrix_data;
	//	delete [] matrix_data_new;
	//	
	//	return returnable;
	//}
	//
	//Matrix* Matrix::operator*(const Matrix& other_m)const {
	//	float* matrix_data_new = new float[9];
	//	float* other_matrix_data = other_m.GetMatrixData;
	//	
	//	float rows[3][3] = {
	//		{this->matrix_data[0], this->matrix_data[1], this->matrix_data[2]},
	//		{this->matrix_data[3], this->matrix_data[4], this->matrix_data[5]},
	//		{this->matrix_data[6], this->matrix_data[7], this->matrix_data[8]}
	//	};

	//	float cols[3][3] = {
	//		{this->matrix_data[0], this->matrix_data[3], this->matrix_data[6]},
	//		{this->matrix_data[1], this->matrix_data[4], this->matrix_data[7]},
	//		{this->matrix_data[2], this->matrix_data[5], this->matrix_data[8]},
	//	};
	//	
	//	for(int i = 0; i < 3; i++) {
	//		for(int j = 0; j < 3; j++) {
	//			matrix_data_new[(3*i) + j] = rows[i][0] * cols[j][0] + rows[i][1] * cols[j][1] + rows[i][2] * cols[j][2];
	//		}
	//	}
	//	
	//	Matrix* returnable = new Matrix(matrix_data_new);
	//	
	//	delete [] other_matrix_data;
	//	delete [] matrix_data_new;
	//	
	//	return returnable;
	//}
	//
	//Matrix* Matrix::operator/(const Matrix& other_m)const {
	//	float matrix_data_new[9] = {0.0};
	//	float* other_matrix_data = other_m.GetMatrixData;
	//	
	//	float rows[3][3] = {
	//		{this->matrix_data[0], this->matrix_data[1], this->matrix_data[2]},
	//		{this->matrix_data[3], this->matrix_data[4], this->matrix_data[5]},
	//		{this->matrix_data[6], this->matrix_data[7], this->matrix_data[8]}
	//	};

	//	float cols[3][3] = {
	//		{this->matrix_data[0], this->matrix_data[3], this->matrix_data[6]},
	//		{this->matrix_data[1], this->matrix_data[4], this->matrix_data[7]},
	//		{this->matrix_data[2], this->matrix_data[5], this->matrix_data[8]},
	//	};
	//	
	//	for(int i = 0; i < 3; i++) {
	//		for(int j = 0; j < 3; j++) {
	//			matrix_data_new[(3 * i) + j] = rows[i][0] * cols[j][0] + rows[i][1] * cols[j][1] + rows[i][2] * cols[j][2];
	//		}
	//	}
	//	
	//	Matrix* returnable = new Matrix(matrix_data_new);
	//	
	//	delete[] matrix_data_new;

	//	return returnable;
	//}
	//
	//Matrix* Matrix::operator*(const float scalar)const {
	//	float* matrix_data_new = new float[9];
	//	
	//	for(int i = 0; i < 9; i++) {
	//		matrix_data_new[i] = scalar  * this->matrix_data[i];
	//	}
	//	
	//	Matrix* returnable = new Matrix(matrix_data_new);
	//	
	//	delete [] matrix_data_new;
	//	
	//	return returnable;
	//}
	//
	//Matrix* Matrix::operator/(const float scalar)const {
	//	float* matrix_data_new = new float[9];
	//	
	//	for(int i = 0; i < 9; i++) {
	//		matrix_data_new[i] = scalar  / this->matrix_data[i];
	//	}
	//	
	//	Matrix* returnable = new Matrix(matrix_data_new);
	//	
	//	delete [] matrix_data_new;
	//	
	//	return returnable;
	//}
	//
	////Alter and assign
	//

	////Matrix functions
	//float* Matrix::GetMatrixData() {
	//	return matrix_data;
	//}

	//Matrix Matrix::Inverse() {
	//	float matData = ;
	//	float determinantA = matData[0] * (matData[4] * matData[8] - matData[5] * matData[7]);
	//	float determinantB = matData[1] * (matData[3] * matData[8] - matData[5] * matData[6]);
	//	float determinantC = matData[2] * (matData[3] * matData[7] - matData[4] * matData[6]);

	//	float determinant = determinantA - determinantB + determinantC;
	//	if (determinant == 0) {
	//		return nullptr;
	//	}

	//	Matrix* minor = this->MinorMatrix();
	//	minor->Cofactor();
	//	Matrix* minorAdjugate = minor->Adjugate();

	//	*minor *= (1 / determinant);

	//	return minor;
	//}

	//Matrix* Matrix::MinorMatrix() {
	//	float matData[9] = {
	//		//row 0
	//		this->matrix_data[4] * this->matrix_data[8] - this->matrix_data[5] * this->matrix_data[7],
	//		this->matrix_data[3] * this->matrix_data[8] - this->matrix_data[5] * this->matrix_data[6],
	//		this->matrix_data[3] * this->matrix_data[7] - this->matrix_data[4] * this->matrix_data[6],
	//		//row 1
	//		this->matrix_data[1] * this->matrix_data[8] - this->matrix_data[2] * this->matrix_data[7],
	//		this->matrix_data[0] * this->matrix_data[8] - this->matrix_data[2] * this->matrix_data[6],
	//		this->matrix_data[0] * this->matrix_data[7] - this->matrix_data[1] * this->matrix_data[6],
	//		//row 2
	//		this->matrix_data[1] * this->matrix_data[5] - this->matrix_data[2] * this->matrix_data[4],
	//		this->matrix_data[0] * this->matrix_data[5] - this->matrix_data[2] * this->matrix_data[3],
	//		this->matrix_data[0] * this->matrix_data[4] - this->matrix_data[1] * this->matrix_data[3]
	//	};

	//	return new Matrix(matData);
	//}

	//Matrix* Matrix::Adjugate() {
	//	float matData[9] = {
	//		this->matrix_data[0], this->matrix_data[3], this->matrix_data[6],
	//		this->matrix_data[1], this->matrix_data[4], this->matrix_data[7],
	//		this->matrix_data[2], this->matrix_data[5], this->matrix_data[8]
	//	};

	//	return new Matrix(matData);
	//}

	//void Matrix::Cofactor() {
	//	for (int i = 0; i < sizeof(this->matrix_data); i++) {
	//		if (i % 2 != 0) {
	//			this->matrix_data[i] = -this->matrix_data[i];
	//		}
	//	}
	//}

	////Display functions
	//void Matrix::Show() {
	//	std::cout << "\n[" << matrix_data[0] << ",\t" << matrix_data[3] << ",\t" << matrix_data[6] << std::endl;
	//	std::cout << matrix_data[1] << ",\t" << matrix_data[4] << ",\t" << matrix_data[7] << std::endl;
	//	std::cout << matrix_data[2] << ",\t" << matrix_data[5] << ",\t" << matrix_data[8] << "]" << std::endl;
	//}

	//char* Matrix::ToString() {
	//	std::string charArr = "Matrix(";
	//	charArr = charArr + "(" + std::to_string(matrix_data[0]) + ","
	//		+ std::to_string(matrix_data[3]) + "," + std::to_string(matrix_data[6]) + "),("
	//		+ std::to_string(matrix_data[1]) + "," + std::to_string(matrix_data[4])
	//		+ "," + std::to_string(matrix_data[7]) + "),(" + std::to_string(matrix_data[2]) + ","
	//		+ std::to_string(matrix_data[5]) + "," + std::to_string(matrix_data[8]) + "))";

	//	return charhelper::unconstchar(charArr.c_str());
	//}

	//General Namespace functions
	Vector3 ttmathengine::VectorNormal(Vector3 v) {
		if((v.magnitude()) > 0.0f) {
			float inverseMag = 1.0f/(v.magnitude());
			
			return Vector3(v.x*inverseMag, v.y*inverseMag, v.z*inverseMag);
		}
	}

	Matrix ttmathengine::Inverse(Matrix mat) {
		std::vector<std::vector<float>> matNew 
			= std::vector<std::vector<float>>(mat.y, std::vector<float>(mat.x));


	}

	Matrix ttmathengine::MinorMatrix(Matrix mat) {
		std::vector<std::vector<float>> fullMinorMat
			= std::vector<std::vector<float>>(mat.y, std::vector<float>(mat.x));

		for (int i = 0; i < mat.y; i++) {
			for (int j = 0; j < mat.x; j++) {
				fullMinorMat[i][j] = Determinant(mat.GetMatrixData(), j, i);
			}
		}

		return Matrix(mat.x, mat.y, fullMinorMat);
	}

	Matrix ttmathengine::Cofactor(Matrix mat) {
		
	}

	Matrix ttmathengine::Adjugate(Matrix mat) {

	}

	float Determinant(std::vector<std::vector<float>> data, int x, int y) {
		//The matricies we use to calculate determinants are less by 1 in each dimension
		std::vector<std::vector<float>> minor
			= std::vector<std::vector<float>>(data.size() - 1, std::vector<float>(data[0].size() - 1));

		//populate the matrix we'll use to calculate
		for (int i = 0; i < data.size(); i++) {
			if (i == y) {
				continue;
			}

			std::vector<float> insert = std::vector<float>(data[0].size() - 1);

			for (int j = 0; j < data[0].size(); j++) {
				if (j == x) {
					continue;
				}

				insert.push_back(data[i][j]);
			}

			minor.push_back(insert);
		}

		float determinant;

		for (int i = 0; i < minor[0].size(); i++) {
			float adder = 1;
			float subtractor = 1;

			for (int j = 0; j < minor.size(); j++) {
				if (i + j < minor[0].size()) {
					adder *= (minor[j][i + j]);
					subtractor *= (minor[minor.size() - (j + 1)][i + j]);
				}
				else {
					adder *= (minor[j][(i + j) - minor[0].size()]);
					subtractor *= (minor[minor.size() - (j + 1)][(i + j) - minor[0].size()]);
				}
			}

			determinant += (adder - subtractor);
		}

		return determinant;
	}
}