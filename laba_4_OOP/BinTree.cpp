/************************************************************************
* file: BinTree.cpp
* These functions are declared in the include file "BinTree.h".
* related files: none
* author: Vlad Seletkov
* written: 18/12/2020
* last modified: 20/12/2020
************************************************************************/

#include "BinTree.h"

CBinTree::CBinTree() {
	this->root = nullptr;
}

CBinTree::CBinTree(const char *csv) {
	this->root = nullptr;
	if (csv == nullptr) {
		cout << "CBinTree() csv nullptr error" << endl;
		exit(1);
	}
	FILE *f_ptr_csv = nullptr;
	f_ptr_csv = fopen(csv, "r");
	if (f_ptr_csv == nullptr) {
		cout << "CBinTree() f_ptr_csv nullptr error" << endl;
		exit(1);
	}
	CTreeNode ctn;
	char temp[256] = { 0 };
	while (1) {
		fgets(temp, 256, f_ptr_csv);
		if (feof(f_ptr_csv))
			break;
		char *str = nullptr;
		str = strtok(temp, ";\n");
		if (str == nullptr || atoi(str) <= 0) {
			cout << "CBinTree() str == nullptr || atoi(str) <= 0 csv error" << endl;
			fclose(f_ptr_csv);
			exit(1);
		}
		ctn.m_Bookid = atoi(str);
		str = strtok(nullptr, ";\n");
		if (str == nullptr || strlen(str) == 0) {
			cout << "CBinTree() str == nullptr || strlen(str) csv error" << endl;
			fclose(f_ptr_csv);
			exit(1);
		}
		ctn.m_Author = str;
		str = strtok(nullptr, ";\n");
		if (str == nullptr || strlen(str) == 0) {
			cout << "CBinTree() str == nullptr || strlen(str) csv error" << endl;
			fclose(f_ptr_csv);
			exit(1);
		}
		ctn.m_Title = str;
		str = strtok(nullptr, ";\n");
		if (str == nullptr || atoi(str) <= 0) {
			cout << "CBinTree() str == nullptr || atoi(str) <= 0 csv error" << endl;
			fclose(f_ptr_csv);
			exit(1);
		}
		ctn.m_Year = atoi(str);
		str = strtok(nullptr, ";\n");
		if (str == nullptr || atoi(str) < 0) {
			cout << "CBinTree() str == nullptr || atoi(str) <= 0 csv error" << endl;
			fclose(f_ptr_csv);
			exit(1);
		}
		ctn.m_Quantity = atoi(str);
		add_book(ctn);
	}
	fclose(f_ptr_csv);
}

CBinTree::~CBinTree() {
	this->remove_cbn(this->root);
}

void CBinTree::remove_cbn(CTreeNode *branch) {
	if (branch == nullptr)
		return;
	this->remove_cbn(branch->left);
	this->remove_cbn(branch->right);
	delete branch;
	return;
}

void CBinTree::add_book(const CTreeNode &ctn) {
	this->root = this->add_book_private(this->root, ctn);
}

CTreeNode *CBinTree::add_book_private(CTreeNode *branch, const CTreeNode &ctn) {
	if (branch == nullptr) {
		branch = new CTreeNode(ctn);
		return branch;
	}
	if (ctn.m_Bookid > branch->m_Bookid)
		branch->right = this->add_book_private(branch->right, ctn);
	else if (ctn.m_Bookid < branch->m_Bookid)
		branch->left = this->add_book_private(branch->left, ctn);
	else 
		branch->m_Quantity += ctn.m_Quantity;
	return branch;
}

void CBinTree::print_cbn() {
	this->print_cbn_private(this->root);
}

void CBinTree::print_cbn_private(CTreeNode *branch) {
	if (branch == nullptr) 
		return;
	this->print_cbn_private(branch->left);
	branch->print_ctn();
	this->print_cbn_private(branch->right);
	return;
}

void CBinTree::IsBookEmpty_find(const string &title) {
	if (title.empty() == true) {
		cout << endl << "IsBookEmpty_find() error title.empty() == true" << endl;
		return;
	}
	int quantity = 0;
	this->IsBookEmpty_find_private(title, this->root, quantity);
	if (quantity <= 0)
		cout << endl << "there are no books with title: " << title << endl;
	else
		cout << endl << "there are books with title: " << title << " <--> quantity: " << quantity << endl;
}

void CBinTree::IsBookEmpty_find_private(const string &title, CTreeNode *branch, int &quantity) {
	if (branch == nullptr)
		return;
	if (branch->m_Title == title)
		quantity += branch->m_Quantity;
	this->IsBookEmpty_find_private(title, branch->left, quantity);
	this->IsBookEmpty_find_private(title, branch->right, quantity);
	return;
}

void CBinTree::ShowAllBooks_ByAuthor(const string &author) {
	if (author.empty() == true) {
		cout << endl << "ShowAllBooks_ByAuthor() error author.empty() == true" << endl;
		return;
	}
	int flag = 0;
	this->ShowAllBooks_ByAuthor_private(author, this->root, flag);
	if (flag == 0)
		cout << endl << "unknown author: " << author << endl;
}

void CBinTree::ShowAllBooks_ByAuthor_private(const string &author, CTreeNode *branch, int &flag) {
	if (branch == nullptr)
		return;
	if (branch->m_Author == author) {
		flag = 1;
		if (branch->m_Quantity <= 0)
			cout << endl << "there are no books with title: " << branch->m_Title << " <--> by author: " << branch->m_Author << endl;
		else
			cout << endl << "there are books with title: " << branch->m_Title << " <--> by author: " << branch->m_Author << " <--> quantity: " << branch->m_Quantity << endl;
	}
	this->ShowAllBooks_ByAuthor_private(author, branch->left, flag);
	this->ShowAllBooks_ByAuthor_private(author, branch->right, flag);
	return;
}

void CBinTree::delete_book(int id) {
	if (id <= 0) {
		cout << endl << "delete_book() error id <= 0" << endl;
		return;
	}
	if (this->root->m_Bookid == id) {
		this->root->m_Bookid = 0;
		this->root->m_Author = "nothing";
		this->root->m_Title = "nothing";
		this->root->m_Year = 0;
		this->root->m_Quantity = 0;
	}
	else {
		int flag = 0;
		this->delete_book_private(id, this->root, flag);
		if (flag == 0)
			cout << endl << "unknown id: " << id << endl;
	}
}

CTreeNode *CBinTree::delete_book_private(int id, CTreeNode *branch, int &flag) {
	if (branch == nullptr)
		return branch;
	if (branch->m_Bookid == id) {
		flag = 1;
		CTreeNode *next_branch;
		if (branch->right != nullptr) {
			CTreeNode *temp = branch->right;
			if (temp->left != nullptr) {
				CTreeNode *temp_min = temp->left;
				while (temp_min->left != nullptr) {
					temp = temp_min;
					temp_min = temp->left;
				}
				temp->left = temp_min->right;
				temp_min->left = branch->left;
				temp_min->right = branch->right;
				next_branch = temp_min;
			}
			else {
				temp->left = branch->left;
				next_branch = temp;
			}
		}
		else 
			next_branch = branch->left;
		delete branch;
		return next_branch;
	}
	else if (branch->m_Bookid > id)
		branch->left = this->delete_book_private(id, branch->left, flag);
	else 
		branch->right = this->delete_book_private(id, branch->right, flag);
	return branch;
}
