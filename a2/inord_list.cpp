#include "inord_list.h"
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

inord_list :: inord_list()
{
	Head = NULL;
	Current = NULL;
}

int inord_list :: insert(const ListElemType &Data, unsigned int Line)
{
	Link AddedNode;
	Link Pred;
	Link ptr;
	unsigned int temp;
	AddedNode = new Node;

	if (AddedNode == NULL)
	{
		return 0;
	}
	else
	{
		AddedNode->Item = Data;
		AddedNode->LineNum = Line;
	}

	if ( (Head == NULL) || (Data < Head->Item) )
	{
		AddedNode->Next = Head;
		Head = AddedNode;
		return 1;
	}

	else if ( Data == Head->Item )
	{
		AddedNode->Next = Head;
		Head = AddedNode;
		ptr = AddedNode;
		while((ptr!=NULL) && ((ptr->Next)!=NULL) && ((ptr->Item) == (ptr->Next->Item)) )
		{
			if ((ptr->LineNum) > (ptr->Next->LineNum))
			{
				temp = (ptr->LineNum);
				(ptr->LineNum) = (ptr->Next->LineNum);
				(ptr->Next->LineNum) = temp;
			}
			ptr = ptr->Next;
		}
		return (-1);
	}

	else
	{
		Pred = Head;
		while( (Pred->Next!=NULL) && ((Pred->Next->Item)<Data) )
		{
			Pred = Pred->Next;
		}

		AddedNode->Next = Pred->Next;
		Pred->Next = AddedNode;

		if (AddedNode->Next == NULL)
		{
			return 1;
		}
		else if (Data == (AddedNode->Next->Item))
		{
			ptr = AddedNode;
			while((ptr!=NULL) && ((ptr->Next)!=NULL) && ((ptr->Item) == (ptr->Next->Item)) )
			{
				if ((ptr->LineNum) > (ptr->Next->LineNum))
				{
					temp = (ptr->LineNum);
					(ptr->LineNum) = (ptr->Next->LineNum);
					(ptr->Next->LineNum) = temp;
				}
				ptr = ptr->Next;
			}
			return (-1);
		}
		else
		{
			return 1;
		}
	}
}

void inord_list :: FreqWord()
{
	string MostFreq1 = "";
	string MostFreq2 = "";
	unsigned int Freq1 = 0;
	unsigned int Freq2 = 0;
	unsigned int temp;
	Link ptr = Head;

	while(ptr!=NULL)
	{
		if ( (ptr->Item != "a") && (ptr->Item != "an") && (ptr->Item != "the") && (ptr->Item != "in") && (ptr->Item != "on") && (ptr->Item != "of") && (ptr->Item != "is") && (ptr->Item != "are") && (ptr->Item != "and") )
		{
			MostFreq1 = ptr->Item;
			Freq1 = 1;
			ptr = ptr->Next;
			while( (ptr!=NULL) && (MostFreq1 == (ptr->Item)) )
			{
				Freq1++;
				ptr = ptr->Next;
			}
		}
		if ( (ptr->Item == "a") || (ptr->Item == "an") || (ptr->Item == "the") || (ptr->Item == "in") || (ptr->Item == "on") || (ptr->Item == "of") || (ptr->Item == "is") || (ptr->Item == "are") || (ptr->Item == "and") )
		{
			ptr = ptr->Next;
		}
		else
		{
			break;
		}
	}

	while(ptr!=NULL)
	{
		if ( (ptr->Item != "a") && (ptr->Item != "an") && (ptr->Item != "the") && (ptr->Item != "in") && (ptr->Item != "on") && (ptr->Item != "of") && (ptr->Item != "is") && (ptr->Item != "are") && (ptr->Item != "and") )
		{
			MostFreq2 = ptr->Item;
			Freq2 = 1;
			ptr = ptr->Next;
			while( (ptr!=NULL) && (MostFreq2 == (ptr->Item)) )
			{
				Freq2++;
				ptr = ptr->Next;
			}

		}
		if ((ptr!=NULL) && ((ptr->Item == "a") || (ptr->Item == "an") || (ptr->Item == "the") || (ptr->Item == "in") || (ptr->Item == "on") || (ptr->Item == "of") || (ptr->Item == "is") || (ptr->Item == "are") || (ptr->Item == "and")) )
		{
			ptr = ptr->Next;
		}
		else
		{
			if (Freq1<Freq2)
			{
				swap(MostFreq1, MostFreq2);
				temp = Freq1;
				Freq1 = Freq2;
				Freq2 = temp;
			}
		}
	}

	ptr = Head;
	Freq2 = 0;
	cout<<"Most frequent word is: ";
	while(ptr!=NULL)
	{
		if ( (ptr->Item != "a") && (ptr->Item != "an") && (ptr->Item != "the") && (ptr->Item != "in") && (ptr->Item != "on") && (ptr->Item != "of") && (ptr->Item != "is") && (ptr->Item != "are") && (ptr->Item != "and") )
		{
			MostFreq2 = ptr->Item;
			Freq2 = 1;
			ptr = ptr->Next;
			while( (ptr!=NULL) && (MostFreq2 == (ptr->Item)) )
			{
				Freq2++;
				ptr = ptr->Next;
			}
		}
		if ((ptr!=NULL) && ((ptr->Item == "a") || (ptr->Item == "an") || (ptr->Item == "the") || (ptr->Item == "in") || (ptr->Item == "on") || (ptr->Item == "of") || (ptr->Item == "is") || (ptr->Item == "are") || (ptr->Item == "and")) )
		{
			ptr = ptr->Next;
		}
		else
		{
			if (Freq2==Freq1)
			{
				cout<<MostFreq2<<" ";
			}
		}
	}
	cout<<endl;
}

