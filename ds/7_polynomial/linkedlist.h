struct node
{
	int x_deg, y_deg, z_deg, coeff;
	struct node * next;
};

typedef struct node Node;

Node * getnode();
void freenode(Node *);

void insertEnd(Node **,int,int,int,int);
void insertFront(Node **, int,int,int,int);

void removeEnd(Node **);
void removeFront(Node **);
void removeNode(Node **, int, int);
