//list.h
#define MAX_SIZE 100

typedef struct _myList{
	int value;
	struct _myList *next;
}myList;

typedef struct _myQueue{
	int node_num;
	myList *front;
	myList *rear;
}myQueue;