void inord_list :: CountWord(const ListElemType &Data)
{
	int count = 0;
	Link ptr = Head;
	while(ptr!=NULL)
	{
		if (Data == ptr->Item)
		{
			count++;
		}
		ptr = ptr->Next;
	}
		cout<<Data<<" is repeated "<<count<<" times"<<endl;
}

void inord_list :: FindStarting(const ListElemType &Data)
{
	Link ptr = Head;
	int FoundWords = 0, count = 1, found;
	while(ptr!=NULL)
	{
		found = ((ptr->Item).find(Data,0));
		if ((found)==0)
		{
			FoundWords++;
			while(ptr!=NULL)
			{
				if ((ptr->Next != NULL) && ((ptr->Item) == (ptr->Next->Item)))
				{
					count++;
					ptr = ptr->Next;
				}
				else
				{
					break;
				}
			}
			cout<<(ptr->Item)<<": "<<count<<"\t";
			count = 1;
		}
		ptr = ptr->Next;
	}

	if (FoundWords == 0)
	{
		cout<<"Word not found"<<endl;
	}
	else
	{
		cout<<endl;
	}
}

void inord_list :: FindContaining(const ListElemType &Data)
{
	int found = 0, count = 1, FoundWords = 0;
	Link ptr = Head;
	while(ptr!=NULL)
	{
		found = (ptr->Item).find(Data,0);
		if (found != string::npos)
		{
			FoundWords++;
			while(ptr!=NULL)
			{
				if (((ptr->Next) != NULL) && ((ptr->Item) == (ptr->Next->Item)))
				{
					count++;
					ptr = ptr->Next;
				}
				else
				{
					break;
				}
			}
			cout<<(ptr->Item)<<": "<<count<<"\t";
			count = 1;
		}
		if (ptr!=NULL)
		{
			ptr = ptr->Next;
		}
	}

	if (FoundWords == 0)
	{
		cout<<"Word not found"<<endl;
	}
	else
	{
		cout<<endl;
	}
}

void inord_list :: SearchWord(const ListElemType &Data)
{
	int found = 0, FoundWords = 0;
	Link ptr = Head;
	while(ptr!=NULL)
	{
		found = (ptr->Item).find(Data,0);
		if (found != string::npos)
		{
			FoundWords++;
			cout<<ptr->Item<<":\tlines "<<ptr->LineNum;
			while(ptr!=NULL)
			{
				if ( ((ptr->Next) != NULL) && ((ptr->Item) == (ptr->Next->Item)) )
				{
					if ((ptr->LineNum != ptr->Next->LineNum))
					{
						cout<<" "<<ptr->Next->LineNum;
					}
					ptr = ptr->Next;
				}
				else
				{
					break;
				}
			}
			cout<<endl;
		}
		if (ptr!=NULL)
		{
			ptr = ptr->Next;
		}
	}
	if (FoundWords == 0)
	{
		cout<<"Word not found"<<endl;
	}
}