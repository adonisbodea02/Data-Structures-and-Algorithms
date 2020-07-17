#include "PriorityQueue.h"
#include <string>
#include <iostream>

PriorityQueue::~PriorityQueue()
{
	this->destroy();
}

PriorityQueue::PriorityQueue(bool(*relation)(int a, int b))
{
	this->relation = relation;
	this->root = nullptr;
}


void PriorityQueue::push(int value, int priority)
{
	BSTNode* z = new BSTNode(priority, value);
	BSTNode* y = nullptr;
	BSTNode* x = root;
	while (x != nullptr)
	{
		y = x;
		if (relation(z->priority, x->priority))
			x = x->left;
		else
			x = x->rigth;
	}
	if (y == nullptr)
		root = z;
	else
		if (relation(z->priority, y->priority))
			y->left = z;
		else
			y->rigth = z;
}

void PriorityQueue::pop(int & value, int & priority)
{
	if (this->is_empty() == false)
	{
		BSTNode* x = root;
		while (x->rigth != nullptr)
			x = x->rigth;
		value = x->value;
		priority = x->priority;
		if (x == root)
		{
			root = x->left;
			delete x; 
		}
		else
		{
			if (x->left == nullptr)
			{
				BSTNode* parent = this->find_parent(x);
				parent->rigth = nullptr;
				delete x;
			}
			else
			{
				BSTNode* parent = this->find_parent(x);
				parent->rigth = x->left;
				delete x;
			}
		}
	}
	else
	{
		std::string s = "Priority queue is empty!\n";
		throw(s);
	}
}

void PriorityQueue::top(int & value, int & priority)
{
	if (this->is_empty() == false)
	{
		BSTNode* x = root;
		while (x->rigth != nullptr)
			x = x->rigth;
		value = x->value;
		priority = x->priority;
	}
	else
	{
		std::string s = "Priority queue is empty!\n";
		throw(s);
	}
}

/*
void PriorityQueue::in_order()
{
	in_order_tree_walk(root);
}
*/

void PriorityQueue::destroy()
{
	while (this->is_empty() == false)
	{
		BSTNode* x = root;
		while (x->rigth != nullptr)
			x = x->rigth;
		if (x == root)
		{
			root = x->left;
			delete x;
		}
		else
		{
			if (x->left == nullptr)
			{
				BSTNode* parent = this->find_parent(x);
				parent->rigth = nullptr;
				delete x;
			}
			else
			{
				BSTNode* parent = this->find_parent(x);
				parent->rigth = x->left;
				delete x;
			}
		}
	}
}

BSTNode * PriorityQueue::find_parent(BSTNode * n)
{
	BSTNode* c = root;
	while (c != nullptr && c->left != n && c->rigth != n)
		if (relation(n->priority, c->priority))
				c = c->left;
		else
				c = c->rigth;
	return c;
}

/*
void in_order_tree_walk(BSTNode * x)
{
	if (x != nullptr)
	{
		in_order_tree_walk(x->left);
		std::cout << x->value << " ";
		in_order_tree_walk(x->rigth);
	}
}
*/
