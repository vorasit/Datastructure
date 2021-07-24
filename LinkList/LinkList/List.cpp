#include<iostream>
#include "List.h"
using namespace std;

template <class Object>
List<Object>::List()
{
	header = new ListNode<Object>;
}
template <class Object>
bool List<Object>::isEmpty() const
{
	return header->next == NULL;
}
template <class Object>
ListItr<Object> List<Object>::zeroth() const
{
	return ListItr<Object>(header);
}
template <class Object>
ListItr<Object> List<Object>::first() const
{
	return ListItr<Object>(header->next);
}
template <class Object>
ListItr<Object> List<Object>::find(const Object & x) const
{
	ListNode<Object> *itr = header->next;

	while (itr != NULL && itr->element != x)
		itr = itr->next;
	cout << "ListNode Address is " << itr << endl;
	return ListItr<Object>(itr);
}
template<class Object>
int List<Object>::remove(const Object & x)
{
	ListItr<Object> p = findPrevious(x);

	if (p.current->next != NULL)
	{
		ListNode<Object> *oldNode = p.current->next;
		p.current->next = p.current->next->next;
		delete oldNode;
		return 1;
	}
	return 0;
}
template <class Object>
ListItr<Object> List<Object>::findPrevious(const Object & x) const
{
	ListNode<Object> *itr = header;

	while (itr->next != NULL && itr->next->element != x)
		itr = itr->next;
	return ListItr<Object>(itr);
}

template<class Object>
void List<Object>::insert(const Object & x, const ListItr<Object> & p)
{
	if (p.current != NULL)
		p.current->next = new ListNode<Object>(x, p.current->next);
}

template <class Object>
void List<Object>::makeEmpty()
{
	while (!isEmpty())
		remove(first().retrieve());
}
template<class Object>
List<Object>::~List()
{
	makeEmpty();
	delete header;
}

void main()
{
	List<int> a;
	ListItr<int> b;
	cout<<"==============================\n";
	cout<<"Menu\n";
	cout<<"==============================\n";
	cout<<"1. Insert\n2. Print\n3. Find\n4. Remove\n5. FindKTh\n0. Quit\n";
	cout<<"==============================\n";
	cout<<"\n";




}