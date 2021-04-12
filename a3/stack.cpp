#include <iostream>
#include "stack.h"
using namespace std;

stack :: stack()
{
	Head = NULL;
}

void stack :: push(StackElemType Data)
{
	Link AddedNode;
	AddedNode = new Node;
	if (AddedNode == NULL)
	{
		printf("\nAllocation failed");
	}
	else
	{
		AddedNode->Item = Data;
		AddedNode->Next = Head;
		Head = AddedNode;
	}
}

StackElemType stack :: pop()
{
	if(Head==NULL)
	{
		return 0;
	}
	else
	{
		Link Index = Head;
		Head = Head->Next;
		return (Index->Item);
	}
}

StackElemType stack :: top()
{
	if(Head==NULL)
	{
		return 0;
	}
	else
	{
		return (Head->Item);
	}
}

bool stack :: IsEmpty()
{
	return bool(Head==NULL);
}