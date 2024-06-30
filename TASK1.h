#pragma once
#include <iostream>
using namespace std;

template <class T>
struct node
{
	T data;
	node <T>* next;
};

template <class T>
class Queue {
private:
	node<T>* front;
	node<T>* rear;
public:
	Queue()
	{
		front = rear = NULL;
	}

	void enqueue(int d)
	{
		node<T>* temp = new node<T>;
		temp->data = d;
		temp->next = NULL;
		if (front == NULL)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			node<T>* temp1 = rear;
			temp1->next = temp;
			temp->next = NULL;
			rear = temp;
		}
	}

	void dequeue()
	{
		node <T>* temp = front;
		front = front->next;
		delete temp;
	}

	int Front()
	{
		return front->data;
	}

	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;
	}

	void Display()
	{
		node<T>* p = front;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;

		}
		cout << endl;
	}
};

template <class T>
void RoundRobin(Queue<T> q, T QuantumTime)
{
	T front = q.Front();
	int d;
	while (!q.isEmpty())
	{
		front = q.Front();
		d = front- QuantumTime;
		cout << "execution time: " << front << " and running time: " << d << endl;
		if (d > 0)
		{
			q.dequeue();
			q.enqueue(d);
		}
		else
		{
			q.dequeue();
		}
	}
}

template <class T>

Queue<T> StringQueue(string str)
{
	Queue<T> mainQ;
	Queue<T> temp;

	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		temp.enqueue(str[i]);

		if (str[i] == ' ')
		{
			while (!temp.isEmpty())
			{
				T a = temp.Front();
				mainQ.enqueue(a);
				temp.dequeue();
			}
		}

		i++;
	}

	while (!temp.isEmpty())
	{
		T a = temp.Front();
		mainQ.enqueue(a);
		temp.dequeue();
	}

	return mainQ;
}
