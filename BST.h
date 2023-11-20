#pragma once

#include <iostream>
#include <stack>
#include <queue>
#include<string>
#include<cstring>
#include"customerclass.h"
using namespace std;

class BNode {
public:
	BNode();
	BNode(Customer*);
	void setLeftChild(BNode* n);
	BNode* getLeftChild();
	void setRightChild(BNode* n);
	BNode* getRightChild();
	void setData(Customer* data);
	Customer* getData();
private:
	Customer* data;
	BNode* leftchild;
	BNode* rightchild;
};


BNode::BNode() {
	data = nullptr;
	leftchild = nullptr;
	rightchild = nullptr;

}
BNode::BNode(Customer* pVal) {
	data = pVal;
	leftchild = nullptr;
	rightchild = nullptr;

}

void BNode::setData(Customer* pdata) {
	data = pdata;
}

Customer* BNode::getData() {
	return data;
}

BNode* BNode::getLeftChild() {
	return leftchild;
}

BNode* BNode::getRightChild() {
	return rightchild;
}

void BNode::setLeftChild(BNode* n) {
	leftchild = n;
}

void BNode::setRightChild(BNode* n) {
	rightchild = n;
}

class BinarySearchTree {
public:
	BinarySearchTree();
	void insert(Customer* data);
	bool search();
	void LevelOrder();
	bool setPrice(int m, int b);
	int remainingbal(int m);
private:
	BNode* root;
};

BinarySearchTree::BinarySearchTree() {
	root = 0;
}

void BinarySearchTree::insert(Customer* pVal) {
	BNode* n = root;
	BNode* parent = 0;
	while (n)
	{
		parent = n;
		int cmp = n->getData()->getMobile() - pVal->getMobile();
		if (cmp == 0)
		{
			cout << "Value already detected" << endl;
			return;
		}
		else if (cmp < 0)
		{
			n = n->getRightChild();
		}
		else
		{
			n = n->getLeftChild();
		}

	}

	BNode* newNode = new BNode();
	newNode->setData(pVal);
	if (parent) {
		int cmp = parent->getData()->getMobile() - pVal->getMobile();
		if (cmp < 0)
		{
			parent->setRightChild(newNode);
		}
		else
		{
			parent->setLeftChild(newNode);
		}
	}
	if (!root)
	{
		root = newNode;
		return;
	}

}

bool BinarySearchTree::search()
{
	bool flag = false;
	int pVal;
	cout << "Enter the number of the user you want to search: ";
	cin >> pVal;

	BNode* n = root;
	while (n)
	{
		int cmp = n->getData()->getMobile()-pVal;
		if (cmp == 0)
		{
			flag = true;
			break;
		}
		else if (cmp < 0)
		{
			n = n->getRightChild();
		}
		else
		{
			n = n->getLeftChild();
		}
	}
	
	if (flag)
	{
		cout << "Displaying customer." << endl;
		cout << "\n_________________________________________________________\n";
		cout << left << setw(15) << "Name";
		cout << left << setw(14) << "Mobile";
		cout << left << setw(20) << "Address";
		cout << left << setw(10) << "Balance";
		cout << endl;
		cout << "_________________________________________________________\n";
		cout << *n->getData() << endl;
	}
	else
	{
		cout << "Customer not found. " << endl;
		flag = false;
	}

	return flag;
}
void BinarySearchTree::LevelOrder()
{
	cout << " Displaying customers." << endl;
	cout << "\n_________________________________________________________\n";
	cout << left << setw(15) << "Name";
	cout << left << setw(14) << "Mobile";
	cout << left << setw(20) << "Address";
	cout << left << setw(10) << "Balance";
	cout << endl;
	cout << "_________________________________________________________\n";
	BNode* n;
	queue<BNode*>* q = new queue<BNode*>();
	if (root)
	{
		q->push(root);
		while (!q->empty())
		{
			n = q->front();
			q->pop();
			cout << *n->getData();
			if (n->getLeftChild())
			{
				q->push(n->getLeftChild());
			}
			if (n->getRightChild())
			{
				q->push(n->getRightChild());
			}
		}
	}
	
}

bool BinarySearchTree::setPrice(int m, int b)
{
	bool flag = false;
	BNode* n = root;
	while (n)
	{
		int cmp = n->getData()->getMobile() - m;
		if (cmp == 0)
		{
			int bal = n->getData()->getBalance();
			n->getData()->setBalance(bal - b);
			flag = true;
			break;
		}
		else if (cmp < 0)
		{
			n = n->getRightChild();
		}
		else
		{
			n = n->getLeftChild();
		}
	}

	if (!flag)
		cout << "Customer not found. " << endl;

	return flag;
}

int BinarySearchTree::remainingbal(int m)
{
	BNode* n = root;
	while (n)
	{
		int cmp = n->getData()->getMobile() - m;
		if (cmp == 0)
		{
			return n->getData()->getBalance();
		}
		else if (cmp < 0)
		{
			n = n->getRightChild();
		}
		else
		{
			n = n->getLeftChild();
		}
	}

	return 0;
}