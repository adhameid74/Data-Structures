#include <string.h>
#include <string>
#include <iostream>

using namespace std;

typedef string ListElemType;

class inord_list
{
public:
	inord_list();
	int insert(const ListElemType &Data, unsigned int Line);
	void FreqWord();
	void CountWord(const ListElemType &Data);
	void FindStarting(const ListElemType &Data);
	void FindContaining(const ListElemType &Data);
	void SearchWord(const ListElemType &Data);

private:
	struct Node;
	typedef Node* Link;
	struct Node{
		ListElemType Item;
		unsigned int LineNum;
		Link Next;
	};
	
	Link Head;
	Link Current;
};