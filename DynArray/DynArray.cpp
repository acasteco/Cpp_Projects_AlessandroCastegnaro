#include "DynArray.hh"

DynArray::DynArray():								// constructs the class by default
	m_capacity(DYN_ARRAY_DEFAULT_SIZE),
	m_size(0),										//Lista de parametros declarats fora de la funcio
	m_data(new int[DYN_ARRAY_DEFAULT_SIZE])
{
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



DynArray::DynArray(size_t size, const int &value):	// creates and initializes the elements of the array with a value
	m_data(new int[DYN_ARRAY_MAX_SIZE]),
	m_size(size)
{	
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
	for (int *i = first; i != last; i++)
		*i = value;
	/*
	while(first != last)
	{
		*first = value;
		++first;
	}
	*/
}

void DynArray::copy(int * first, int * last, int * dest)
{
	while (first != last)
	{
		dest = first;
		++first;
	}
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


void DynArray::push(const int & val)
{
	if (m_size < m_capacity)
	{
		m_data[m_size++] = val;
	}
	else 
	{
		resize(m_size);
		m_data[m_size++] = val;
	}
}

void DynArray::pop(void)
{
	m_size--;
}

void DynArray::erase(size_t position)
{
	while (position != m_size)
	{
		m_data[position] = m_data[position + 1];
		position++;
	}
}

/*
SI l'array esta ple, hem de fer un resize:
	- verificar que no queda espai
	- crear un tmp 
	- copy
	- push (afegir objecte)
	- lliberar espai de memoria de la llista antiga
	- actualitzar el punter m_data

*/

void DynArray::resize(size_t n)
{
	int *tmp(new int[m_capacity + 1]);
	copy(begin(), end(), tmp);
	delete[] m_data;
	m_data = tmp;
	m_capacity++;
}