//reverse a list(single)
Node * reverse(Node *);
Node * reverse(Node * ptr)
{
	Node * tmp;
	Node * previous=NULL;
	
	while(ptr!=NULL)
	{
		tmp=ptr->next;
		ptr->next=previous;
		previous=ptr;
		ptr=tmp;		
	}
	return previous;
}