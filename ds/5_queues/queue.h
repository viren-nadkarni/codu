//FILE: queue.h

struct queue
{
	int front,rear;
	int items[64];
};

void insertq(struct queue *, int);
int removeq(struct queue *);
int sizeofq(struct queue *);
