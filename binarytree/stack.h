#include <iostream>
using namespace std;

#define MAX_SIZE 10

template <typename T> class myStack
{
private:
	int top;
	T stack[MAX_SIZE];

public:
	myStack(void)
	{
		top = 0;	
	}

	~myStack(void)
	{
		top = -1;
	}

	int isStackFull(void)
	{
		return(top==MAX_SIZE-1);
	}
	
	int isStackEmpty(void)
	{
		return(top==0);
	}

	void stackPrint(void)
	{
		int tmp = 0;

		while(tmp!=top)
			cout<<stack[tmp++]<<" ";
		cout<<endl;
	}

	int stackPush(T elem)
	{
		if(isStackFull())
			return 0;
		stack[top++] = elem;
		return 1;
	}

	int stackPop(T &elem)
	{
		if(isStackEmpty())
			return 0;
		elem = stack[--top];
		return 1;
	}

	int stackTop(T &elem)
	{
		if(isStackEmpty())
			return 0;
		elem = stack[top-1];
		return 1;
	}
};