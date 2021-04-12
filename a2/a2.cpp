//============================================================================
// Name        : A2.cpp
// Author      : Adham Mohammed Eid		Sec: 1		BN: 35
// Version     : 1
// Copyright   : Your copyright notice
// Description : Assignment 2
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include "inord_list.h"

using namespace std;

int main(int argc, char const *argv[])
{
	inord_list MyList;
	unsigned int NumberOfLines = 0, NumberOfWords = 0, NumberOfChar = 0, NumberOfUniqueWords = 0, len = 0;
	int DistinctFlag = 0, i = 0;
	char ch;
	string word = "", Comm = "", line = "", check = "";
	ifstream InFile,Commands;

	if (argc!=3)
	{
		cout<<"Incorrect number of arguments"<<endl;
		return 0;
	}

	InFile.open(argv[1]);
	if (!InFile)
	{
		cout<<"File not found"<<endl;
		return 0;
	}
	else
	{
		while(!InFile.eof())
		{
			InFile.get(ch);
			NumberOfChar++;
	
			if ( ((ch>=97) && (ch<=122)) || ((ch>=48) && (ch<=57)) || (ch==39) || (ch==45) )
			{
				word+=ch;
			}
			else if ( (ch>=65) && (ch<=90) )
			{
				ch += 32;
				word+=ch;
			}
			else
			{
				if ((word == "") || (word == "'") )
				{
					word = "";
				}
				else if ((word[0]==45))
				{
					word = "";
				}
				else
				{
					for (i = 0; word[i]!='\0'; i++)
					{
						len++;
					}
					if (word[len-1]==45)
					{
						word = "";
						goto l1;
					}
					DistinctFlag = MyList.insert(word,NumberOfLines+1);
					NumberOfWords++;
					word = "";
					if (DistinctFlag == 1)
					{
						NumberOfUniqueWords++;
					}
				}
			}
		l1:	if (ch == '\n')
			{
				NumberOfLines++;
			}
			ch = ' ';
			len = 0;
		}

		len = 0;
		if ( (word == "") || ((word == "'")) )
		{
			word = "";
		}
		else if (word[0] == 45)
		{
			word = "";
		}
		else
		{
			for (i = 0; word[i]!='\0'; i++)
			{
				len++;
			}
			if (word[len-1]==45)
			{
				word = "";
				goto l2;
			}
			DistinctFlag = MyList.insert(word,NumberOfLines+1);
			NumberOfWords++;
			word = "";
			if (DistinctFlag == 1)
			{
				NumberOfUniqueWords++;
			}
		}
	}

l2:	NumberOfChar--;
	word = "";
	InFile.close();

	Commands.open(argv[2]);
	if (!Commands)
	{
		cout<<"File not found"<<endl;
		return 0;
	}
	else
	{
		while(!Commands.eof())
		{
			getline(Commands, line);
			while( (!line.empty()) && (!Commands.eof()) )
			{
				stringstream s(line);
				s >> Comm;
				if (Comm == "wordCount")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						cout<<NumberOfWords<<" words"<<endl;
					}
				}
	
				else if (Comm == "distWords")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						cout<<NumberOfUniqueWords<<" distinct words"<<endl;
					}
				}
	
				else if (Comm == "charCount")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						cout<<NumberOfChar<<" characters"<<endl;
					}
				}
	
				else if (Comm == "frequentWord")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						MyList.FreqWord();
					}
				}
	
				else if (Comm == "countWord")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
					cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.CountWord(word);
					}
				}
	
				else if (Comm == "starting")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.FindStarting(word);
					}
				}
	
				else if (Comm == "containing")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.FindContaining(word);
					}
				}
	
				else if (Comm == "search")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.SearchWord(word);
					}
				}

				else if (Comm == "")
				{
					
				}
				else
				{
					cout<<"Undefined command"<<endl;
				}

				Comm = "";
				getline(Commands, line);
			}
		}
	}

				stringstream s(line);
				s >> Comm;
				if (Comm == "wordCount")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						cout<<NumberOfWords<<" words"<<endl;
					}
				}
	
				else if (Comm == "distWords")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						cout<<NumberOfUniqueWords<<" distinct words"<<endl;
					}
				}
	
				else if (Comm == "charCount")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						cout<<NumberOfChar<<" characters"<<endl;
					}
				}
	
				else if (Comm == "frequentWord")
				{
					if (s>>word)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						MyList.FreqWord();
					}
				}
	
				else if (Comm == "countWord")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
					cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.CountWord(word);
					}
				}
	
				else if (Comm == "starting")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.FindStarting(word);
					}
				}
	
				else if (Comm == "containing")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.FindContaining(word);
					}
				}
	
				else if (Comm == "search")
				{
					if (!(s>>word))
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else if (s>>check)
					{
						cout<<"Incorrect number of arguments"<<endl;
					}
					else
					{
						for (i = 0; word[i]!='\0'; i++)
						{
							len++;
						}
						for (i = 0; i < len; i++)
						{
							if ( (word[i]>=65) && (word[i]<=90) )
							{
								word[i]+=32;
							}
						}
						len = 0;
						MyList.SearchWord(word);
					}
				}

				else if (Comm == "")
				{
					
				}
				else
				{
					cout<<"Undefined command"<<endl;
				}

	Commands.close();
	return 0;
}