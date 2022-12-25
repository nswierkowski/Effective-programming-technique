#include <iostream>
#include "CTreeDynamic.h"
#include <string>

void test_int() {
	std::cout << "\n Test dynamicznego drzewa: " << std::endl;
	CTreeDynamic<int> dynamicTree;
	int first = 1;
	int second = 2;
	int eleven = 11;
	int twelve = 12;
	int twentyOne = 21;
	int twentyTwo = 22;
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	dynamicTree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	dynamicTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	std::cout << "\n Pokaz pierwsze drzewo: " << std::endl;
	dynamicTree.pcGetRoot()->vPrintAllBelow();
}

void test_char() {
	std::cout << "\n Test dynamicznego drzewa: " << std::endl;
	CTreeDynamic<char> dynamicTree;
	dynamicTree.pcGetRoot()->vSetValue('x');
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vSetValue('a');
	dynamicTree.pcGetRoot()->pcGetChild(1)->vSetValue('a');
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue('b');
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue('b');
	dynamicTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue('c');
	dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue('c');

	std::cout << "\n Pokaz pierwsze drzewo: " << std::endl;
	dynamicTree.pcGetRoot()->vPrintAllBelow();
}

void test_str() {
	std::cout << "\n Test dynamicznego drzewa: " << std::endl;
	CTreeDynamic<std::string> dynamicTree;
	dynamicTree.pcGetRoot()->vSetValue("x(0)");
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vSetValue("a(1)");
	dynamicTree.pcGetRoot()->pcGetChild(1)->vSetValue("a(2)");
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("b(11)");
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("b(12)");
	dynamicTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue("c(21)");
	dynamicTree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue("c(22)");

	std::cout << "\n Pokaz pierwsze drzewo: " << std::endl;
	dynamicTree.pcGetRoot()->vPrintAllBelow();
}

int main() {
	test_int();
	test_char();
	test_str();
}