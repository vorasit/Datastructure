#pragma once
template <class Object>

class MemoryCell
{
	explicit MemoryCell( const Object & initialValue = object( ) )
	: storedValue( initialValue ) { }
	const Object & read( ) const
	{ return storedValue; }
	void write( const Object & x )
	{ storedValue = x; }
	private:
	Object storedValue;
};

// class implement
/*
explicit MemoryCell::MemoryCell( const Object & initialValue = Object( ) )
	: storedValue( initialValue ) { }
	const Object & MemoryCell::read( ) const
	{ return storedValue; }
	void MemoryCell::write( const Object & x )
	{ storedValue = x; }

*/