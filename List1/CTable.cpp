#include "CTable.h"
#include<string>
#include <iostream>

	std::string s_name;
	int* table;
	int length;

	CTable::CTable() {
		s_name = "CTable";
		length = 0;
		table = new int[length];
		std::cout << "bezp: " + s_name << std::endl;
	}

	CTable::CTable(std::string sName, int iTableLen) {
		s_name = sName;
		length = iTableLen;
		table = new int[length];
	}

	CTable::CTable(CTable& pcOther) {
		s_name = pcOther.getSName() + "_copy";
		length = pcOther.getLength();
		table = new int[length];
		for (int i = 0; i < length; i++) {
			table[i] = pcOther.table[i];
		}
		std::cout << ("Kopiuj " + s_name) << std::endl;
	}

	std::string CTable:: getSName() {
		return s_name;
	}

	int CTable::getLength() {
		return length;
	}

	int* CTable::getTable() {
		return table;
	}

	CTable:: ~CTable() {
		std:: cout << ("Usuwam " + s_name) << std::endl;
		delete []table;
	}

	void CTable:: vSetName(std::string sName) {
		s_name = sName;
	}

	bool CTable:: bSetNewSize(int iTableLen) {
		if (iTableLen <= 0) return false;
		int* newTable;
		newTable = new int[iTableLen];
		if (iTableLen >= length) {
			for (int i = 0; i < length; i++) {
				newTable[i] = table[i];
			}
		}
		else {
			for (int i = 0; i < iTableLen; i++) {
				newTable[i] = table[i];
			}
		}
		length = iTableLen;
		delete[] table;
		table = newTable;
		return true;
	}

	CTable* CTable:: pcClone() {
		return new CTable(*this);
	}

	void CTable::toString() {
		std::cout << "SName: " + s_name + ", length " << length << std::endl;
	}
;