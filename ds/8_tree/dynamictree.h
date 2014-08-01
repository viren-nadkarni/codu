struct node
{
	int data;
	struct node *left, *right;
};

typedef struct node Node;

static int height=-1,h=-1;


Node * getnode();
void freenode(Node *);

Node *createRoot(int);

void insertChildLeft(Node *,int);
void insertChildRight(Node *,int);

void traverseInOrder(Node *);
void traversePreOrder(Node *);
void traversePostOrder(Node *);

void treeHeight(Node *);

void binInsert(Node *node, int value);
