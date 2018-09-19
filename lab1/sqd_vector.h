#pragma once
#include"SQD.h"
#include<vector>
using namespace std;
template<typename T>
class sqd_vector :public SQD<T>//������ ���� ���� � �����
{
public:
	sqd_deque() { }
	//functions for stack in list
	void add_stack(T a);

	//functions for queue in list
	void add_queue(T a);

	//functions for deque in list
	void push_front(T a)override;
	void push_back(T a)override;
	T pop_front()override;
	T pop_back()override;

	//same functions for all 
	void show()override;
	bool is_empty()override;
	T back()override;
	T front()override;
	bool erase_from_position(int position)override;
	bool delete_data(T a)override;
	int size()override;
private:
	deque<T> DEQUE;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
void sqd_deque<T>::add_stack(T a)
{
	DEQUE.push_front(a);
}


template<typename T>
T sqd_deque<T>::back()
{
	return DEQUE.back();
}


template<typename T>
T sqd_deque<T>::front()
{
	return DEQUE.front();
}

template<typename T>
T sqd_deque<T>::pop_front()
{
	T tmp = DEQUE.front();
	DEQUE.pop_front();
	return tmp;
}


template<typename T>
bool sqd_deque<T>::erase_from_position(int position)
{
	//deque<T> ::iterator;
}
template<typename T>
bool sqd_deque<T>::delete_data(T data)
{

}
template<typename T>
int sqd_deque<T>::size()
{
	return DEQUE.size();
}


/////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_deque<T>::add_queue(T a)
{
	DEQUE.push_back(a);
}


/////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
void sqd_deque<T>::show()
{

}

template<typename T>
bool sqd_deque<T>::is_empty()
{
	return DEQUE.empty();
}

template<typename T>
void sqd_deque<T>::push_back(T a)
{
	DEQUE.push_back(a);
}
template<typename T>
void sqd_deque<T>::push_front(T a)
{
	DEQUE.push_front(a);
}
template<typename T>
T sqd_deque<T>::pop_back()
{
	T tmp = DEQUE.back();
	DEQUE.pop_back();
	return tmp;
}
