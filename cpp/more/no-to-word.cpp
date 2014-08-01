#include <iostream>

using namespace std;

void order(int);

int main()
{
	char num[10];
	int lth=0,p;
	
	cout << "\nEnter number: ";
	cin >> num;
	
	for(int i=0 ; num[i]!='\0' ; ++i)
		lth++;
	
	
	cout << "\nIn words: ";
	p=lth;
	
	for(int i=0; i<lth; ++i)
	{
		switch(num[i])
		{
			case '1':
				cout << "one ";
				break;
			case '2':
				cout << "two ";
				break; 
			case '3':
				cout << "three ";
				break;
			case '4':
				cout << "four ";
				break;
			case '5':
				cout << "five ";
				break;
			case '6':
				cout << "six ";
				break;
			case '7':
				cout << "seven ";
				break;
			case '8':
				cout << "eight ";
				break;
			case '9':
				cout << "nine ";
				break;
			case '0':
				if(p!=2)
					cout << "zero ";
				break;				
		}
		order(p);
		p--;
	}
	cout << endl << endl;	
	return 0;
}

void order(int p)
{
	switch(p)
	{
		case 0:
			cout << "only ";
			break;
		case 3:
			cout << "hundred and ";
			break;
		case 4:
			cout << "thousand ";
			break;
		case 6: 
			cout << "lakhs ";
			break;		
		case 8:
			cout << "crores ";
			break;
	}
}
