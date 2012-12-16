#pragma once

#include <vector>

template <class Type>
class MemVector
{
public:
	MemVector(void)
	{}
	~MemVector(void)
	{}

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
		vector<Type>::iterator it = data.begin();
		for( int i=0; i<index; i++ )
		{
			it++;
		}
		return *it;
	}

	void removeIndex( int index )
	{
		vector<Type>::iterator it = data.begin();
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
	
	vector<Type> data;
};

