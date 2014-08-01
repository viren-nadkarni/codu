#include<iostream>
#include<iomanip>

using namespace std;

int q_slice,n,total_bur_time=0,timer=0,burst_time;

typedef struct element
{
	int arr_time;
	int bur_time;
	int pr_no;
	struct element *next;
}node;

node *start=NULL;

typedef struct list
{
	int start_time;
	int end_time;
	int pr_no;
	struct list *next;
}list;

list *front=NULL,*rear=NULL;

node* create()
{
	node *temp=new node;
	static int i=1;
	cout<<"\n_Process id "<<i;
	temp->pr_no=i;
	cout<<"\nArrival time: ";
	cin>>temp->arr_time;
	cout<<"Burst time: ";
	cin>>temp->bur_time;
	i++;
	total_bur_time+=temp->bur_time;
	return(temp);
}

int get_process()
{
	static node *temp=start;
	int p_no;
	if(temp->arr_time>timer)
		temp=start;
	do
	{
		if(temp->arr_time <=timer && temp->bur_time!=0)
      	{
     		if(temp->bur_time<q_slice)
	   		{
	   			burst_time=temp->bur_time;
	   			temp->bur_time=0;
	   		}
      		else
	  		{
	  			burst_time=q_slice;
	  			temp->bur_time-=q_slice;
	  		}
      		p_no=temp->pr_no;
      		temp=temp->next;
      		break;
      	}
		temp=temp->next;
	}
	while(temp->next!=start);
	return(p_no);
}

void final_list()
{
	int cur_state;
	list *temp=NULL;
	front=new list;
	front->pr_no=1;
	front->start_time=0;
	front->next=NULL;
	rear=front;
	cout<<"\n";
	for(int i=0;i<80;i++)
		cout<<"-";
	cout<<setw(4)<<"P"<<front->pr_no<<setw(3)<<"|"<<setw(3);
	while(timer<total_bur_time)
  	{
  		cur_state=get_process();
  		if(cur_state!=rear->pr_no)
      	{
      		rear->end_time=timer;
      		temp=new list;
      		rear->next=temp;
      		temp->start_time=timer;
      		temp->pr_no=cur_state;
      		cout<<"P"<<temp->pr_no<<setw(3)<<"|"<<setw(3);
      		temp->next=NULL;
      		rear=temp;
      	}
  		timer+=burst_time;
  	}
	rear->end_time=timer;
}

void display()
{
	list *temp=front;
	int i;
	cout << "\n";
	for(i=0;i<80;i++)
   		cout<<"-";
	cout<<front->start_time<<setw(7);
	while(temp!=NULL)
  	{
  		cout<<temp->end_time<<setw(7);
  		temp=temp->next;
  	}
	cout<<"\n";
	for(i=0;i<80;i++)
   		cout<<"-";
}

void calculate()
{
	list *temp=NULL;
	node *ptr=start;
	float avg=0;
	int end_time,i;
	for(i=1;i<=n;i++)
    {
     	temp=front;
     	while(temp!=NULL)
	 	{
	 		if(temp->pr_no==i)
	     		break;
	 		temp=temp->next;
	 	}
     	cout<<"\n_Process "<<i<<" waiting time="<<temp->start_time-ptr->arr_time;
	    avg+=temp->start_time-ptr->arr_time;
     	ptr=ptr->next;
    }
	cout<<"\n\nAverage waiting time= "<<avg/n<<"\n";
	avg=0;
	for(i=1;i<=n;i++)
    {
     	temp=front;
     	while(temp!=NULL)
	 	{
	 		if(temp->pr_no==i)
	     	end_time=temp->end_time;
	 		temp=temp->next;
	 	}
     	cout<<"\n_Process "<<i<<" turnaround time="<<end_time;
	    avg+=end_time;
    }
	cout<<"\n\nAverage turnaround time= "<<avg/n;
}


int main()
{
	int i;
	node *temp=NULL,*ptr=NULL;
	cout<<"Quantum time: ";
	cin>>q_slice;
	cout<<"\nHow many processes? ";
	cin>>n;
	start=create();
	start->next=start;
	ptr=start;
	for(i=1;i<n;i++)
  	{
  		temp=create();
  		ptr->next=temp;
  		temp->next=start;
  		ptr=temp;
  	}
  	cout<<"\nGantt chart:\n";
	final_list();
	display();
	calculate();
	
	cout<<endl;
	system("pause");

	return 0;
}
