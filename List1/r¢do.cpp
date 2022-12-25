#include <iostream>
#include <string>
#include "CTable.h"
#include "Nag³ówek.h"


void v_alloc_table_fill_34(int iSize) {
	//Zadanie 1
	if (iSize < 0) {
		std::cout << "Bledna wartosc parametru iSize" << std::endl;
		return;
	}
	int* table_thirty_four;
	table_thirty_four = new int[iSize];
	for (int i = 0; i < iSize; i++) {
		table_thirty_four[i] = repeting_value;
		std::cout << ("%d \n", table_thirty_four[i]) << std::endl;
	}
	delete[] table_thirty_four;
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
	//Zadanie 2
	if (iSizeY <= 0 || iSizeX <= 0) return false;
	*piTable = new int* [iSizeX];
	for (int i = 0; i < iSizeX; i++) {
		(* piTable)[i] = new int[iSizeY];
	}
	if (piTable == NULL) return false;
	return true;
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
	//Zadanie 3
	if (iSizeY <= 0 || iSizeX <= 0) return false;
	for (int i = 0; i < iSizeX; i++) {
		delete [] (*piTable)[i];
	}
	delete [] (*piTable);
	return true;
}

void v_mod_tab(CTable* pcTab, int iNewSize) {
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
}

int main() {
	std::cout << ("Zadanie 1: ") << std::endl;
	v_alloc_table_fill_34(4);

	std::cout << ("Zadanie 2: ") << std::endl;
	int** piTable = NULL;
	if (b_alloc_table_2_dim(&piTable, 3, 5) == true) {
		std:: cout << ("Zaalokowano tablice ") << std::endl;

		std::cout << ("Zadanie 3: ") << std::endl;
		if (b_dealloc_table_2_dim(&piTable, 3, 5) == true) {
			std::cout << ("Dealokowano tablice ") << std::endl;
		}
		else {
			std::cout << ("B³¹d z dealokacj¹") << std::endl;
		}
	}

	std::cout << ("Zadanie 4: ") << std::endl;
	CTable* cTable;
	cTable = new CTable("Tablica", 15);
	cTable->toString();

	v_mod_tab(cTable, 5);
	cTable->toString();

	v_mod_tab(*cTable, 20);
	cTable->toString();

	cTable->~CTable();
	return 0;
}
