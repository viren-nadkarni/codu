#include <stdio.h>
#include <stdlib.h>
#include "dynamictree.h"

Node *getnode()
{
	Node *tmp;
	tmp=(Node *)malloc(sizeof(Node));
	tmp->left=NULL;
	tmp->right=NULL;
	
	return tmp;
}

void freenode(Node * tmp)
{
	free(tmp);
}	

void insertChildLeft(Node *parent, int value)
{
	Node *n;
	n=getnode();
	n->data=value;
	
	if(parent->left!=NULL)
		printf("_ Left child value overwritten\n");
	
	parent->left=n;	
}

void insertChildRight(Node *parent, int value)
{
	Node *n;
	n=getnode();
	n->data=value;
	
	if(parent->right!=NULL)
		printf("_ Right child value overwritten\n");
	
	parent->right=n;	
}

Node *createRoot(int value)
{
	Node *n;
	n=getnode();
	n->data=value;
	
	return n;
}

void traverseInOrder(Node *root)
{
	if(root->left!=NULL)
		traverseInOrder(root->left);
		
	printf("%d ",root->data);
	
	if(root->right!=NULL)
		traverseInOrder(root->right);
}

void traversePreOrder(Node *root)
{
	printf("%d ",root->data);
	
	if(root->left!=NULL)
		traverseInOrder(root->left);
		
	if(root->right!=NULL)
		traverseInOrder(root->right);

}

void traversePostOrder(Node *root)
{
	if(root->left!=NULL)
		traverseInOrder(root->left);
		
	if(root->right!=NULL)
		traverseInOrder(root->right);

	printf("%d ",root->data);
}

void binInsert(Node *node,int value)
{
	if(value<node->data)
	{
		if(node->left==NULL)
			insertChildLeft(node,value);
		else
			binInsert(node->left,value);
	}
	else if(value>(node->data))
	{
		if(node->right==NULL)
			insertChildRight(node,value);
		else
			binInsert(node->right,value);
	}
}

