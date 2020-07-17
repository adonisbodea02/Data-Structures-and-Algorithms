#include "BSTNode.h"

BSTNode::BSTNode(int priority, int value)
{
	this->priority = priority;
	this->value = value;
	this->left = nullptr;
	this->rigth = nullptr;
}
