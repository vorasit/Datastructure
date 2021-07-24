#include "StdAfx.h"
#include "IntCell.h"
class IntCell
{
	public:
	explicit IntCell( int initialValue = 0 )
		: storedValue( initialValue ) { }
	int read( ) const
	{ 
		return storedValue; 
	}
	void write( int x )
	{ 
		storedValue = x; 
	}
	private:
		int storedValue;
};


// class implement
/*
IntCell::IntCell( int initialValue ) : storedValue( initialValue )
{

}
int IntCell::read( ) const
{
	return storedValue;
}

void IntCell::write( int x )
{
	storedValue = x;
}
*/
