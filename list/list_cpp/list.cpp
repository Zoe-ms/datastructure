//list.cpp
#include "list.h"

int main()
{
	myQueue<double> t;
	double data;
	double &elem = data;

	while(1)
	{
		cin>>data;
		if(data == 0) break;
		if(!t.insertQueue(data))
		{
			cout<<"Insert Queue Failed!"<<endl;
			break;
		}
	}
	t.printQueue();
	t.deleteQueue(elem);
	t.deleteQueue(elem);
	t.printQueue();
	return 1;
}