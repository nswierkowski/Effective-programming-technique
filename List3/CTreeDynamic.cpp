#include "CTreeDynamic.h"

//class CTreeDynamic
std::vector<CNodeDynamic*> v_children;
CNodeDynamic* pc_parent_node;
int i_val;

CNodeDynamic::CNodeDynamic() { 
	i_val = 0; 
	pc_parent_node = NULL; 
}

CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children.at(i);
	}
}
	
void CNodeDynamic::vSetValue(int iNewVal) { 
	i_val = iNewVal; 
}

int CNodeDynamic::iGetChildrenNumber() { 
	return (v_children.size()); 
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* newChild = new CNodeDynamic;
	newChild->setParent(this);
	v_children.push_back(newChild);
}
	
void CNodeDynamic::vAddNewChild(CNodeDynamic* child) {
	v_children.push_back(child);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset > v_children.size() || iChildOffset < 0) return NULL;
	return v_children.at(iChildOffset);
}
	
void CNodeDynamic::vPrint() { 
	std::cout << " " << i_val << std::endl; 
}
	
void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}
	
void CNodeDynamic::setParent(CNodeDynamic* newParent) {
	pc_parent_node = newParent;
}

CNodeDynamic* CNodeDynamic::getParent() {
	return pc_parent_node;
}

void CNodeDynamic::remove(CNodeDynamic* node) {
	for (int i = 0; i < v_children.size(); i++) {
		if (node == v_children.at(i)) v_children.erase(v_children.begin() + i);
	}
}

void CNodeDynamic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}

//class CTreeDynamic
CNodeDynamic* pc_root;

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic;
}

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}

CNodeDynamic* CTreeDynamic::pcGetRoot() { 
	return(pc_root); 
}

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}

void CTreeDynamic::setRoot(CNodeDynamic* newRoot) {
	delete pc_root;
	pc_root = newRoot;
}

CNodeDynamic* CTreeDynamic::getRoot() {
	return pc_root;
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode) {
	if (pcNewChildNode == NULL || pcParentNode == NULL) return false;
	if(pcNewChildNode->getParent() != NULL) pcNewChildNode->getParent()->remove(pcNewChildNode);
	pcNewChildNode->setParent(pcParentNode);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}
