Design the tree node classes CTreeNode and binary tree CBinTree and use them to write the program according to the option. The tree is not balanced.
(20.12.2020)
Option 1.
A binary tree (CBinTree) contains current information about books in the library. The tree is sorted by inventory numbers.
Information about books (CTreeNode) contains:
inventory number - m_Bookid;
author's last name - m_Author;
title – m_Title;
publication year – m_Year;
the number of copies of this book in the library - m_Quantity.

The program should provide:

initial formation of data about all books in the library in the form of a binary tree;
the output data is read from a csv file, each row of which contains a species record
m_Bookid; m_Author; m_Title; m_Year; m_Quantity;
adding data about books coming to the library;
deletion of data on books being written off (by inventory number);
information about the availability of all his books in the library is published by the author's name.
information about the availability of a book in the library is issued by name;
output to the console of information about all books.
