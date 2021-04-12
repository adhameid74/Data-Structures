// Author      : Adham Mohammed Eid		Sec: 1		BN: 35

//g++ stack.cpp a3.cpp

#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char const *argv[])
{
	stack firstNumWhole;
	stack firstNumfractional;
	stack secondNumWhole;
	stack secondNumfractional;
	stack result;
	char op, num = 1, numOfOp = 0, numOfpoints = 0, carry = 0, num1, num2, res;
	int j = 0, numOfDigitsWhole1 = 0, numOfDigitsfractional1 = 0, numOfDigitsWhole2 = 0, numOfDigitsfractional2 = 0, maxNumOfDigitsWhole = 0, maxNumOfDigitsfractional = 0;

	if (argc!=2)
	{
		printf("Invalid input");
		return 0;
	}

	while(argv[1][j]!='\0')
	{
		if ( (argv[1][j]>=48) && (argv[1][j]<=57) )
		{
			if ( (num==1) && (numOfpoints==0) )
			{
				firstNumWhole.push(argv[1][j]-48);
				numOfDigitsWhole1++;
			}
			else if ( (num==1) && (numOfpoints==1) )
			{
				firstNumfractional.push(argv[1][j]-48);
				numOfDigitsfractional1++;
			}
			else if ( (num==2) && (numOfpoints==0) )
			{
				secondNumWhole.push(argv[1][j]-48);
				numOfDigitsWhole2++;
			}
			else
			{
				secondNumfractional.push(argv[1][j]-48);
				numOfDigitsfractional2++;
			}
		}
		else if (argv[1][j]==46)
		{
			numOfpoints++;
			if (numOfpoints>1)
			{
				printf("Invalid input");
				return 0;
			}
			if (argv[1][j+1]=='\0')
			{
				printf("Invalid input");
				return 0;
			}
			if ( (argv[1][j+1]<48) || (argv[1][j+1]>57) )
			{
				printf("Invalid input");
				return 0;
			}
			if ( (argv[1][j-1]<48) || (argv[1][j-1]>57) )
			{
				printf("Invalid input");
				return 0;
			}
		}
		else if ( (argv[1][j]==43) || (argv[1][j]==45) )
		{
			numOfOp++;
			num++;
			numOfpoints = 0;
			if (numOfOp>1)
			{
				printf("Invalid input");
				return 0;
			}
			else
			{
				op = argv[1][j];
			}
			if (argv[1][j+1]=='\0')
			{
				printf("Invalid input");
				return 0;
			}
			if ( (argv[1][j+1]<48) || (argv[1][j+1]>57) )
			{
				printf("Invalid input");
				return 0;
			}
			if ( (argv[1][j-1]<48) || (argv[1][j-1]>57) )
			{
				printf("Invalid input");
				return 0;
			}
		}
		else
		{
			printf("Invalid input");
			return 0;
		}
		j++;
	}

	if (numOfOp!=1)
	{
		printf("Invalid input");
		return 0;
	}

	if (numOfDigitsWhole1>numOfDigitsWhole2)
	{
		maxNumOfDigitsWhole = numOfDigitsWhole1;
	}
	else
	{
		maxNumOfDigitsWhole = numOfDigitsWhole2;
	}
	if (numOfDigitsfractional1>numOfDigitsfractional2)
	{
		maxNumOfDigitsfractional = numOfDigitsfractional1;
		for (int i = 0; i < (numOfDigitsfractional1-numOfDigitsfractional2); i++)
		{
			secondNumfractional.push(0);
		}
	}
	else if (numOfDigitsfractional1<=numOfDigitsfractional2)
	{
		maxNumOfDigitsfractional = numOfDigitsfractional2;
		for (int i = 0; i < (numOfDigitsfractional2-numOfDigitsfractional1); i++)
		{
			firstNumfractional.push(0);
		}
	}

	if (op=='+')
	{
		if ( (!(firstNumfractional.IsEmpty())) || (!(secondNumfractional.IsEmpty())) )
		{
			for (int i = 0; i < maxNumOfDigitsfractional; i++)
			{
				num1 = firstNumfractional.pop();
				num2 = secondNumfractional.pop();
				res = num1 + num2 + carry;
				if ((res/10)!=0)
				{
					carry = 1;
					result.push((res%10));
				}
				else
				{
					carry = 0;
					result.push(res);
				}
			}
			result.push('.');
		}
		for (int i = 0; i < maxNumOfDigitsWhole; i++)
		{
			num1 = firstNumWhole.pop();
			num2 = secondNumWhole.pop();
			res = num1 + num2 + carry;
			if ((res/10)!=0)
			{
				carry = 1;
				result.push((res%10));
			}
			else
			{
				carry = 0;
				result.push(res);
			}
		}
		result.push(carry);
	}

	else
	{
		if ( (!(firstNumfractional.IsEmpty())) || (!(secondNumfractional.IsEmpty())) )
		{
			for (int i = 0; i < maxNumOfDigitsfractional; i++)
			{
				num1 = firstNumfractional.pop();
				num2 = secondNumfractional.pop();
				res = num1 - num2 - carry;
				if (res<0)
				{
					res+=10;
					carry = 1;
					result.push(res);
				}
				else
				{
					carry = 0;
					result.push(res);
				}
			}
			result.push('.');
		}
		for (int i = 0; i < maxNumOfDigitsWhole; i++)
		{
			num1 = firstNumWhole.pop();
			num2 = secondNumWhole.pop();
			res = num1 - num2 - carry;
			if (res<0)
			{
				res+=10;
				carry = 1;
				result.push((res%10));
			}
			else
			{
				carry = 0;
				result.push(res);
			}
		}
		result.push(carry);
	}

	while( ((int)result.top()== 0) && (!(result.IsEmpty())))
	{
		result.pop();
	}

	if ( (result.top()=='.') || (result.IsEmpty()))
	{
		result.push(0);
	}

	while(!result.IsEmpty())
	{
		if (result.top()=='.')
		{
			cout<<(result.pop());
		}
		else
		{
			cout<<(int)(result.pop());
		}
	}
	return 0;
}