#pragma once

template <class T>
class BaseList
{
public:
	BaseList() = default;
	virtual BaseList() = default;

	virtual bool empty() = 0;
	virtual size_t size() const = 0;
	virtual void insert(const T& data, size_t pos) = 0;
	virtual void erase(size_t index) = 0;
	virtual void clear() = 0;
};
