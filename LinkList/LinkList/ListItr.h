#include<iostream>
template<class Object>
class ListItr{
public : 
	ListItr():current(NULL){}
	bool isPastEnd() comst{return current == NULL;}

	void advance(){
		if(!isPastEnd()) current=current->next;
	}

	const Oject & retrieve() const{
		if(isPastEnd()) throw BadIterator();
		return current->element;
	}
private : 
	ListNode<Object> *current;
	ListItr(ListNode<Object> *current;) : current(theNode){}
	friend class List<Object>;
}