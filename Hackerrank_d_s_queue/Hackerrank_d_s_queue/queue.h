#pragma once
#include <stack>
#include <iostream>


template<typename T>
class Queue
{
public:
	Queue() = default;
	void enqueue(const T&);
	T dequeue();
	T front();

private:
	std::stack<T> first;
	std::stack<T> second;
};

template<typename T>
void Queue<T>::enqueue(const T& a)
{
	if (!second.empty())
	{
		while (!second.empty()) 
		{
			first.push(second.top());
			second.pop();
		}
	}
		first.push(a);
}

template<typename T>
T Queue<T>::dequeue()
{
	while (!first.empty())
	{
		second.push(first.top());
		first.pop();
	}
	T x = second.top();
	second.pop();
	return x;
}

template<typename T>
T Queue<T>::front()
{
	while (!first.empty())
	{
		second.push(first.top());
		first.pop();
	}
	
	return second.top();
}