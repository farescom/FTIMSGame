#pragma once

#include <list>

using namespace std;

template <class Type>
class MemList
{
public:
	MemList(void)
	{
	}

	~MemList(void)
	{
	}

	Type& New()
	{
		Type newElem;
		data.push_back( newElem );
		return data.back();
	}

	Type& last()
	{
		return data.back();
	}

	Type& operator[]( int index )
	{
		list<Type>::iterator it = data.begin();
		for( int i=0; i<index; i++ )
		{
			it++;
		}
		return *it;
	}

	void removeIndex( int index )
	{
		list<Type>::iterator it = data.begin();
		for( int i=0; i<index; i++ )
		{
			it++;
		}
		data.erase( it );
	}

	void clear()
	{
		data.clear();
	}

	unsigned int elms()
	{
		return data.size();
	}

private:
	list<Type> data;

};

