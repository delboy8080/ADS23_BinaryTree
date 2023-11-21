// BinaryTree.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <queue>
#include "BinaryTree.h"
#include "Utils.h"
using namespace std;

int min(BSTNode<int> *tree)
{
	while (tree->getLeft() != nullptr)
	{
		tree = tree->getLeft();
	}
	return tree->getItem();
}
int max(BSTNode<int>* tree)
{
	while (tree->getRight() != nullptr)
	{
		tree = tree->getRight();
	}
	return tree->getItem();
}

void question1()
{
	//part a
	BinaryTree<int> tree1;
	for (int i = 1; i <= 15; i++)
	{
		tree1.add(i);
	}
	printBT(tree1.root);

	//part b
	BinaryTree<int> tree2;
	for (int i = 15; i >= 1; i--)
	{
		tree2.add(i);
	}
	printBT(tree2.root);

	//part c
	tree2.clear();
	tree2.add(8);
	tree2.add(4);
	tree2.add(12);
	tree2.add(2);
	tree2.add(6);
	tree2.add(1);
	tree2.add(3);
	tree2.add(5);
	tree2.add(7);
	tree2.add(10);
	tree2.add(14);
	tree2.add(9);
	tree2.add(11);
	tree2.add(13);
	tree2.add(15);
	printBT(tree2.root);

	//part d
	tree2.printPreOrder();
	//part e
	tree2.printPostOrder();
	//part f
	tree2.printInOrder();
	//part g
	cout << "Minimum Value: " << min(tree2.root) << endl;
	cout << "Maximum Value: " << max(tree2.root) << endl;

}
Book* findBookByTitle(string title, BinaryTree<Book> &books)
{
	Book* found = nullptr;
	BSTNode<Book> *cn = books.root;
	while (cn != nullptr)
	{
		//
		if (cn->getItem().title == title)
		{
			found = new Book(cn->getItem());
			break;
		}
		else if(cn->getItem().title < title)
		{
			cn = cn->getRight();
		}
		else 
		{
			cn = cn->getLeft();
		}
	}
	return found;
}

void decreasePricePre(BSTNode<Book> *node)
{
	if (node != nullptr)
	{
		Book b = node->getItem();
		b.price *= .9;
		node->setItem(b);
		decreasePricePre(node->getLeft());
		decreasePricePre(node->getRight());
	}
}
void decreasePricePost(BSTNode<Book>* node)
{
	if (node != nullptr)
	{
		
		decreasePricePre(node->getLeft());
		decreasePricePre(node->getRight());
		Book b = node->getItem();
		b.price *= .9;
		node->setItem(b);
	}
}
void decreasePriceInOrder(BSTNode<Book>* node)
{
	if (node != nullptr)
	{
		
		decreasePricePre(node->getLeft());
		Book b = node->getItem();
		b.price *= .9;
		node->setItem(b);
		decreasePricePre(node->getRight());
	}
}
void question4()
{
	BinaryTree<Book> books;
	books.add(Book("John Grisham", "The Associate", 9.99));
	books.add(Book("J. K. Rowling", "The Christmas Pig", 21.99));
	books.add(Book("John Grisham", "The Judge's List", 19.99));
	books.add(Book("J.R.R. Tolkien", "The Hobbit", 8.99));
	books.add(Book("Mary Shelly", "Frankenstein", 5.99));
	books.add(Book("Harper Lee", "To Kill a Mocking Bird", 9.99));
	
	//decreasePricePre(books.root);
	printBT(books.root);
	
	Book* found = findBookByTitle("The Judge's List", books);
	if (found != nullptr)
	{
		cout << *found << endl;
	}
	else
	{
		cout << "Book not found" << endl;
	}

	cout << endl<<endl;
	decreasePriceInOrder(books.root);
	printBT(books.root);
}
int main()
{
	BinaryTree<int> tree;
	tree.add(4);
	tree.add(2);
	tree.add(6);
	tree.add(1);
	tree.add(3);
	tree.add(5);
	tree.add(7);
	//cout <<"Count: " << tree.count() << endl;
	//printBT(tree.root);
	tree.printPreOrder();
	question4();

    return 0;
}

