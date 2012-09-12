//list.cpp
#include "list.h"
#include <iostream>
using namespace std;

myQueue *createQueue(void)    //��ʼ������
{
	myQueue *head = (myQueue *)malloc(sizeof(myQueue));
	head->node_num = 0;
	head->front = NULL;
	head->rear = NULL;
	return head;
}

int isQueueEmpty(myQueue *head)   //�ж϶����Ƿ�Ϊ��
{
	return(head->node_num==0);
}

int isQueueFull(myQueue *head)   //�ж϶����Ƿ�Ϊ��
{
	return(head->node_num==MAX_SIZE);
}

int insertQueue(myQueue *head, int elem)
{
	if(isQueueFull(head))  //������
		return 0;
	else if(isQueueEmpty(head))   //���п�
	{
		myList *temp = (myList *)malloc(sizeof(myList));
		temp->value = elem;
		temp->next =NULL;
		head->rear = temp;
		head->front = temp;
		head->node_num ++;
		return 1;
	}
	else
	{
		myList *temp = (myList *)malloc(sizeof(myList));
		temp->value = elem;
		temp->next =NULL;
		head->rear->next = temp;
		head->rear =temp;
		head->node_num++;
		return 1;
	}
}

int deleteQueue(myQueue *head, int *elem)   //ɾ��Ԫ��
{
	if(isQueueEmpty(head))
		return 0;
	else
	{
		myList *temp;
		temp = head->front;
		*elem = temp->value;
		head->front = temp->next;
		head->node_num--;
		free(temp);
		return 1;
	}
}

void printQueue(myQueue *head)   //��ӡ����Ԫ��
{
	myList *temp;

	temp = head->front;
	while(temp != NULL)
	{
		cout<<temp->value<<" ";
		temp = temp->next;
	}
	free(temp);
	cout<<endl;
}

void freeQueue(myQueue *head)  //�����������е�ָ��free
{
	myList *temp;

	temp=head->front;
	while(temp)
	{
		temp = head->front->next;
		free(head->front);
		head->front = temp;
	}
	free(temp);
}

int main()
{
	myQueue *head;
	int data;
	int *elem = (int *)malloc(sizeof(int));

	head = createQueue();

	while(1)
	{
		cin>>data;
		if(data == 0) break;
		if(!insertQueue(head, data))
		{
			cout<<"Inset Queue Failed!"<<endl;
			break;
		}
	}

	printQueue(head);

	deleteQueue(head, elem);
	
	cout<<*elem<<endl;

	printQueue(head);

	free(elem);

	freeQueue(head);

	free(head);

	return 1;
}