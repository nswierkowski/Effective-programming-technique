#pragma once
#include <vector>
class CTreeStatic
{
public:
	class CNodeStatic
	{
	public:
		CNodeStatic();
		~CNodeStatic();
		void vSetValue(int iNewVal);
		int iGetChildrenNumber();
		void vAddNewChild();
		void vAddNewChild(CNodeStatic newChild);
		void vSetParent(CNodeStatic* newParent);
		CNodeStatic* pcGetChild(int iChildOffset);
		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();
		CNodeStatic* getParent();
		void setParent(CNodeStatic* newParent);
		void remove(CNodeStatic* node);
		void repair(CNodeStatic* parent);
	private:
		std::vector<CNodeStatic> v_children;
		CNodeStatic* pc_parent_node;
		int value;
	};
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot() { return(&c_root); }
	void vPrintTree();
	CNodeStatic getRoot();
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
private:
	CNodeStatic c_root;
};