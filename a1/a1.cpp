//============================================================================
// Name        : A1.cpp
// Author      : Adham Mohammed Eid
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 1
//============================================================================

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]) {

	int i=2;
	int j=0;
	int count=0;
	char temp;
	int k;
	int sum=0;
	int num;
	int sequenceLength;
	int minNumber;
	int maxNumber;
	int seedValue;
	if(strcmp(argv[1],"print")==0){
		if(argc<3){
			cout<<"Incorrect Number of Arguments";
			goto l1;
		}
		for(i=2;i<argc;i++){
			if(i==argc-1){
				cout<<argv[i];
			}
			else {
				cout<<argv[i]<<' ';
			}
		}
	}
	else if(strcmp(argv[1],"reverse")==0) {
		if(argc<3){
					cout<<"Incorrect Number of Arguments";
					goto l1;
				}
		for (i=argc-1;i>=2;i--){
			if(i==2){
							cout<<argv[i];
						}
						else {
							cout<<argv[i]<<' ';
						}
		}
	}
	else if(strcmp(argv[1],"upper")==0){
		if(argc<3){
    				cout<<"Incorrect Number of Arguments";
    				goto l1;
						}
		for(i=2;i<argc;i++){
			j=0;
			while(argv[i][j]!='\0'){
				if(argv[i][j]>=97 && argv[i][j]<=122){
					argv[i][j] = argv[i][j]-32;
				}
				j++;
			}
			if(i==argc-1){
							cout<<argv[i];
						}
						else {
							cout<<argv[i]<<' ';
						}
		}
	}
	else if(strcmp(argv[1],"shuffle")==0){
		j=0;
		if(argc!=3){
			cout<<"Incorrect Number of Arguments";
			goto l1;
		}
		while(argv[2][j]!='\0'){
			count++;
			j++;
		}
		if(count%2==0){
			for(j=0;j<=count-2;j+=2){
				temp=argv[2][j];
				argv[2][j]=argv[2][j+1];
				argv[2][j+1]=temp;
			}
		}
		else{
			for(j=0;j<=count-3;j+=2){
							temp=argv[2][j];
							argv[2][j]=argv[2][j+1];
							argv[2][j+1]=temp;
						}
		}
		cout<<argv[2];
	}
	else if(strcmp(argv[1],"shuffleStatement")==0){
		if(argc<3){
					cout<<"Incorrect Number of Arguments";
					goto l1;
						}
		if(argc%2==0){
					for(i=2;i<=argc-2;i+=2){
						if(i==argc-2){
							cout<<argv[i+1]<<' '<<argv[i];
						}
						else{
							cout<<argv[i+1]<<' '<<argv[i]<<' ';
						}
					}
				}
				else{
					for(i=2;i<=argc-1;i+=2){
						if(i==argc-1){
						cout<<argv[i];
					}
					else{
						cout<<argv[i+1]<<' '<<argv[i]<<' ';
					}
					}
				}
	}
	else if(strcmp(argv[1],"delete")==0){
		if(argc<4){
					cout<<"Incorrect Number of Arguments";
					goto l1;
						}
		k=2+atoi(argv[2]);
		if(k>argc){
					cout<<"Incorrect Number of Arguments";
					goto l1;
						}
		else if(atoi(argv[2])<=0){
			cout<<"Incorrect Data Type";
			goto l1;
		}
		for(i=3;i<=argc-1;i++){
			if(i==k){
				continue;
			}
			if((i==argc-1)||((k==argc-1)&&(i==argc-2))){
				cout<<argv[i];
			}
			else{
				cout<<argv[i]<<' ';
			}
		}
	}
	else if(strcmp(argv[1],"middle")==0){
		if(argc<3){
					cout<<"Incorrect Number of Arguments";
					goto l1;
						}
		k=argc-2;
		if(k%2==0){
			cout<<argv[(k/2)+1]<<' '<<argv[(k/2)+2];
		}
		else{
			cout<<argv[((k+1)/2)+1];
		}
	}
	else if(strcmp(argv[1],"add")==0){
		if(argc<3){
					cout<<"Incorrect Number of Arguments";
					goto l1;
				}
		for(i=2;i<=argc-1;i++){
			num=atoi(argv[i]);
				j=0;
				while(argv[i][j]!='\0'){
					if( !( ((argv[i][j]>=48) && (argv[i][j]<=57)) || (argv[i][j]==45) ) ){
						cout<<"Incorrect Data Type";
						goto l1;
					}
					j++;
				}
				sum=sum+num;
			}
		cout<<sum;
		}
	else if(strcmp(argv[1],"random")==0){
		if(argc!=6){
					cout<<"Incorrect Number of Arguments";
					goto l1;
						}
		sequenceLength = atoi(argv[2]);
		minNumber = atoi(argv[3]);
		maxNumber = atoi(argv[4]);
		seedValue = atoi(argv[5]);
		if(minNumber>maxNumber){
			cout<<"Incorrect Data Type";
			goto l1;
		}
		else if (sequenceLength<=0){
			cout<<"Incorrect Data Type";
			goto l1;
		}
		else if( ((sequenceLength==0) && (argv[2][0]!=48)) || ((minNumber==0) && (argv[3][0]!=48)) || ((maxNumber==0) && (argv[4][0]!=48)) || ((seedValue==0) && (argv[5][0]!=48)) ){
							cout<<"Incorrect Data Type";
							goto l1;
						}
		srand(seedValue);
		for(i=0;i<sequenceLength;i++){
			if(i==sequenceLength-1){
				cout<<(minNumber + (rand() % (int)(maxNumber - minNumber + 1)));
			}
			else{
				cout<<(minNumber + (rand() % (int)(maxNumber - minNumber + 1)))<<' ';
			}
		}
	}
	else {
		cout<<"Undefined Command";
	}
	l1:
	return 0;
}
