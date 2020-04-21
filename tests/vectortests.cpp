#include <iostream>
#include <cassert>
#include "ttmathengine.hpp"

int main(int argc, const char * argv[]) {
	TTMathEngine::Vector3 v1(0,0,0);
	TTMathEngine::Vector3 v2(v1);	
	TTMathEngine::Vector3 v3(2,5,4);

	TTMathEngine::Vector3 v4(3,4,5);

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
	std::cout << "v2 added to v4 equals v4 with the + operator";
	
	v1+=v4;
	assert(v1 == v4);
	std::cout << "v1 added to v4 equals v4 with the += operator";

	assert(v1 - v4 == v2);
	std::cout << "v4 subtracted from v1 equals v2 with the - operator";
	
	v1-=v4;
	assert(v1 == v2);
	std::cout << "v4 subtracted from v1 equals v2 with the -= operator";
	
	return 0;
}