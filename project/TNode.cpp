#include "TNode.h"

TNode::TNode(char val)
{
	data = val;
	left =  nullptr;
	right = nullptr;
}


void TNode::setdata(char x)
{
	data = x;
}
char TNode::getdata()
{
	return data;
}
void TNode::setleft(TNode* x)
{
	left = x;
}
TNode*& TNode::getleft()
{
	return left;
}
void TNode::setright(TNode*x)
{
	right = x;
}

TNode*& TNode::getright()
{
	 return right;
}
