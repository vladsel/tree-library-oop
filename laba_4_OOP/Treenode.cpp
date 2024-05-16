/************************************************************************
* file: Treenode.cpp
* These functions are declared in the include file "Treenode.h".
* related files: none
* author: Vlad Seletkov
* written: 18/12/2020
* last modified: 20/12/2020
************************************************************************/

#include "Treenode.h"

CTreeNode::CTreeNode() {
	this->m_Bookid = 0;
	this->m_Author = "nothing";
	this->m_Title = "nothing";
	this->m_Year = 0;
	this->m_Quantity = 0;
	this->left = nullptr;
	this->right = nullptr;
}

CTreeNode::CTreeNode(int id, string author, string title, int year, int quantity) {
	if (id <= 0 || year <= 0 || quantity < 0) {
		cout << "error constructor CTreeNode() id <= 0 || year <= 0 || quantity < 0" << endl;
		exit(1);
	}
	if (author.empty() == true || title.empty() == true) {
		cout << "error constructor CTreeNode() author.empty() == true || title.empty() == true" << endl;
		exit(1);
	}
	this->m_Bookid = id;
	this->m_Author = author;
	this->m_Title = title;
	this->m_Year = year;
	this->m_Quantity = quantity;
	this->left = nullptr;
	this->right = nullptr;
}

CTreeNode::CTreeNode(const CTreeNode &ctn) {
	this->m_Bookid = ctn.m_Bookid;
	this->m_Author = ctn.m_Author;
	this->m_Title = ctn.m_Title;
	this->m_Year = ctn.m_Year;
	this->m_Quantity = ctn.m_Quantity;
	this->left = nullptr;
	this->right = nullptr;
}

void CTreeNode::print_ctn() {
	if (this != nullptr) {
		cout << this->m_Bookid << " ; " << this->m_Author << " ; " << this->m_Title << " ; " << this->m_Year << " ; " << this->m_Quantity << endl;
	}
	else {
		cout << "\nprint_ctn() this == nullptr" << endl;
		exit(1);
	}
}
