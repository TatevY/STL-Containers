#pragma once
#include <assert.h>

template<typename T>

class Vector
{

public:
	
	Vector()
		:m_capacity{ 0 }
		, m_size{ 0 }
		, m_vec{ 0 }{}

	Vector(size_t size);
	Vector(size_t size, const T& initial);
	Vector(const Vector<T>& vector);
	~Vector();


	size_t size() const;
	size_t capacity() const;
	bool empty()const;

	void push_back(const T& elem);
	void pop_back();


	T& operator[] (const size_t& index);
	Vector<T>& operator = (const Vector<T>& vector);
	void clear();

private:

	size_t m_size;
	size_t m_capacity;
	T m_vec;

};

template<typename T>
inline Vector<T>::Vector(size_t size)
{
	m_capacity = size;
	m_size  = size;
	m_vec = new T[size];
}

template<typename T>
inline Vector<T>::Vector(size_t size, const T& initial)
{
	m_capacity = size;
	m_size = size;
	m_vec = new T[size];

	for (size_t i = 0; i < m_size; i++)
		m_vec[i] = initial;
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& vector)
{
	m_size = vector.m_size;
	m_capacity = vector.m_capacity;
	m_vec = new T[m_size];

	for (size_t i = 0; i < m_size; i++)
		m_vec[i] = vector.m_vec[i];
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] m_vec;
}

template<typename T>
inline size_t Vector<T>::size() const
{
	return m_size;
}

template<typename T>
inline size_t Vector<T>::capacity() const
{
	return m_capacity;
}


template<typename T>
inline bool Vector<T>::empty() const
{
	return size == 0;
}


template<typename T>
inline void Vector<T>::push_back(const T& elem)
{
	if (m_capacity == m_size)
	{
		m_capacity *= 2;
		T* tmp_vec = m_vec;
		m_vec = new T[m_capacity];

		for (size_t i = 0; i < m_size; ++i)
			m_vec[i] = tmp_vec[i];

		delete tmp_vec;

	}

	m_vec[m_size++] = elem;
}

template<typename T>
inline void Vector<T>::pop_back()
{
	assert(m_size);
	--m_size;
}


template<typename T>
inline T& Vector<T>::operator[](const size_t& index)
{
	
	assert(index >= 0 && index <= m_size)
		return m_vec[i];

}

template<typename T>
inline void Vector<T>::clear()
{
	m_capacity = 0;
	m_size = 0;
	m_vec = 0;

}


template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& vector)
{

	if (this == &vector)
		return *this;

	if (m_capacity < vector.m_size)
	{
		m_capacity *= 2;
		m_vec = new T[m_capacity];
	}

	for (szie_t = 0; i < vector.m_size; ++i)
		m_vec[i] = vector.m_vec[i];
	m_size = vector.m_size;
	return *this;
}
