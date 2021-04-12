#include <iostream>
using namespace std;

typedef char StackElemType;

class stack
{
public:
	stack();
	void push(StackElemType Data);
	StackElemType pop();
	StackElemType top();
	bool IsEmpty();

private:
	struct Node;
	typedef Node* Link;
	struct Node
	{
		StackElemType Item;
		Link Next;
	};
	Link Head;
	
};