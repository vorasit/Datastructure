#include <iostream>
#include "BinarySearchTree.h"
#include "dsexceptions.h"
#include "BinarySearchTree.cpp"

using namespace std;

void insert();
void print();
void remove();
void find();
void mainMenu();

 const int ITEM_NOT_FOUND = -9999;
 BinarySearchTree<int> a(ITEM_NOT_FOUND);  

void main( )
{
	system("cls");
    int menu;

	mainMenu();
	do{
	cout << "Select Menu : ";
	cin >> menu;
	}while(menu < 0 && menu >= 5);

	switch(menu){
	
	case 1 : insert();	break;
	case 2 : print();	break;
	case 3 : remove();	break;
	case 4 : find();	break;
	case 5 : exit(0);
	}
	
	system("pause");
	
}

void insert(){
	
	int t,ne;
	
	cout << "Enter Number Of Element : ";
	cin>>ne;
	
	for(int i=0;i<ne;i++){
	cout << "Enter Element : ";
	cin>>t;
	a.insert(t);
	}
	system("pause");
	main();
}

void print(){

	system("cls");

	cout << "-------------------------\n";
	cout << "Print Tree\n";
	cout << "\n-------------------------\n";
	
	cout << "\n PreOrder : ";
	a.printPre();
	cout << "\n InOrder : ";
	a.printIn();
	cout << "\n PostOrder : ";
	a.printPost();
	
	cout << "\n";
	system("pause");
	main();
}


void remove(){
	
	int t;
	
	cout << "-------------------------\n";
	cout << "Remove Tree\n";
	cout << "\n-------------------------\n";
	
	cout << "Enter Element : ";
	cin >> t;

	if(a.find(t) == t){
	a.remove(t);
	cout << "All Done!! to remove "<<t<<"\n";
	}else{
	cout << "Data Not Found "<<t<<" Please Try again\n";
	}
	system("pause");
	main();
}


void find(){
	system("cls");

	
	int t;
	
	cout << "-------------------------\n";
	cout << "Find Tree\n";
	cout << "\n-------------------------\n";
	
	cout << "Min Element : " << a.findMin() << "\n";
	cout << "Max Element : " << a.findMax() << "\n";


	cout << "Enter Element : ";
	cin >> t;

	if(a.find(t) == t){
	a.find(t);
	cout << "Found "<<t<<" on Memory\n\n";
	}else{
	cout << "Data Not Found "<<t<<" Please Try again\n\n";
	}

	system("pause");
	main();
}

void mainMenu(){

	cout << "-------------------------\n";
	cout << "1.Insert to Tree\n";
	cout << "2.Print Tree\n";
	cout << "3.Remove form Tree\n";
	cout << "4.Find in Tree\n";

	cout << "5.Close Program\n";
	cout << "\n-------------------------\n";


}
