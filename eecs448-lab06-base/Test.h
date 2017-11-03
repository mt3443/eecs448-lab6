#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"

class Test {
	public:
	
	Test();
	bool testEmptyOnEmptyList();
	bool testEmptyOnPopulatedList();
	bool testSizeOfEmptyList();
	bool testSizeAfterAddFront(int value);
	bool testSizeAfterAddBack(int value);
	bool testSearchOnEmptyList(int value);
	bool testSearchWhenValueIsFirst(int value);
	bool testSearchWhenValueIsLast(int value);
	bool testSearch(int value);
	bool testSearchWhenValueNotPresent();
	bool testSizeAfterRemoveFront(int value);
	bool testSizeAfterRemoveBack(int value);
	bool testAddFrontOrder();
	bool testAddBackOrder();
	void runTests();
	void testPassed(bool result);
		
	private:
	
	int m_score;
};

#endif
