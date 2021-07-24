#pragma once
class IntCell
{
	public:
	explicit IntCell( int initialValue = 0 );
	int read( ) const;
	void write( int x );
	private:
	int storedValue;
};