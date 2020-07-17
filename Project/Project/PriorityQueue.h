#pragma once
#include "BSTNode.h"

class PriorityQueue
{
public:
	PriorityQueue(bool(*relation)(int a, int b));
	~PriorityQueue();
	void push(int value, int priority);
	void pop(int& value, int& priority);
	void top(int& value, int& priority);
	bool is_empty() { return this->root == nullptr; };
	//void in_order();
	void destroy();

private:
	bool(*relation)(int p1, int p2);
	BSTNode* root;
	BSTNode* find_parent(BSTNode* n);
};

//void in_order_tree_walk(BSTNode* x);