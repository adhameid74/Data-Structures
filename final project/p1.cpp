/* 	Nama: Adham Mohammed Eid
	Sec: 1
	BN: 35
	SeatNo.: 33035
	Ordered Packets Delivery
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>

using namespace std;

typedef int QueueElemType;

class Queue
{
public:
	Queue(int QUEUESIZE);
	void enqueue(QueueElemType data, QueueElemType expected);
	QueueElemType dequeue();
	QueueElemType front();
	bool isEmpty();
	bool isFull();
	bool isThere(QueueElemType data); // check if certain value exists in the queue or not

private:
	int fr;
	int rear;
	int separator; // holds the index of the first element in the queue that is less than the next expected Packet, if there's none it should equal -1. it will be used in enqueue function
	int SIZE;
	QueueElemType * QueueArr;
};

bool isDigits(const string &str); // checks if a string consists only of numbers or not

int main(int argc, char const *argv[])
{
	if (argc<=4)
	{
		cout<<"Invalid number of arguments";
		if (argc==2)
		{
			int seqNumBits = atoi(argv[1]);
			if ( (seqNumBits<=0) || !(isDigits(argv[1])) )
			{
				cout<<" Invalid seqNumBits";
			}
		}
		else if (argc==3)
		{
			int seqNumBits = atoi(argv[1]);
			int winSize = atoi(argv[2]);
			int MAXSEQNU = pow(2, seqNumBits);
			if ( (seqNumBits<=0) || !(isDigits(argv[1])) )
			{
				cout<<" Invalid seqNumBits";
			}
			if ( ((winSize>MAXSEQNU-1) && (seqNumBits>0) && (isDigits(argv[1]))) || (winSize<=0) || !(isDigits(argv[2])) )
			{
				cout<<" Invalid winSize";
			}
		}
		else if (argc==4)
		{
			int seqNumBits = atoi(argv[1]);
			int winSize = atoi(argv[2]);
			int initSeq = atoi(argv[3]);
			int MAXSEQNU = pow(2, seqNumBits);
			if ( (seqNumBits<=0) || !(isDigits(argv[1])) )
			{
				cout<<" Invalid seqNumBits";
			}
			if ( ((winSize>MAXSEQNU-1) && (seqNumBits>0) && (isDigits(argv[1]))) || (winSize<=0) || !(isDigits(argv[2])) )
			{
				cout<<" Invalid winSize";
			}
			if ( ((initSeq>MAXSEQNU-1) && (seqNumBits>0) && (isDigits(argv[1]))) || (initSeq<0) || !(isDigits(argv[3])) || (strcmp(argv[3],"-")==0) )
			{
				cout<<" Invalid initSeq";
			}
		}
		return 0;
	}

	int seqNumBits = atoi(argv[1]);
	int winSize = atoi(argv[2]);
	int initSeq = atoi(argv[3]);
	int MAXSEQNU = pow(2, seqNumBits);
	bool error_flag = false;

	if ( (seqNumBits<=0) || !(isDigits(argv[1])) )
	{
		cout<<"Invalid seqNumBits";
		error_flag = true;
	}

	if ( ((winSize>MAXSEQNU-1) && (seqNumBits>0) && (isDigits(argv[1]))) || (winSize<=0) || !(isDigits(argv[2])) )
	{
		if (error_flag == true)
		{
			cout<<" Invalid winSize";
		}
		else
		{
			cout<<"Invalid winSize";
			error_flag = true;
		}
	}

	if ( ((initSeq>MAXSEQNU-1) && (seqNumBits>0) && (isDigits(argv[1]))) || (initSeq<0) || !(isDigits(argv[3])) || (strcmp(argv[3],"-")==0) )
	{
		if (error_flag == true)
		{
			cout<<" Invalid initSeq";
		}
		else
		{
			cout<<"Invalid initSeq";
			error_flag = true;
		}
	}

	for (int i = 4; i < argc; i++)
	{
		if ( (atoi(argv[i])<0) || ((atoi(argv[i])>MAXSEQNU-1) && (seqNumBits>0) && (isDigits(argv[1]))) || !(isDigits(argv[i])) || (strcmp(argv[i],"-")==0) )
		{
			if (error_flag == true)
			{
				cout<<" Invalid packet ID";
			}
			else
			{
				cout<<"Invalid packet ID";
				error_flag = true;
			}
			break;
		}
	}

	if (error_flag == true)
	{
		return 0;
	}

	Queue wait(winSize+1); // create the wait queue (winSize+1 because there is an empty element always in the queue)
	string R = "R ";
	string D = "D ";
	int minWin; // first value in the window range
	int maxWin; // last value in window range
	int j; // just an iterator
	bool in_win_range; // flag to tell if the packet is in the window range or not

	for (int i = 4; i < argc; i++)
	{
		if (atoi(argv[i])==initSeq)
		{
			R = R + argv[i] +" ";
			initSeq = (initSeq+1)%MAXSEQNU;
			while ( (!(wait.isEmpty())) && (wait.front() == initSeq) ) // this while loop checks for expected packets in wait queue
			{
				R = R + to_string(wait.dequeue()) + " ";
				initSeq = (initSeq+1)%MAXSEQNU;
			}
			continue;
		}

		minWin = initSeq;
		maxWin = ((minWin+winSize)%MAXSEQNU)-1;
		if (maxWin == -1)
		{
			maxWin = MAXSEQNU-1; // to apply circularity
		}
		j = minWin;
		in_win_range = false;

		while(j!=((maxWin+1)%MAXSEQNU)) // this loop is to determine if the packet is inside or outside window range
		{
			if (atoi(argv[i]) == j)
			{
				in_win_range = true;
				break;
			}
			j = (j+1)%MAXSEQNU;
		}

		if ( (!in_win_range) || ((!(wait.isEmpty())) && (wait.isThere(atoi(argv[i])))) )
		{
			D = D + argv[i] +" "; // packet should be dropped if it’s out of window range or repeated
		}

		else
		{
			wait.enqueue(atoi(argv[i]),initSeq);
		}
	}

	cout<<R<<"E "<<initSeq<<" W ";
	while(!(wait.isEmpty()))
	{
		cout<<wait.dequeue()<<" ";
	}
	cout<<D;
	return 0;
}

bool isDigits(const string &str)
{
    return str.find_first_not_of("-0123456789") == string::npos;
}

int nextPos(int p, int MAXSIZE)
{
	if (p == MAXSIZE-1)
	{
		return 0;
	}
	else
	{
		return (p+1);
	}
}

int prevPos(int p, int MAXSIZE)
{
	if (p == 0)
	{
		return (MAXSIZE-1);
	}
	else
	{
		return (p-1);
	}
}

Queue :: Queue(int QUEUESIZE)
{
	QueueArr = new QueueElemType[QUEUESIZE];
	assert(QueueArr!=NULL);
	fr = 0;
	rear = 0;
	separator = -1; // initially -1 to indicate that ther's no elements in the queue less than initSeq
	SIZE = QUEUESIZE;
}

void Queue :: enqueue(QueueElemType data, QueueElemType expected)
{
	int i = 0, j = 0;
	assert(nextPos(rear,SIZE)!=fr); // make sure queue isn't full

	if (rear==fr) // queue is empty
	{
		rear = nextPos(rear,SIZE);
		QueueArr[rear] = data;
		return;
	}

	// if queue is not empty then we need to set the value of separator according to next expected sequence
	
	separator = -1;
	if (expected!=0) // if the expected is equal to zero, the separator should be -1
	{
		i = nextPos(fr,SIZE);
		while(i!=nextPos(rear,SIZE))
		{
			if (QueueArr[i]<expected)  // if ther's no element less than the expected, the separator should be -1
			{
				separator = i; // set the separator to the index of the first element less than next expected
				break;
			}
			i = nextPos(i,SIZE);
		}
	}

	rear = nextPos(rear,SIZE); // set rear to the next free element to store
	if (separator==-1)
	{
		if ( (data>QueueArr[prevPos(rear,SIZE)]) || (data<expected) ) // if data is greater than the greatest value in queue or it's less than the expected value then it should be just stored at the end of the queue
		{
			QueueArr[rear] = data;
			return;
		}

		i = nextPos(fr,SIZE);
		while(i!=rear)
		{
			if (data<QueueArr[i]) // search for the right position for the value to be in order
			{
				j = rear;
				while(j!=i) // shifting the elements of the queue to store the value in the needed position
				{
					QueueArr[j] = QueueArr[prevPos(j,SIZE)];
					j = prevPos(j,SIZE);
				}
				QueueArr[i] = data;
				return;
			}
			i = nextPos(i,SIZE);
		}
	}

	else
	{
		if (data>expected)
		{
			i = nextPos(fr,SIZE);
			while(i!=separator)
			{
				if (data<QueueArr[i])
				{
					j = rear;
					while(j!=i)
					{
						QueueArr[j] = QueueArr[prevPos(j,SIZE)];
						j = prevPos(j,SIZE);
					}
					QueueArr[i] = data;
					return;
				}
				i = nextPos(i,SIZE);
			}

			i = separator;
			j = rear;
			while(j!=i)
			{
				QueueArr[j] = QueueArr[prevPos(j,SIZE)];
				j = prevPos(j,SIZE);
			}
			QueueArr[i] = data;
			return;
		}

		else
		{
			if (data>QueueArr[prevPos(rear,SIZE)])
			{
				QueueArr[rear] = data;
				return;
			}

			i = separator;
			while(i!=rear)
			{
				if (data<QueueArr[i])
				{
					j = rear;
					while(j!=i)
					{
						QueueArr[j] = QueueArr[prevPos(j,SIZE)];
						j = prevPos(j,SIZE);
					}
					QueueArr[i] = data;
					return;
				}
				i = nextPos(i,SIZE);
			}
		}
	}
}

QueueElemType Queue :: dequeue()
{
	assert(fr!=rear);
	fr = nextPos(fr,SIZE);
	return QueueArr[fr];
}

QueueElemType Queue :: front()
{
	assert(fr!=rear);
	return QueueArr[nextPos(fr,SIZE)];
}

bool Queue :: isEmpty()
{
	return bool(fr==rear);
}

bool Queue :: isFull()
{
	return bool(fr==nextPos(rear,SIZE));
}

bool Queue :: isThere(QueueElemType data)
{
	assert(fr!=rear);
	for (int i = nextPos(fr,SIZE); i != nextPos(rear,SIZE); i=nextPos(i,SIZE))
	{
		if (data==QueueArr[i])
		{
			return true;
		}
	}
	return false;
}