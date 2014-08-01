#include <stdio.h>
#include <stdlib.h>
#include "dynamictree.h"
#define MAXSIZE 64

int main()
{
	Node *tree;
	int list[MAXSIZE],i,num;
	
	printf("How many items? ");
	scanf("%d",&num);
	
	printf("\nList them: ");
	for(i=0;i<num;++i)
		scanf("%d",&list[i]);
	
	for(i=0;i<num;++i)
	{
		if(i==0)
			tree=createRoot(list[i]);		
		else
			binInsert(tree,list[i]);
	}
	
	treeHeight(tree);
	printf("\nHeight: %d",height);

	printf("\nPre-order traversal: ");
	traversePreOrder(tree);
	
	printf("\nIn-order traversal: ");
	traverseInOrder(tree);
	
	printf("\nPost-order traversal: ");
	traversePostOrder(tree);
	printf("\n");
	
	return 0;
}

void treeHeight(Node *root)
{
	h++;
	
	if(root->left!=NULL)
		treeHeight(root->left);
		
	if(root->right!=NULL)
		treeHeight(root->right);
	
	if(h>height)
		height=h;
		
	h--;
}
