#include<iostream>
#include "ListItr.h"
#include "ListNode.h"
template<class Object>
class List;
template<class Object>
class List
{
public:
	List();
	List(const List & rhs);
	~List();

	bool isEmpty() const;
	void makeEmpty();
	ListItr<Object> zeroth() const;
	ListItr<Object> first() const;
	void insert(const Object & x, const ListItr<Object> & p);
	ListItr<Object> find(const Object & x) const;
	ListItr<Object> findPrevious(const Object & x) const;
	int remove(const Object & x);

	const List & operator=(const List & rhs);

private:
	ListNode<Object> *header;
};
