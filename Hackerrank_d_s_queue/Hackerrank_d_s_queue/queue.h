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
	

	first.push(a);

	/*
	if (!second.empty())
	{
		while (!second.empty()) 
		{
			first.push(second.top());
			second.pop();
		}
	}
		first.push(a);*/
}

template<typename T>
T Queue<T>::dequeue()
{
	if (first.empty() && second.empty()) {
		throw std::out_of_range{ "empty" };
	}
	if (!second.empty()) {
		T val = second.top();
		second.pop();
		return val;
	}
	while (!first.empty()) {
		second.push(first.top());
		first.pop();
	}

	T value = second.top();
	second.pop();



	return value;
	/*while (!first.empty())
	{
		second.push(first.top());
		first.pop();
	}
	T x = second.top();
	second.pop();
	return x;*/
}

template<typename T>
T Queue<T>::front()
{
	if (first.empty() && second.empty()) {
		throw std::out_of_range{ "empty" };
	}
	if (!second.empty()) 
	{
		return second.top();
	}
	while (!first.empty()) 
	{
		T x;
		x = first.top();
		first.pop();
		second.push(x);
	}
	return second.top();
	/*while (!first.empty())
	{
		second.push(first.top());
		first.pop();
	}
	
	return second.top();*/
}