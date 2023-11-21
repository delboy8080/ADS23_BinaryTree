#pragma once
#include "BSTNode.h"
#include <vector>
template <class T>
class BinaryTree
{
	void addItemToArray(BSTNode<T>* node, int &pos, int *arr);
public:
	BSTNode<T> *root;
	BinaryTree();
	void add(T item);
	bool remove(T item);
	void clear();
	int count();

	T* toArray();
	void printInOrder();
	void printInOrder(BSTNode<T> *node);
	void printPreOrder();
	void printPreOrder(BSTNode<T> *node);
	void printPostOrder();
	void printPostOrder(BSTNode<T> *node);
	
	~BinaryTree();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template <class T>
void BinaryTree<T>::add(T item)
{
	if (root == nullptr)
		root = new BSTNode<T>(item);
	else
	{
		root->add(item);
	}
}
template <class T>
int BinaryTree<T>::count()
{
	if (root == nullptr)
		return 0;
	else
		return root->count();
}
template <class T>
bool BinaryTree<T>::remove(T item)
{
	BSTNode<T>* parent = nullptr;
	BSTNode<T>* toBeRemoved = root;
	bool found = false;
	while (!found && toBeRemoved != nullptr) {
		if (toBeRemoved->getItem() == item)
			found = true;
		else {
			parent = toBeRemoved;
			if (toBeRemoved->getItem() > item)
				toBeRemoved = toBeRemoved->getLeft();
			else
				toBeRemoved = toBeRemoved->getRight();

		}
	}
	if (!found)
		return false;
	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T>* newChild;
		if (toBeRemoved->getLeft() != nullptr)
		{
			newChild = toBeRemoved->getLeft();
		}
		else
		{
			newChild = toBeRemoved->getRight();
		}
		if (root == nullptr)
			root = newChild;
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}
	BSTNode<T>* smallestParent = toBeRemoved;
	BSTNode<T>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}

	toBeRemoved->setItem(smallest->getItem());
	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}
	return true;
}


/**
	Helper Function to put the binary tree into a sorted array;

*/
template <class T>
void BinaryTree<T>::addItemToArray(BSTNode<T>* node, int &pos, int *arr)
{
	if (node != nullptr)
	{
		addItemToArray(node->getLeft(), pos, arr);
		arr[pos] = node->getItem();
		pos++;
		addItemToArray(node->getRight(), pos, arr);
	}

}

/**
	This function is used to convert this binary tree into a sorted array.

*/
template <class T>
T* BinaryTree<T>::toArray()
{
	T *arr = new T[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}

template <class T>
void BinaryTree<T>::clear()
{
	delete root;
	root = nullptr;
}
template <class T>
BinaryTree<T>::~BinaryTree()
{
	delete root;
}



/*
Print the entire tree using in order traversal
*/
template<class T>
void BinaryTree<T>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}
/*
Print a subtree using in order traversal
*/
template<class T>
void BinaryTree<T>::printInOrder(BSTNode<T> *node)
{
	if (node != nullptr)
	{
		printInOrder(node->getLeft());
		cout << node->getItem() << " ";
		printInOrder(node->getRight());
	}

}
/*
Print the entire tree using pre order traversal
*/
template<class T>
void BinaryTree<T>::printPreOrder()
{
	this->printPreOrder(root);
	cout << endl;
}

/*
Print a subtree using post order traversal
*/
template<class T>
void BinaryTree<T>::printPreOrder(BSTNode<T> *node)
{
	if (node != nullptr)
	{
		cout << node->getItem() << " ";
		printPreOrder(node->getLeft());
		printPreOrder(node->getRight());
	}
	
}

/*
	Print the entire tree using post order traversal	
*/
template<class T>
void BinaryTree<T>::printPostOrder()
{
	this->printPostOrder(root);
	cout << endl;
}
/*
		Print a subtree using post order traversal
*/
template<class T>
void BinaryTree<T>::printPostOrder(BSTNode<T> *node)
{

	if (node != nullptr)
	{
		printPostOrder(node->getLeft());
		printPostOrder(node->getRight());
		cout << node->getItem()<< " ";

	}
}