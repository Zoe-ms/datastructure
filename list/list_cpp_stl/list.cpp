#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> myqueue;
	int data;

	while(1)
	{
		cin>>data;
		if(data == 0)
			break;
		myqueue.push(data);
	}

	cout<<myqueue.size()<<endl;
	cout<<myqueue.back()<<endl;
	cout<<myqueue.front()<<endl;

	myqueue.pop();

	cout<<myqueue.front()<<endl;

	myqueue.push(10);
	cout<<myqueue.back()<<endl;

	return 1;
}