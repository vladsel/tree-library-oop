/************************************************************************
 * file: Treenode.h
 * Treenode class definition
 * written: 18/12/2020
 * author: Vlad Seletkov
*************************************************************************/

#ifndef LABA_4_OOP_TREENODE_H
#define LABA_4_OOP_TREENODE_H

#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)

using std::string;
using std::cout;
using std::endl;

class CTreeNode {
public:
	CTreeNode();
	CTreeNode(const CTreeNode &ctn);
	CTreeNode(int id, string author, string title, int year, int quantity);
	void print_ctn();
	friend class CBinTree;
private:
	int m_Bookid;
	string m_Author;
	string m_Title;
	int m_Year;
	int m_Quantity;
	CTreeNode *left;
	CTreeNode *right;
};

#endif //LABA_4_OOP_TREENODE_H
