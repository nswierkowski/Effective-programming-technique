#include "CTreeStatic.h"
#include <iostream>

//CNodeStatic atributes
std::vector<CTreeStatic::CNodeStatic> v_children;
CTreeStatic::CNodeStatic* pc_parent_node;
int value;

//CNodeStatic methods
CTreeStatic::CNodeStatic::CNodeStatic() {
	value = 0;
	pc_parent_node = NULL;
}

CTreeStatic::CNodeStatic::~CNodeStatic() {}

void CTreeStatic::CNodeStatic::vSetValue(int iNewVal) {
	value = iNewVal;
}

int CTreeStatic::CNodeStatic::iGetChildrenNumber() {
	return (v_children.size());
}

void CTreeStatic::CNodeStatic::vAddNewChild() {
	CNodeStatic child;
	child.vSetParent(this);
	v_children.push_back(child);
}

void CTreeStatic::CNodeStatic::vAddNewChild(CTreeStatic::CNodeStatic newChild) {
	v_children.push_back(newChild);
	newChild.repair(&newChild);
}

void CTreeStatic::CNodeStatic::repair(CTreeStatic::CNodeStatic* parent) {
	if (parent == NULL) return;
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i).setParent(parent);
		v_children.at(i).repair(&v_children.at(i));
	}
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0) {
		return NULL;
	}
	return &(v_children.at(iChildOffset));
}

void CTreeStatic::CNodeStatic::vPrint() {
	std::cout << " " << value << std::endl;
}

void CTreeStatic::CNodeStatic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i).vPrintAllBelow();
	}
}
void CTreeStatic::CNodeStatic::vSetParent(CNodeStatic* newParent) {
	pc_parent_node = newParent;
}

void CTreeStatic::CNodeStatic::vPrintUp() {
	if (pc_parent_node == NULL) vPrint();
	else {
		vPrint();
		pc_parent_node->vPrintUp();
	}
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::getParent() {
	return pc_parent_node;
}

void CTreeStatic::CNodeStatic::setParent(CNodeStatic* newParent) {
	pc_parent_node = newParent;
}

void CTreeStatic::CNodeStatic::remove(CTreeStatic::CNodeStatic* node) {
	for (int i = 0; i < v_children.size(); i++) {
		if (node == &v_children.at(i)) v_children.erase(v_children.begin() + i);
	}
}

//CTreeStatic atribute
CTreeStatic::CNodeStatic c_root;

//CTree methods
CTreeStatic::CTreeStatic() {}

CTreeStatic::~CTreeStatic() {}

CTreeStatic::CNodeStatic* pcGetRoot() {
	return(&c_root);
}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}


bool  CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic* pcParentNode, CTreeStatic::CNodeStatic* pcNewChildNode) {
	if (pcNewChildNode == NULL) return false;
	CTreeStatic::CNodeStatic* oldParent = pcNewChildNode->getParent();
	pcNewChildNode->setParent(pcParentNode);
	if (pcParentNode != NULL) pcParentNode->vAddNewChild(*pcNewChildNode);
	if (oldParent != NULL) oldParent->remove(pcNewChildNode);
	return true;
}