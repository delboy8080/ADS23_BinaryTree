#pragma once
#include <string>
#include <iostream>

using namespace std;
struct Book
{
	string author;
	string title;
	double price;
	Book()
	{

	}
	Book(string author, string title, double price)
	{
		this->author = author;
		this->title = title;
		this->price = price;
	}
	friend ostream& operator<<(ostream& out, Book& b) 
	{
		out << b.title << " by " << b.author << "(" << b.price << ")";
		return out;
	}
	bool operator<(Book& b)
	{
		return title < b.title;
	}
	bool operator>(Book& b)
	{
		return title > b.title;
	}
	bool operator==(Book& b)
	{
		return title == b.title;
	}
};
ostream& operator<<(ostream& out, Book* b)
{
	out << b->title << " by " << b->author << "(" << b->price << ")";
	return out;
}

/*
recursive function to display a binary tree
*/
template <class T>
void printBT(const std::string& prefix, BSTNode<T>* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "<--" : ">--");

		// print the value of the node
		std::cout << node->getItem() << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
	}
}
/*
Display function to print the tree
*/
template <class T>
void printBT(BSTNode<T>* node)
{
	printBT("", node, true);
}

/*
Recursive Function to add each element when balancing a binary tree
*/
void createBalancedTree(BinaryTree<int> &tree, int min, int max, int *arr)
{
	if (min < max)
	{
		int mid = (min + max) / 2;
		tree.add(arr[mid]);
		createBalancedTree(tree, min, mid, arr);
		createBalancedTree(tree, mid + 1, max, arr);
	}
}
/*
Recursive Function used to balance a binary tree
*/
void balance(BinaryTree<int> &tree)
{
	int *arr = tree.toArray();
	int max = tree.count();
	tree.clear();
	createBalancedTree(tree, 0, max, arr);
	delete[] arr;

}