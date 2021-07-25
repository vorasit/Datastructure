#pragma once
template<class Object>
class MemoryCell
{
public:
	explicit MemoryCell( const Object & initialValue = Object());
	int read( ) const;
	void write( const Object & x );
	private:
	Object storedValue;
};

