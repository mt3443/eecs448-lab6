/**
*	@author 
*	@date 
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#include <iostream>
#include "Test.h"

int main(int argc, char** argv)
{
	//Example of declaring a LinkedListOfInts
	LinkedListOfInts testableList;

	//You won't do all the tests in main; that's what your Test class will be for
	//Example:
	//TestSuite myTester;
	//myTester.runTests();
	
	Test tester;
	tester.runTests();
	
	return (0);

}

