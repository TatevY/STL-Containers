#pragma once

#include"BaseList.h"
#include<assert.h>

template<class T>

class LinkedList :public BaseList<T>
{
public:
	struct Node
	{	Node(const T& data=T(),Node* n=nullptr):
							next(n),data(data){}
		Node * next;
		T data;
	};

	bool empty() override
	{
		return size();
	}


	size_t size() const override
	{
		return size;
	}



	void insert(const T& data, size_t pos) override
	{
		assert(pos > 0);
		if (pos > size + 1)
		{
			throw("Invalid size");
		}

		if (pos == 1)
		{
			head = new Node(data, head);
			size++;
			return;
		}
		auto temp = head;
		
		if (pos = size())
		{
			for (size_t i = 1; i < pos; ++i)
			{
				temp = temp->next;
				last = new Node(data, nullptr);
				last = temp->next;
				size++;
				return;
			}
		}

		for (size_t i = 1; i < pos; ++i)
		{
			temp = temp->next;
			if (i == pos - 1)
			{	
				auto tmp_next = temp->next;
				node = new Node(data, nullptr);
				node = temp->next;
				tmp_next = node->next;
				size++;
				return;
			}
		}
//		node = new Node(data, temp);		
	}


	void erase(size_t index) override
	{

		assert(index > 0);
		if (index > size + 1)
		{
			throw("Invalid index");
		}

		auto temp = head;

		if (index == 1)
		{	

			head = head->next;
			delete temp;
			size--;
			return;
		}


		if (index = size())
		{

			for (size_t i = 1; i < index; ++i)
			{
				
				temp = temp->next;
				if (i == index - 1) 
				{
					auto last = temp;
					delete temp->next;
					size--;
					return;
				}
				
			}

		}


		for (size_t i = 1; i < index; ++i)
		{
			temp = temp->next;
	
			if (i == index - 1)
			{
				
				auto tmp_del = temp->next;
				auto tmp_del_next = tmp_del->next;
				tmp_del_next = temp->next;
				delete tmp_del;
				size--;
				return;

			}

//			temp = tmp_prev->next;
			
	
		}


	}


	void clear() override
	{
		while (!empty())
		{
			for (i = 1; i <= size(); i++)
			{
				erase(i);
			}
			
		}
	}


private:
	size_t size;
	Node * head;
};


