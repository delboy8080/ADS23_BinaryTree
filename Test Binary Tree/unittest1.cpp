#include "CppUnitTest.h"
#include "../BinaryTree/BinaryTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBinaryTree
{		
	TEST_CLASS(TestBSTNode)
	{
	public:
		/*
			Test to ensure the data is set in the 
			BSTNode constructor and left, right, parent are nullptr
		*/
		TEST_METHOD(TestConstructor)
		{
			BSTNode<int> node(1);
			Assert::AreEqual(1, node.getItem());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
			Assert::IsNull(node.getParent());

		}

		/*
			Test Add to add a node as a child. As this is 
			A Binary Search Tree, all items add should remain in order.
			By Adding 2 to a node wiht a value of 4, the new node
			should be on the left.
		*/
		TEST_METHOD(TestAddLessThan)
		{
			BSTNode<int> node(4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getLeft());
			node.add(2);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(2, node.getLeft()->getItem());
		}
		/*
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 6 to a node wiht a value of 4, the new node
		should be on the right.
		*/
		TEST_METHOD(TestAddGreaterThan)
		{
			BSTNode<int> node(4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getRight());
			node.add(6);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(6, node.getRight()->getItem());
		}
		/*
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 6 to a node wiht a value of 4, the new node
		should be on the right. If we then add two children 5 and 7
		They should appear as follows
					4
				   / \
				      6
					 / \
					5   7
		*/
		TEST_METHOD(TestAddGreaterThanChildren)
		{
			BSTNode<int> node(4);
			node.add(6);
			BSTNode<int> *right = node.getRight();
			node.add(5);
			node.add(7);
			Assert::IsNotNull(right->getLeft());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::IsNotNull(right->getRight());
			Assert::AreEqual(7, right->getRight()->getItem());

		}

		/*
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 2 to a node wiht a value of 4, the new node
		should be on the left. If we then add two children 1 and 3
		They should appear as follows
				 4
				/ \
			   2
			  / \
			 1   3
		*/
		TEST_METHOD(TestAddLessThanChildren)
		{
			BSTNode<int> node(4);
			node.add(2);
			BSTNode<int> *left = node.getLeft();
			node.add(1);
			node.add(3);
			Assert::IsNotNull(left->getLeft());
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNotNull(left->getRight());
			Assert::AreEqual(3, left->getRight()->getItem());

		}

		/*
			Test the count method returns the correct value.
			to test this we will use the following tree
					4
				   / \
				  2   6
				 / \ / \
				1  3 5  7

		*/
		TEST_METHOD(TestCount)
		{
			BSTNode<int> node(4);
			node.add(2);
			node.add(6);
			BSTNode<int> *left = node.getLeft();
			node.add(1);
			node.add(3);
			node.add(5);
			node.add(7);
			Assert::AreEqual(7, node.count());
			
		}
	};
}