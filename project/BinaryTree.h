#pragma once
#include"TNode.h"
#include<iostream>
#include"ArrayStack.h"

class BinaryTree {
private:
	TNode* Root;

public:
	BinaryTree() {
		Root = nullptr;
	}
	~BinaryTree() {}
	


	void PostfixToInfix(std::string X)
	{
		ArrayStack<TNode*> Z;
		TNode* M;
		for (int i = 0; i < X.length(); i++)
		{

			if (X[i] >= 'a' && X[i] <= 'z' || X[i] >= 'A' && X[i] <= 'Z' || X[i] >= '0' && X[i] <= '9') {
				TNode* c = new TNode(X[i]);
				Z.push(c);
			}
			else if (X[i] == '*' || X[i] == '/' || X[i] == '+' || X[i] == '-' || X[i] == '^') {
				TNode* c = new TNode(X[i]);
				     Z.pop(M);
				     c->setright(M);
					 Z.pop(M);
					 c->setleft(M);
					 Z.push(c);
			}
		}
		Z.pop(M);

		if (Z.isEmpty()) Print(M);
			
	}
	void Print(TNode* subRoot) {
		//if (subRoot == nullptr) return;
		if (subRoot->getleft() != nullptr) {
			std::cout << "(";
			Print(subRoot->getleft());
		}
		std::cout << subRoot->getdata();
		if (subRoot->getright() != nullptr)
			Print(subRoot->getright());
		std::cout << ")";
	}
};