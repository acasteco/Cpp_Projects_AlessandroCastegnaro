#include "DynArray.hh"

DynArray::DynArray()								// constructs the class by default
{
	m_data = new int[DYN_ARRAY_DEFAULT_SIZE];
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = 0;
}
DynArray::~DynArray() 
{
	delete[] m_data;
}



DynArray::DynArray(size_t size)						// creates the array with a defined size
{
	m_data = new int[size];
	m_capacity = size;
	m_size = size;
}



DynArray::DynArray(size_t size, const int &value)	// creates and initializes the elements of the array with a value
{
	m_data = new int[DYN_ARRAY_MAX_SIZE];
	m_size = size;
	fill(begin(), end(), value);
}

int *DynArray::begin()const
{
	return m_data;
}

int *DynArray::end()const
{
	return m_data + m_size;
}
void DynArray::fill(int *first, int *last, int value)
{
	for (int *i = first; i < last; i++)
		*i = value;
}

int &DynArray::operator[](size_t n)const 
{
	return m_data[n];
}

bool operator==(const DynArray & lhs, const DynArray & rhs)
{
	if (lhs.m_size == rhs.m_size)
	{
		for (int i = 0; i < lhs.m_size; i++) 
		{
			if (lhs.m_data[i] != rhs.m_data[i])
				return false;
		}
		return true;
	}
	else
		return false;
}
