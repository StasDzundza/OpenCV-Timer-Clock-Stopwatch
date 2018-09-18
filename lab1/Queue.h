#pragma once
#include"sqd_arr.h"
#include"sqd_list.h"
//enum MODE
//{
//	list,
//	arr
//};
template<typename T>
class queue
{
public:
	virtual void push_back(T a) = 0;
	virtual void show() = 0;
	virtual bool is_empty() = 0;
	virtual T back() = 0;
	virtual T front() = 0;
	virtual T pop() = 0;//delete from begin
	virtual bool erase_from_position(int position) = 0;
	virtual bool delete_data(T a) = 0;
	virtual int size() = 0;
};

template<typename T>
class Queue :public queue<T>
{
public:

	Queue() {}
	Queue(int size)
	{
		arrr = sqd_arr<T>(size);
	}
	void push_back(T a) override;
	void show() override;
	void set_state(int st);
	bool is_empty() override;
	T back() override;
	T front() override;
	T pop() override;//delete from begin
	bool erase_from_position(int position) override;
	bool delete_data(T a) override;
	int size() override;
private:
	MODE mode;
	sqd_list<T> lst;
	sqd_arr<T> arrr;
};

template<typename T>
void Queue<T>::set_state(int state)
{
	if (state == 1)
		mode = MODE::list;
	else
		mode = MODE::arr;
}
template<typename T>
void Queue<T>::push_back(T a)
{
	if (mode == MODE::list)
		lst.add_queue(a);
	else
		arrr.add_qu(a);
}

template<typename T>
void Queue<T>::show()
{
	if (mode == MODE::list)
		lst.show();
	else
		arrr.show();
}
template<typename T>
bool Queue<T>::is_empty()
{
	if (mode == MODE::list)
		return lst.is_empty();
	else
		return arrr.is_empty();
}
template<typename T>
T Queue<T>::back()
{
	if (mode == MODE::list)
		return lst.back();
	else
		return arrr.back();
}
template<typename T>
T Queue<T>::front()
{
	if (mode == MODE::list)
		return lst.front();
	else
		return arrr.front();
}
template<typename T>
T Queue<T>::pop()
{
	if (mode == MODE::list)
		return lst.pop();
	else
		return arrr.pop();
}

template<typename T>
bool Queue<T>::erase_from_position(int position)
{
	if (mode == MODE::list)
		return lst.erase_position(position);
	else
		return arrr.erase_position(position);
}

template<typename T>
bool Queue<T>::delete_data(T a)
{
	if (mode == MODE::list)
		return lst.delete_data(a);
	else
		return arrr.delete_data(a);
}

template<typename T>
int Queue<T>::size()
{
	if (mode == MODE::list)
		return lst.size();
	else
		return arrr.size();
}
