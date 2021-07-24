#include<iomanip>
#include<iostream>
#include<string>
#include<vector>

using namespace std;


template <class HashedObj>
class HashTable
{
public :
	explicit HashTable(const HashedObj & notFound, int size=101);
	HashTable(const HashTable & rhs): currentSize(rhs.currentSize),ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND),array(rhs.array) {}

	const HashedObj & find(const HashedObj & x) const;
	void makeEmpty();
	void insert(const HashedObj & x);
	void remove(const HashedObj & x);
	void print(); 
	void create(int size);
	const HashedObj & findarray(const HashedObj & x) const;

	const HashTable & operator=(const HashTable & rhs);

	enum EntryType { ACTIVE, EMPTY, DELETED };
	int isprime(int x)const;
private :
	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry( const HashedObj & e = HashedObj( ),EntryType i = EMPTY ) : element(e),info(i) {}
	};

	vector<HashEntry> array;
	int currentSize;
	const HashedObj ITEM_NOT_FOUND;

	void rehash();
	bool isActive(int currentPos) const;
	int findPos(const HashedObj & x) const;
	
	int nextPrime(int size);
	int hash( const string & key, int tableSize ) const;
    int hash( int key, int tableSize ) const;
void print(int tableSize) const; 
	int  hash2(int x,int tablesize)const;
	
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class HashedObj>
void HashTable<HashedObj>::create(int size)
{
	array.resize(size);
	makeEmpty();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class HashedObj>
void HashTable<HashedObj>::print() 
{
	
	print(array.size());

}

template <class HashedObj>
void HashTable<HashedObj>::print(int tableSize) const
{	
	cout<<"\t------------------------\n\t"<<setw(6)<<"[ADDR]["<<setw(7)<<"ELEMENT]["<<setw(9)<<"INFO]\n";
	for(int i=0;i<tableSize;i++)
		{
			string info = array[i].info==0?"ACTIVE":array[i].info==1?"EMPTY":"DELETED";
			if(i==0){
			cout<<"\t------------------------\n\t"<<"[   0]""[     0  ]""[  ACTIVE]\n";
			}
			else{
				if(array[i].info == EMPTY){
					cout<<"\t------------------------\n\t"<<"["<<i<<"]""[       ]""[  EMPTY]\n";
				}
				else{
					cout<<"\t------------------------\n\t"<<"["<<setw(4)<<i<<"]["<<setw(7)<<array[i].element<<"]["<<setw(7)<<info <<"]\n";
				}
			}
		}
	cout<<"\t------------------------\n";
}

template <class HashedObj>
HashTable<HashedObj>::HashTable( const HashedObj & notFound , int size) : ITEM_NOT_FOUND(notFound),array(nextPrime(size))
{
makeEmpty();
}

////////////////////////////////////////////////////////

template<class HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
	currentSize= 0 ;
	for(int i=0;i<array.size();i++)
		array[i].info= EMPTY;

}

////////////////////////////////////////////////////////

template<class HashedObj>
const HashedObj & HashTable<HashedObj>::find(const HashedObj & x ) const
{
	int currentPos = findPos(x);
	return isActive(currentPos) ? array[currentPos].element : ITEM_NOT_FOUND;
}
////////////////////////////////////////////////////////

template<class HashedObj>
const HashedObj & HashTable<HashedObj>::findarray(const HashedObj & x ) const
{
	int currentPos = findPos(x);
	int index = isActive(currentPos) ? currentPos : ITEM_NOT_FOUND;
	if(index!=ITEM_NOT_FOUND) cout<<"\n\t!!! ADDRESS OF "<<x<<" IN ARRAY INDEX IS "<<index<<" !!!\n\t!!! AND ADDRESS OF MEMORY IS "<<&array[index]<<" !!!\n\n";
	return index;
}

////////////////////////////////////////////////////////

template<class HashedObj>
int HashTable<HashedObj> ::findPos(const HashedObj & x ) const
{
	int collisionNum=0;
	int currentPos = hash(x,array.size());

	while(array[currentPos].info !=EMPTY&&array[currentPos].element != x )
	{
		currentPos =hash(x,array.size())+(++collisionNum)*hash2(x,array.size());
		
		if(currentPos>=array.size())
			currentPos = currentPos%array.size();


		
	}
	return currentPos;
}
template<class HashedObj>
int HashTable<HashedObj> ::hash2(int x,int tablesize) const
{
	int prime=isprime(tablesize);
	return (prime-(x%prime));
}

template<class HashedObj>
int HashTable<HashedObj> ::isprime(int x) const
{
	int prime=0,check=0;
	for(int i=0;i<x;i++)
	{
		check=0;
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				check++;
			}
		}
		if(check<3)
			{
				prime=i;
			}
	}
	//cout<<prime<<endl;
	return prime;
}

////////////////////////////////////////////////////////

template<class HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
	return array[currentPos].info==ACTIVE;
}

////////////////////////////////////////////////////////
 
template<class HashedObj>
void HashTable<HashedObj>::insert(const HashedObj & x)
{
	int currentPos=findPos(x);
	if(isActive(currentPos))
		return;
	array[currentPos]=HashEntry(x,ACTIVE);

	if(++currentSize>array.size()*0.70)
		rehash();

}

////////////////////////////////////////////////////////

template<class HashedObj>
void HashTable<HashedObj>::remove( const HashedObj & x)
{
	int currentPos=findPos(x);
	if(isActive(currentPos))
		array[currentPos].info=DELETED;
}

////////////////////////////////////////////////////////

template <class HashedObj>
void HashTable<HashedObj>::rehash()
{
	vector<HashEntry> oldArray=array;

	array.resize(nextPrime(2*oldArray.size()));
	for(int j=0;j<array.size();j++)
		array[j].info=EMPTY;

	currentSize=0;
	for(int i=0;i<oldArray.size();i++)
		if(oldArray[i].info==ACTIVE)
			insert(oldArray[i].element);
}

////////////////////////////////////////////////////////

template <class HashedObj>
int HashTable<HashedObj>::nextPrime(int size)
{
	int i=2;
	
	while(size%i!=0) i++;
		if(i==size) return i;
		else{
			i=size+1;
			bool check=false;
				while(true){
					for(int j=2;j<=i;j++){
						if(i%j==0&&j<i) break;
						else if(i%j==0&&j==i) check = true; 
					}
				if(check) break;
				i++;
				}
			return i;
		}
}


////////////////////////////////////////////////////////

template<class HashedObj>
int HashTable<HashedObj>::hash(const string & key,int tableSize) const
{
	int hashVal = 0;
	for(int i=0;i<key.length();i++)
		hashVal+=key[i];

	return hashVal % tableSize;

}

template<class HashedObj>
int HashTable<HashedObj>::hash(int key ,int tableSize) const
{
	if( key < 0 ) key -= key;
    return key % tableSize;
}
