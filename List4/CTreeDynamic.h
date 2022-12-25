#pragma once
#include <vector>
#include <iostream>

template< typename T > class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(T iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic* child);
	CNodeDynamic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void setParent(CNodeDynamic* newParent);
	CNodeDynamic* getParent();
	void remove(CNodeDynamic* node);
	void vPrintUp();
	void mod1(T val, bool up);
	CNodeDynamic* findIt(T val);
private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	T i_val;
};//class CNodeDynamic
template< typename T > class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T>* pcGetRoot();
	void vPrintTree();
	void setRoot(CNodeDynamic<T>* newRoot);
	CNodeDynamic<T>* getRoot();
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
private:
	CNodeDynamic<T>* pc_root;
};

template< typename T >
std::vector<CNodeDynamic<T>*> v_children;

template< typename T >
CNodeDynamic<T>* pc_parent_node;

template< typename T >
T i_val;

template< typename T >
CNodeDynamic<T>::CNodeDynamic() {
	pc_parent_node = NULL;
}

template< typename T >
CNodeDynamic<T>::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children.at(i);
	}
}

template< typename T >
void CNodeDynamic<T>::vSetValue(T iNewVal) {
	i_val = iNewVal;
}

template< typename T >
int CNodeDynamic<T>::iGetChildrenNumber() {
	return (v_children.size());
}

template< typename T >
void CNodeDynamic<T>::vAddNewChild() {
	CNodeDynamic* newChild = new CNodeDynamic;
	newChild->setParent(this);
	v_children.push_back(newChild);
}

template< typename T >
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic* child) {
	v_children.push_back(child);
}

template< typename T >
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset > v_children.size() || iChildOffset < 0) return NULL;
	return v_children.at(iChildOffset);
}

template< typename T >
void CNodeDynamic<T>::vPrint() {
	std::cout << " " << i_val << std::endl;
}

template< typename T >
void CNodeDynamic<T>::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}

template< typename T >
void CNodeDynamic<T>::setParent(CNodeDynamic* newParent) {
	pc_parent_node = newParent;
}

template< typename T >
CNodeDynamic<T>* CNodeDynamic<T>::getParent() {
	return pc_parent_node;
}

template< typename T >
void CNodeDynamic<T>::remove(CNodeDynamic* node) {
	for (int i = 0; i < v_children.size(); i++) {
		if (node == v_children.at(i)) v_children.erase(v_children.begin() + i);
	}
}

template< typename T >
void CNodeDynamic<T>::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}

template< typename T >
void CNodeDynamic<T>::mod1(T val, bool up) {
	CNodeDynamic* searchedNode = findIt(val);
	if (up) {
		searchedNode->vPrintUp();
	}
	else {
		searchedNode->vPrintAllBelow();
	}
}

template< typename T >
CNodeDynamic<T>* CNodeDynamic<T>::findIt(T val) {
	if (i_val == val) {
		return this;
	}
	for (int i = 0; i < v_children.size(); i++) {
		CNodeDynamic* searchedNode = v_children.at(i)->findIt(val);
		if (searchedNode != NULL) return searchedNode;
	}
	return NULL;
}

//class CTreeDynamic
template< typename T >
CNodeDynamic<T>* pc_root;

template< typename T >
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic<T>;
}

template< typename T >
CTreeDynamic<T>::~CTreeDynamic() {
	delete pc_root;
}

template< typename T >
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot() {
	return(pc_root);
}

template< typename T >
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}

template< typename T >
void CTreeDynamic<T>::setRoot(CNodeDynamic<T>* newRoot) {
	delete pc_root;
	pc_root = newRoot;
}

template< typename T >
CNodeDynamic<T>* CTreeDynamic<T>::getRoot() {
	return pc_root;
}

template< typename T >
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {
	if (pcNewChildNode == NULL || pcParentNode == NULL) return false;
	if (pcNewChildNode->getParent() != NULL) pcNewChildNode->getParent()->remove(pcNewChildNode);
	pcNewChildNode->setParent(pcParentNode);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}

