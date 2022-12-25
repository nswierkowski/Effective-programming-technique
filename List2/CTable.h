#pragma once
#include<string>
#include<iostream>

class CTable
{
private:
	std::string s_name;
	int length;
	int* table;

public:
	CTable();
	~CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	std::string getSName();
	int getLength();
	int* getTable();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	void toString();

	//Lista 2
	void operator=(const CTable& pcOther);
	void vSetValueAt(int offSet, int value);
	void vPrint();
	CTable operator+(const CTable& pcOther);

};