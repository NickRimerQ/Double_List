#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Double_List
{	
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data_ = T(), Node* pNext_ = nullptr, Node* pPrev_ = nullptr)
		{
			data = data_;
			pNext = pNext_;
			pPrev = pPrev_;
		}
	};
	int Size;
	Node<T>* head;
	Node<T>* tail;

public:
	Double_List();
	~Double_List();
	void push_back(T data);
	T& operator[](const int index);
	void push_front(T data);
	void pop_front();
	void clear();
	void pop_back();
	int GetSize()
	{
		return Size;
	}
};