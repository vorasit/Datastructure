// TestIntCell.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IntCell.h"
#include <iostream>
using namespace std;
/*
int main( )
{
	IntCell m;

	m.write( 5 );
	cout << "Cell contents: " << m.read( ) << endl;
	//exit(0);
	return 0;
}
*/


// pointer
int main( )
{
	IntCell *m;
	m = new IntCell( 0 );
	m->write( 5 );
	cout << "Cell contents: " << m->read( ) << endl;
	delete m;
	return 0;
}