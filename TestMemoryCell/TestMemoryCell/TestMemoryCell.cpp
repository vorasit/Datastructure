
#include "MemoryCell.h"
#include <iostream>
using namespace std;

int main( )
{
	//MemoryCell<int> m1;
	MemoryCell<string> m2( "hello" );

	//m1.write( 37 );
	m2.write( m2.read( ) + " world" );
	cout << m2.read( ) << endl << endl;
	return 0;
}