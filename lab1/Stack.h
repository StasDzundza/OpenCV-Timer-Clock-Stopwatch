#pragma once
#include"sqd_list.h"
#include"sqd_arr.h"
#include"SQD.h"
enum MODE
{
	list,
	arr
};
template<typename T>
class Stack:public SQD<T>
{
public :
	
	Stack() { impl = new sqd_list<T>; }
	Stack(int size)
	{
		if(size > 0)
			this->SIZE = size;
	}
	
	void push_front(T a) override;
	void show() override;
	void set_mode(int mode);
	bool is_empty() override;
	T back() override;
	T front() override;
	T pop_front() override;//delete from begin
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() override;
private:
	MODE mode = list;
	int SIZE = 0;//��� ������
	SQD<T>*impl;
	void push_back(T a) override;
	T pop_back() override;
};

template<typename T>
void Stack<T>::set_mode(int mode)
{
	if (mode == 1)
	{
		impl = new sqd_list<T>;
	}
	else if(mode == 2)
	{
		if(SIZE > 0)
			impl = new sqd_arr<T>(SIZE);
		else
			impl = new sqd_arr<T>;
	}	
	else
	{

	}
}
template<typename T>
void Stack<T>::push_front(T a)
{
	impl->push_front(a);
}

template<typename T>
void Stack<T>::show()
{
	impl->show();
}
template<typename T>
bool Stack<T>::is_empty()
{
	return impl->is_empty();
}
template<typename T>
T Stack<T>::back()
{
	return impl->back();
}
template<typename T>
T Stack<T>::front()
{
	return impl->front();
}
template<typename T>
T Stack<T>::pop_front()
{
	return impl->pop_front();
}

template<typename T>
bool Stack<T>::erase_from_position(int position)
{
	return impl->erase_from_position(position);
}

template<typename T>
bool Stack<T>::delete_data(T a)
{
	return impl->delete_data(a);
}

template<typename T>
int Stack<T>::size()
{
	return impl->size();
}
///////////////////////////////////������� �� �� ����������� � ������ �������� ���������(��� �� �� ������ ���������������)
template<typename T>
void Stack<T>::push_back(T a)
{
}
template<typename T>
T Stack<T>::pop_back()
{
	return false;
}