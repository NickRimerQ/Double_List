#include "Header.h"

template<typename T>
Double_List<T>::Double_List()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
Double_List<T>::~Double_List()
{
	clear();
}

template<typename T>
void Double_List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else if (tail == nullptr)
	{
		tail = new Node<T>(data, nullptr, head);
		head->pNext = tail;
	}
	else
	{
		Node<T>* temp = tail;
		tail = new Node<T>(data, nullptr, tail);
		temp->pNext = tail;
	}
	Size++;
}

template<typename T>
T& Double_List<T>::operator[](const int index)
{


	if (Size / 2 >= index)
	{
		int counter = 0;

		Node<T>* temp = this->head;

		while (temp != nullptr)
		{
			if (counter == index)
			{
				return temp->data;
			}
			temp = temp->pNext;
			counter++;
		}
	}
	else
	{
		int counter = Size - 1;

		Node<T>* temp = this->tail;

		while (temp != nullptr)
		{
			if (counter == index)
			{
				return temp->data;
			}
			temp = temp->pPrev;
			counter--;
		}
	}


}

template<typename T>
void Double_List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void Double_List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;

	Size--;
}

template<typename T>
void Double_List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void Double_List<T>::pop_back()
{
	Node<T>* temp = tail;
	tail = tail->pPrev;
	delete temp;

	Size--;
}

template<typename T>
int Double_List<T>::GetSize()
{
	return Size;
}

template<typename T>
bool Double_List<T>::isEmpty()
{
	if (Size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<typename T>
void Double_List<T>::insert(T data, int index)
{
	if (Size / 2 >= index)
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext, previous);

		Node<T>* current = previous->pNext;
		current->pPrev = newNode;

		previous->pNext = newNode;

		Size++;
	}
	else
	{
		Node<T>* next = this->tail;

		for (int i = Size; i > index + 1; i--)
		{
			next = next->pPrev;
		}

		Node<T>* newNode = new Node<T>(data, next, next->pPrev);

		Node<T>* current = next->pPrev;
		current->pNext = newNode;

		next->pPrev = newNode;

		Size++;
	}
}

template<typename T>
void Double_List<T>::removeAt(int index)
{
	if (Size / 2 >= index)
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		Node<T>* next = toDelete->pNext;

		next->pPrev = previous;

		delete toDelete;

		Size--;
	}
	else
	{
		Node<T>* next = this->tail;

		for (int i = Size - 1; i > index + 1; i--)
		{
			next = next->pPrev;
		}



		Node<T>* toDelete = next->pPrev;

		next->pPrev = toDelete->pPrev;

		Node<T>* previous = toDelete->pPrev;

		previous->pNext = next;

		delete toDelete;

		Size--;
	}
}
