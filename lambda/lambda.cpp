//============================================================================
// Name        : lambda.cpp
// Author      : sample
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(void) {
	puts("Below is the lambda expression - \n");

	//  [ capture clause ] (parameter) -> return-type {}
	int capture_parameter = 10;
	auto addition = [capture_parameter](int a, int b)->int {
		return a + b + capture_parameter;
	};
//
	std::cout << addition(3, 5) << std::endl;

	return EXIT_SUCCESS;
}
