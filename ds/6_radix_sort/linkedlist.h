struct node
{
	int data;
	struct node * next;
};

typedef struct node Node;

Node * getnode();
void freenode(Node *);

void insertEnd(Node **,int);
void insertFront(Node **, int);

void removeEnd(Node **);
void removeFront(Node **);

int returnFront(Node **);

void printList(Node *);

int valueFront(Node **);
