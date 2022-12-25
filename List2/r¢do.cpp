#include "CTable.h"
#include <string>



int main() {
	//Zadanie 1
	//CTable c_tab_0, c_tab_1;
	//c_tab_0.bSetNewSize(6);
	//c_tab_1.bSetNewSize(4);
	//c_tab_0 = c_tab_1;
	// Program nie mo¿e siê wykonaæ

	//Zadanie 3
	//CTable c_tab_0, c_tab_1;
	//c_tab_0.bSetNewSize(6);
	//c_tab_1.bSetNewSize(4);
	///* initialize table */
	//c_tab_0 = c_tab_1;
	//c_tab_1.vSetValueAt(2, 123);
	//c_tab_0.vPrint();
	//c_tab_1.vPrint();

	//Zadanie 4
	CTable first;
	first.bSetNewSize(3);
	first.vSetName("first");

	CTable second;
	second.bSetNewSize(4);
	second.vSetName("second");

	for (int i = 0; i < second.getLength(); i++) {
		if (i < first.getLength()) first.vSetValueAt(i, i);
		second.vSetValueAt(i, 2*i);
	}

	(first + second).vPrint();
}
