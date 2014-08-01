#include <iostream>
#include <fstream>
#include <cstring>
#define NUM 64

using namespace std;

static int success=0,failure=0;

class Book
{
	private:
		char * author, * title, * publisher;
		float price;
		int stock;
	public:
		void assign(char a[],char t[],char p[] , float * f, int * i)
		{
					title=new(char[strlen(t)+1]);
					strcpy(title,t);
					author=new(char[strlen(a)+1]);
					strcpy(author,a);
					publisher=new(char[strlen(p)+1]);
					strcpy(publisher,p);
					price=*f;
					stock=*i;
		};
		void create();
		void transaction();
		void display();

	friend void buybooks(Book *,int);
	friend int main();
};

void buybooks(Book *, int);
void buybooks(Book b[],int count)
{
	char title[64], author[64];
	int stock,n=0;
	
    cout << "\nBook title: ";
	cin.ignore();
	cin.getline(title,64);

	cout << "\nAuthor: ";
	cin.getline(author,64);;

	cout << "\nStock position: ";
	cin >> stock;

	for(int i=0;i<count;++i)
	{
		if( !strcmp(b[i].title,title) || !strcmp(b[i].author,title) && b[i].stock==stock )
		{
			cout << "\nBook available\nEnter number of copies to buy: ";
			cin >> n;
			(b[i].stock)--;
			cout << "\nSuccess\n";
			success++;
			break;
		}
	}
	if(n==0)
	{
		cout << "\nBook unavailable\nFailure\n";
		failure++;
	}
}

int main()
{
	char selection;
	Book b[NUM];
	int count=0;

	do
	{
		cout << "\n---Menu---\n1> Create\n2> Buy book\n3> Transaction\n4> Display\n5> Quit\n=> ";
		cin >> selection;

		switch(selection)
		{
			case '1':
				{
     				char a[64], t[64], p[64];
     				int i;
     				float f;

					cout << "\nBook title: ";
					cin.ignore();
					cin.getline(t,64);
					
					cout << "\nAuthor: ";
					cin.getline(a,64);

					cout << "\nPublisher: ";
					cin.getline(p,64);

					cout << "\nPrice: ";
					cin >> f;

					cout << "\nStock position: ";
					cin >> i;
					
					b[count++].assign(a, t, p, &f, &i);
				}
				break;
			case '2':
				buybooks(b,count);
				break;
			case '3':
				cout << "\nSuccessful transactions: " << success;
				cout << "\nFailed transactions: " << failure << endl;
				break;
			case '4':
				for(int i=0;i<count;++i)
				{
					cout << "\n\n_Book no. " << i+1;
					cout << "_\nBook title: " << b[i].title;
					cout << "\nAuthor: " << b[i].author ;
					cout << "\nPublisher: " << b[i].publisher ;
					cout << "\nPrice: " << b[i].price ;
					cout << "\nStock position: " << b[i].stock << endl;
				}
				break;
			default:
				cout << "Invalid selection\n";
		}
	} while(selection!='5');

	return 0;
}
