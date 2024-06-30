#include "TASK1.h"

int main()
{
	//QUESTION#1/////////////////////////
	Queue <int> q;
	q.enqueue(5);
	q.enqueue(3);
	q.enqueue(7);
	q.enqueue(35);
	q.enqueue(13);
	q.enqueue(71);
	q.dequeue();
	q.dequeue();
	q.Display();

	//QUESTION#2/////////////////////////
	RoundRobin(q, 40);

	////QUESTION 3//////////////
	string str = "khadija and zinoor and haniya";
	Queue<char> a = StringQueue<char>(str);
	a.Display();
}