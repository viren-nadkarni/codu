/* Uses an array of structures to store name, branch, roll number and score percentage 
 * Uses a menu system to
 * add entries, remove entries, and search entries by name, rollno, branch, and score (> or <)
 */

#include <iostream>

using namespace std;

struct db				//structure definition
{
	int roll;
	string name, branch;
	float pc;
};

static int num=0; 			//global variable which stores number of entries currently in database

int mainMenu();				//function prototypes
void addEntry(db *);
void remEntry(db *);
void viewEntry(db *);
void searchEntry(db *);
void dele(db *,int);

int main()				//main function
{
	int mnu;
	bool quitp=false;
	db list[20];
	
	cout << "\n*** \t ***\n\nAdding entries for the first time";
	addEntry(list);
	
	do				//calls relevent function according to menu selection
	{
		mnu=mainMenu();
		switch(mnu)
		{
			case 1:
				addEntry(list);
				break;
			case 2:
				remEntry(list);
				break;
			case 3:
				searchEntry(list);
				break;
			case 4:
				viewEntry(list);
				break;
			case 5:
				quitp=true;
				break;
		}
	} while(!quitp);
	
	return 0;
}

int mainMenu()				//menu selections
{
	int mnu;

	cout << "\n--- Main Menu ---\n1: Add more entries\n2: Remove an entry\n3: Search\n4: View all entries\n5: Exit\n=> ";
	cin >> mnu;
	
	return mnu;
}

void addEntry(db list[])		//add an entry
{
	char conf='n';
	cout << "\nPlease enter the details";
	
	do
	{
		conf='n';
		cout << "\n--- Entry no. " << num+1;
		
		cout << " ---\nName: ";
		cin >> list[num].name;
		
		cout << "Branch: ";
		cin >> list[num].branch;
		
		cout << "Roll number: ";
		cin >> list[num].roll;
		
		cout << "Percent score: ";
		cin >> list[num].pc;
		
		num++;
		
		cout << "\nAdd another entry?(y/n)\n==>";
		cin >> conf;
	}while(conf=='y');
}


void remEntry(db list[])		//remove an entry
{
	int rolln, mn, entr, tag;
	bool found;
	
	cout << "\n   Delete by\n   1:Entry number\n   2:Roll number\n   =>";
	cin >> mn;
	
	if (mn==1)
	{
		cout << "\nEnter entry number: ";
		cin >> entr;
		if(entr!=0)
			entr--;
	}
	if (mn==2)
	{
		cout << "\nEnter roll number: ";
		cin >> rolln;
	}
	
	if(mn==1)
		dele(list,entr);
	
	if(mn==2)
	{
		for(int i=0;i<num;++i)
		{
			if(list[i].roll==rolln)
			{
				tag=i;
				found=true;
				break;
			}
		
		}
		if(found)
			dele(list,tag);
	}
}


void searchEntry(db list[])		//search for an entry by a given parameter
{
	int mnu, mnu2, rolln;
	float pcnt;
	string nme,brnch;
	
	cout << "\n   Search by\n   1: Name\n   2: Branch\n   3: Roll number\n   4: Score percentage\n   =>";
	cin >> mnu;
	
	switch(mnu)
	{
		case 1:
			cout << "\nEnter name: ";
			cin.ignore();
			getline(cin,nme);
			cout << "Results: \n";
			
			for(int i=0;i<num;++i)
			{
				if(list[i].name==nme)
				{
					cout << "~ Name: " << list[i].name << endl;
					cout << "  Entry number: " << i+1 << endl
						<< "  Roll number: " << list[i].roll << endl
						<< "  Branch: " << list[i].branch << endl
						<< "  Percentage: " << list[i].pc << endl;
				}
			}
			cout  << "\t..." << endl;
			break;
				
		case 2:
			cout << "\nEnter branch: ";
			cin >> brnch;
			cout << "\nResults: \n";
			
			for(int i=0;i<num;++i)
			{
				if(list[i].branch==brnch)
				{
					cout << "~ Name: " << list[i].name << endl;
					cout << "  Entry number: " << i+1 << endl
						<< "  Roll number: " << list[i].roll << endl
						<< "  Branch: " << list[i].branch << endl
						<< "  Percentage: " << list[i].pc << endl;
				}
			}
			cout  << "\t..." << endl;
			break;
				
		case 3:
			cout << "\nEnter roll number: ";
			cin >> rolln;
			cout << "\nResults: \n";
			
			for(int i=0;i<num;++i)
			{
				if(list[i].roll==rolln)
				{
					cout << "~ Name: " << list[i].name << endl;
					cout << "  Entry number: " << i+1 << endl
						<< "  Roll number: " << list[i].roll << endl
						<< "  Branch: " << list[i].branch << endl
						<< "  Percentage: " << list[i].pc << endl;
				}
			}
			cout  << "\t..." << endl;
			break;
				
		case 4:
			cout << "\n     Students having percentage\n     1: Greater than\n     2: Less than\n     =>";
			cin >> mnu2;
			
			cout << "\nEnter percentage: ";
			cin >> pcnt;
			cout << "Results:\n";
			
			for (int i=0;i<num;++i)
			{
				if(pcnt<list[i].pc && mnu2==1)
					cout << "~ Name: " << list[i].name << endl
						<< "  Entry number: " << i+1 << endl
						<< "  Roll number: " << list[i].roll << endl
						<< "  Branch: " << list[i].branch << endl
						<< "  Percentage: " << list[i].pc << endl;
				
				if(pcnt>list[i].pc && mnu2==2)
					cout << "~ Name: " << list[i].name << endl
						<< "  Entry number: " << i+1 << endl
						<< "  Roll number: " << list[i].roll << endl
						<< "  Branch: " << list[i].branch << endl
						<< "  Percentage: " << list[i].pc << endl;
			}
			cout  << "\t..." << endl;
			break;
			
		default:
			cout << "\nInvalid selection!\n";
	}
}


void dele(db list[], int i)		// delete an entry - behind the scene
{
	while(i+1<num)
	{
		list[i].name=list[i+1].name;
		list[i].branch=list[i+1].branch;
		list[i].roll=list[i+1].roll;
		list[i].pc=list[i+1].pc;
		++i;
	}
	--num;
}


void viewEntry(db list[])
{
	cout << endl << "All entries:" << endl;
	for(int i=0;i<num;++i)
	{
		cout << "~ Name: " << list[i].name << endl
			<< "  Entry number: " << i+1 << endl
			<< "  Roll number: " << list[i].roll << endl
			<< "  Branch: " << list[i].branch << endl
			<< "  Percentage: " << list[i].pc << endl;
	}
	cout  << "\t..." << endl;
}

