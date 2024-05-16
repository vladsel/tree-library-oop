#include "BinTree.h"

int main() {
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "||<========================================>LIBRARY<=============================================>||" << endl;
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
	
	CBinTree cbn1("library.csv");
	CTreeNode ctn1;
	CTreeNode ctn2(39, "J. R. R. Tolkien", "The Lord of the Rings", 1937, 20);
	cbn1.add_book(ctn1);
	cbn1.add_book(ctn2);
	cbn1.delete_book(13);
	cout << "\t\t\t\tfirst tree:" << endl;
	cbn1.print_cbn();
	cbn1.ShowAllBooks_ByAuthor("John Irving");
	cbn1.IsBookEmpty_find("Call of the wild");

	CBinTree cbn2;
	CTreeNode ctn3(2, "Philip Pullman", "His Dark Materials", 1995, 10);
	CTreeNode ctn4(7, "J. K. Rowling", "Harry Potter and the Goblet of Fire", 2001, 5);
	CTreeNode ctn5(4, "J. K. Rowling", "Harry potter and the philosopher's stone", 1990, 10);
	CTreeNode ctn6(6, "Stephen King", "The Stand", 1978, 100);
	cbn2.add_book(ctn3);
	cbn2.add_book(ctn4);
	cbn2.add_book(ctn5);
	cbn2.add_book(ctn6);
	cbn2.delete_book(6);
	cout << endl << "\t\t\t\tsecond tree:" << endl;
	cbn2.print_cbn();
	cbn2.ShowAllBooks_ByAuthor("J. K. Rowling");
	cbn2.IsBookEmpty_find("His Dark Materials");
	return 0;
}
