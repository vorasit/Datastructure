#include "hash.h"
#include<iostream>
#include<string>
int nextPrime(int size);
using namespace std;
void main(){
	HashTable<int> a(-999);
	string choice;
	bool exit = true;
	bool create =false;

	do{
	system("cls");
	cout<<"\t========= Assign2 Hashing OpenAddressing =============\n\n";
	cout<<"\t1.) CREATE HASH TABLE\n\t2.) INSERT\n\t3.) PRINT\n\t4.) FIND\n\t5.) REMOVE\n\t6.) EXIT\n\n\tEnter Choice : ";
	cin>>choice;
	switch (choice[0])
	{
		int x;
		case '1' :
			system("cls");
			if(!create){
				int cell;
				cout<<"\t!!!!! CREATE MODE !!!!!\n\n\tHow many cell : ";
				cin>>cell;
				cout<<"\n\tNEXT PRIME OF "<<cell<<" IS "<<nextPrime(cell)<<"\n\tSIZE OF HASH TABLE IS "<<nextPrime(cell)<<endl<<endl;
				
				a.create(nextPrime(cell));
				create =!create;

				system("pause");
			}
			else 
			{
				cout<<"\n!!!CREATED ALL MODE AVAILABLE!!!\n\n";
				system("pause");
			}
				
			break;
		case '2' :
			system("cls");
			if(create)
			{
			cout<<"\t!!!!! INSERT MODE !!!!!\n\n\tEnter Element to Insert : ";
			cin>>x;
			if(a.find(x)==-999){
				a.insert(x);
				cout<<"\n\t!!! INSERT ELEMENT SUCCESSFULL !!!\n";
			}
			else cout<<"\n\t!!! HASH TABLE HAVE SAME ELEMEMT PLEASE TRY AGAIN !!!\n";
			cout<<endl;
			system("pause");
			}
			else 
			{
				cout<<"\n!!!MUST CREATE TABLE BEFORE INSERT ELEMENT!!!\n\n";
				system("pause");
			}
			break;
		case '3' :
			system("cls");
			if(create)
			{
				cout<<"\t!!!!! PRINT MODE !!!!!\n\n";
				a.print();
				cout<<endl;
				system("pause");
			}
			else 
			{
				cout<<"\n!!!MUST CREATE TABLE BEFORE PRINT HASH TABLE!!!\n\n";
				system("pause");
			}
			break;


		case '4' :
			system("cls");
			if(create)
			{
			cout<<"\t!!!!! FIND MODE !!!!!\n\n\tEnter Element to Find : ";
			cin>>x;
			if(a.findarray(x)==-999)
				cout<<"\n\t!!! FIND ELEMENT NOT FOUND !!!\n";
			cout<<endl;
			system("pause");
			}
			else 
			{
				cout<<"\n!!!MUST CREATE TABLE BEFORE FIND ELEMENT!!!\n\n";
				system("pause");
			}
			break;
		case '5' :
			system("cls");
			if(create)
			{
			cout<<"\t!!!!! REMOVE MODE !!!!!\n\n\tEnter Element to Remove : ";
			cin>>x;
			if(a.find(x)!=-999){
				a.remove(x);
				cout<<"\n\t!!! REMOVE ELEMENT SUCCESSFULL !!!\n";
			}
			else cout<<"\n\t!!! HASH TABLE HAVEN'T ELEMEMT PLEASE TRY AGAIN !!!\n";
			cout<<endl;
			system("pause");
			}
			else 
			{
				cout<<"\n!!!MUST CREATE TABLE BEFORE REMOVE ELEMENT!!!\n\n";
				system("pause");
			}
			break;

		case '6' : 
			exit = false;
			break;
		default : break;
	}
	}while(exit);

}


int nextPrime(int size)
{
	int i=2;
	if (size==1) return 1;
	while(size%i!=0) i++;

		if(i==size) return i;
		else{
			i=size+1;
			bool check=false;
				while(true){
					for(int j=2;j<=i;j++){
						if(i%j==0&&j<i) break;
						else if(i%j==0&&j==i) check = true; 
					}
				if(check) break;
				i++;
				}
			return i;
		}
}