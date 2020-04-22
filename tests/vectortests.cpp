#include <iostream>
#include <cassert>
#include "ttmathengine.hpp"

int main(int argc, const char * argv[]) {
	TTMathEngine::Vector3 v1(0,0,0);
	TTMathEngine::Vector3 v2(v1);	
	TTMathEngine::Vector3 v3(2,5,4);

	TTMathEngine::Vector3 v4(3,4,5);

	TTMathEngine::Vector3 scalarVec(3,6,9);
	TTMathEngine::Vector3 scaleResultDiv(1,2,3);
	TTMathEngine::Vector3 scaleResultMulti(3,6,9);

	TTMathEngine::Vector3 dotVect(1,2,0);
	TTMathEngine::Vector3 crossVect(2,3,1);

	float scalar = 3;

	assert(v1 == v2);
	std::cout << "v1 equals v2 constructed from v1\n";
	assert(v3 != v1);
	std::cout << "v3 does not equal v1\n";
	assert(v3 != v2);
	std::cout << "v3 does not equal v2\n";

	v3 = v2;
	assert(v3 == v1);
	std::cout << "v3 reassigned to v2 equals v1\n";

	assert(v2 + v4 == v4);
	std::cout << "v2 added to v4 equals v4 with the + operator\n";
	
	v1+=v4;
	assert(v1 == v4);
	std::cout << "v1 added to v4 equals v4 with the += operator\n";

	assert(v1 - v4 == v2);
	std::cout << "v4 subtracted from v1 equals v2 with the - operator\n";
	
	v1-=v4;
	assert(v1 == v2);
	std::cout << "v4 subtracted from v1 equals v2 with the -= operator\n";
	
	assert(scalarVec/scalar == scaleResultDiv);
	std::cout << "Division without assignment works appropriately\n";
	
	scalarVec/=scalar;
	assert(scalarVec == scaleResultDiv);
	std::cout << "Division with assignment works appropriately\n";
	
	assert(scalarVec * scalar == scaleResultMulti);
	std::cout << "Multiplication without assignment works appropriately\n";
	
	scalarVec*=scalar;
	assert(scalarVec == scaleResultMulti);
	std::cout << "Multiplication with assignment works appropriately\n";
	
	std::cout << crossVect.cross(dotVect).toString();

	return 0;
}