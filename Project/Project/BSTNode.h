#pragma once
class BSTNode
{
public:
	int priority;
	int value;
	BSTNode* left;
	BSTNode* rigth;

public:
	BSTNode(int priority, int value);
	//int get_value() { return value; };
	//int get_priority() { return priority; };
};

