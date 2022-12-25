#include "CTreeStatic.h"
#include "CTreeDynamic.h"
#include <iostream>

void v_static_tree_test()
{
	std::cout << "\n Test statycznego drzewa: " << std::endl;
	CTreeStatic staticTree;
	staticTree.pcGetRoot()->vAddNewChild();
	staticTree.pcGetRoot()->vAddNewChild();
	staticTree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	staticTree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	staticTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	staticTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	staticTree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	staticTree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	staticTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	staticTree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	staticTree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	staticTree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	std::cout << "\n Rodzice: " << std::endl;
	staticTree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

	CTreeStatic staticTree2;
	staticTree2.pcGetRoot()->vAddNewChild();
	staticTree2.pcGetRoot()->vAddNewChild();
	staticTree2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	staticTree2.pcGetRoot()->pcGetChild(1)->vSetValue(3);
	staticTree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	staticTree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	staticTree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	staticTree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	staticTree2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	staticTree2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(31);
	staticTree2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(32);

	std::cout << "\n Pokaz pierwsze drzewo: " << std::endl;
	staticTree.pcGetRoot()->vPrintAllBelow();
	std::cout << "\n Pokaz drugie drzewo: " << std::endl;
	staticTree2.pcGetRoot()->vPrintAllBelow();
	staticTree.bMoveSubtree(staticTree.pcGetRoot()->pcGetChild(0), staticTree2.pcGetRoot()->pcGetChild(1));
	std::cout << "\n Nowe drzewo: " << std::endl;
	staticTree.pcGetRoot()->vPrintAllBelow();
}//void v_tree_test()

void v_dynamic_tree_test()
{
	std::cout << "\n Test dynamicznego drzewa: " << std::endl;
	CTreeDynamic dynamicTree;
	dynamicTree.getRoot()->vAddNewChild();
	dynamicTree.getRoot()->vAddNewChild();
	dynamicTree.getRoot()->pcGetChild(0)->vSetValue(1);
	dynamicTree.getRoot()->pcGetChild(1)->vSetValue(2);
	dynamicTree.getRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.getRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.getRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	dynamicTree.getRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	dynamicTree.getRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.getRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree.getRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	dynamicTree.getRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//Test 
	CTreeDynamic dynamicTree2;
	dynamicTree2.getRoot()->vAddNewChild();
	dynamicTree2.getRoot()->vAddNewChild();
	dynamicTree2.getRoot()->pcGetChild(0)->vSetValue(1);
	dynamicTree2.getRoot()->pcGetChild(1)->vSetValue(3);
	dynamicTree2.getRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree2.getRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree2.getRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	dynamicTree2.getRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	dynamicTree2.getRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree2.getRoot()->pcGetChild(1)->vAddNewChild();
	dynamicTree2.getRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(31);
	dynamicTree2.getRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(32);

	std::cout << "\n Pokaz pierwsze drzewo: " << std::endl;
	dynamicTree.getRoot()->vPrintAllBelow();
	std::cout << "\n Pokaz drugie drzewo: " << std::endl;
	dynamicTree2.getRoot()->vPrintAllBelow();
	dynamicTree.bMoveSubtree(dynamicTree.getRoot()->pcGetChild(0), dynamicTree2.getRoot()->pcGetChild(1));
	std::cout << "\n Wynik: " << std::endl;
	dynamicTree.getRoot()->vPrintAllBelow();

}//void v_tree_test()

int main() {
	v_static_tree_test();
	v_dynamic_tree_test();
}