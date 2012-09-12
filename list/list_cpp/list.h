//list.h
#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 5

template <typename T> class myQueue
{
private:
	int front;
	int rear;
	T queue[MAX_QUEUE_SIZE];
public:
	myQueue()
	{
		front = rear = 0;
	}

	~myQueue()
	{
		front = rear =0;
	}

	int isQueueEmpty(void)
	{
		return(front == rear);
	}

	int isQueueFull(void)
	{
		return((rear+1)%MAX_QUEUE_SIZE == front);
	}

	int insertQueue(T elem)
	{
		if(isQueueFull())
			return 0;
		queue[rear] = elem;
		rear = (rear+1)%MAX_QUEUE_SIZE;
		return 1;
	}

	int deleteQueue(T &elem)
	{
		if(isQueueEmpty())
			return 0;
		elem = queue[front];
		front = (front+1)%MAX_QUEUE_SIZE;
		return 1;
	}

	void printQueue(void)
	{
		int temp = front;

		while(1)
		{
			if(temp == rear)
				break;
			cout<<queue[temp]<<" ";
			temp = (temp + 1)%MAX_QUEUE_SIZE;
		}
		cout<<endl;
	}
};