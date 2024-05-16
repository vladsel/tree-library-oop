/************************************************************************
 * file: BinTree.h
 * BinTree class definition
 * written: 18/12/2020
 * created by Vlad Seletkov
*************************************************************************/

#ifndef LABA_4_OOP_BINTREE_H
#define LABA_4_OOP_BINTREE_H

#include "Treenode.h"

class CBinTree {
public:
	CBinTree();
	CBinTree(const char *csv);
	~CBinTree();
	void add_book(const CTreeNode &ctn);
	void print_cbn();
	void delete_book(int id);
	void IsBookEmpty_find(const string &title);
	void ShowAllBooks_ByAuthor(const string &author);
private:
	CTreeNode *root;
	CTreeNode *add_book_private(CTreeNode *branch, const CTreeNode &ctn);
	void remove_cbn(CTreeNode *branch);
	void print_cbn_private(CTreeNode *branch);
	CTreeNode *delete_book_private(int id, CTreeNode *branch, int &flag);
	void IsBookEmpty_find_private(const string &title, CTreeNode *branch, int &quantity);
	void ShowAllBooks_ByAuthor_private(const string &author, CTreeNode *branch, int &flag);
};

#endif //LABA_4_OOP_BINTREE_H
