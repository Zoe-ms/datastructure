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

	for(queue<int>::iterator iter = myqueue.begin(); iter!=myqueue.end(); iter++)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;

	return 1;
}