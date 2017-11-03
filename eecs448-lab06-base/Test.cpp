#include "Test.h"

Test::Test() {
	m_score = 0;
}

bool Test::testEmptyOnEmptyList() {
	LinkedListOfInts list;
	
	return list.isEmpty() == true;
}

bool Test::testEmptyOnPopulatedList() {
	LinkedListOfInts list;
	
	for(int i = 0; i < 100; i++) {
		list.addFront(i);
	}
	
	if(list.isEmpty() == 1) {
		std::cout << "\nExpected output of isEmpty() on a list of " << list.size() << " elements: 0\n";
		std::cout << "Given output of isEmpty() on a list of " << list.size() << " elements: " << list.isEmpty() << std::endl;
	}
	
	return list.isEmpty() == false;
}

bool Test::testSizeOfEmptyList() {
	LinkedListOfInts list;
	
	return list.size() == 0;
}

bool Test::testSizeAfterAddFront(int value) {
	LinkedListOfInts list;
	
	for(int i = 0; i < value; i++) {
		list.addFront(i);
	}
	
	return list.size() == value;
}

bool Test::testSizeAfterAddBack(int value) {
	LinkedListOfInts list;
	
	for(int i = 0; i < value; i++) {
		list.addBack(i);
	}
	
	return list.size() == value;
}

bool Test::testSearchOnEmptyList(int value) {
	LinkedListOfInts list;
	
	return list.search(value) == false;
}

bool Test::testSearchWhenValueIsFirst(int value) {
	LinkedListOfInts list;
	
	for(int i = 0; i < 30; i++) {
		list.addFront(i);
	}
	
	list.addFront(value);
	
	return list.search(value) == true;
}

bool Test::testSearchWhenValueIsLast(int value) {
	LinkedListOfInts list;
	
	list.addFront(value);
	
	for(int i = 0; i < 30; i++) {
		list.addFront(i);
	}
	
	return list.search(value) == true;
}

bool Test::testSearch(int value) {
	LinkedListOfInts list;
	
	for(int i = 0; i < 100; i++) {
		list.addBack(i);
	}
	
	return list.search(value) == true;
}

bool Test::testSizeAfterRemoveFront(int value) {
	LinkedListOfInts list;
	
	for(int i = 0; i < value; i++) {
		list.addFront(i);
	}
	
	for(int i = 0; i < value; i++) {
		list.removeFront();
	}
	
	if(list.size() != 0) {
		std::cout << "\nExpected size after " << value << " addFronts and " << value << " removeFronts: 0\n";
		std::cout << "Given size: " << list.size() << std::endl;
	}
	
	return list.size() == 0;
}

bool Test::testSizeAfterRemoveBack(int value) {
	LinkedListOfInts list;
	
	for(int i = 0; i < value; i++) {
		list.addBack(i);
	}
	
	for(int i = 0; i < value; i++) {
		list.removeBack();
	}
	
	if(list.size() != 0) {
		std::cout << "\nExpected size after " << value << " addBacks and " << value << " removeBacks: 0\n";
		std::cout << "Given size: " << list.size() << std::endl;
	}
	
	return list.size() == 0;
}

bool Test::testAddFrontOrder() {
	LinkedListOfInts list;
	
	for(int i = 0; i < 10; i++) {
		list.addFront(i);
	}
	
	std::vector<int> vec = list.toVector();
	
	bool match = true;
	
	for(int i = 0; i < 10; i++) {
		if(vec.at(vec.size() - 1 - i) != i) {
			match = false;
			break;
		}
	}
	
	return match;
}

bool Test::testAddBackOrder() {
	LinkedListOfInts list;
	
	for(int i = 0; i < 10; i++) {
		list.addBack(i);
	}
	
	std::vector<int> vec = list.toVector();
	
	bool match = true;
	
	for(int i = 0; i < 10; i++) {
		if(vec.at(i) != i) {
			match = false;
			break;
		}
	}
	
	return match;
}

void Test::runTests() {
	LinkedListOfInts list;
	
	std::cout << "\n\nStarting tests\n\nTest 1. new list is empty (using isEmpty()): ";
	testPassed(testEmptyOnEmptyList());
	std::cout << "Test 2. list of 100 elements is not empty (using isEmpty()): ";
	testPassed(testEmptyOnPopulatedList());
	std::cout << "Test 3. size of empty list is zero (using size()): ";
	testPassed(testSizeOfEmptyList());
	std::cout << "Test 4. size returns correct value after 1 addFront: ";
	testPassed(testSizeAfterAddFront(1));
	std::cout << "Test 5. size returns correct value after 1 addBack: ";
	testPassed(testSizeAfterAddBack(1));
	std::cout << "Test 6. size returns correct value after 10000 addFronts: ";
	testPassed(testSizeAfterAddFront(10000));
	std::cout << "Test 7. size returns correct value after 10000 addBacks: ";
	testPassed(testSizeAfterAddBack(10000));
	std::cout << "Test 8. search returns false when searching an empty list: ";
	testPassed(testSearchOnEmptyList(50));
	std::cout << "Test 9. search returns true when value is at the front of the list: ";
	testPassed(testSearchWhenValueIsFirst(50));
	std::cout << "Test 10. search returns true when value is at the back of the list: ";
	testPassed(testSearchWhenValueIsLast(50));
	std::cout << "Test 11. search returns true when value is in the middle of the list: ";
	testPassed(testSearch(50));
	std::cout << "Test 12. size returns correct value after 1 removeFront: ";
	testPassed(testSizeAfterRemoveFront(1));
	std::cout << "Test 13. size returns correct value after 1 removeBack: ";
	testPassed(testSizeAfterRemoveBack(1));
	std::cout << "Test 14. size returns correct value after 10000 removeFronts: ";
	testPassed(testSizeAfterRemoveFront(10000));
	std::cout << "Test 15. size returns correct value after 10000 removeBacks: ";
	testPassed(testSizeAfterRemoveBack(10000));
	std::cout << "Test 16. elements added using addFront are in correct order: ";
	testPassed(testAddFrontOrder());
	std::cout << "Test 17. elements added using addBack are in correct order: ";
	testPassed(testAddBackOrder());
	
	
	std::cout << "\nScore " << m_score << "/170\n\n";
	
}

void Test::testPassed(bool result) {
	if(result) {
		m_score += 10;
		std::cout << "PASSED\n";
	} else {
		std::cout << "FAILED\n";
	}
}
