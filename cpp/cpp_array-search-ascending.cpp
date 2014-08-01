//reads single dimension array
//checks if the values are in ascending order
//if they are in ascending order, searches for any given term
#include <iostream>

using namespace std;

int main()
{
	int list[30], no, i=0, srch;			//declarations
	bool searchflag=false, found=false;
	
	cout << "\nEnter number of terms: ";		//input
	cin >> no;
	cout << endl;
	
	while(i<no)
	{
		cout << "Enter term " << i+1 << ": ";
		cin >> list[i];
		++i;
	}
	
	for (int j=0; j<no ; ++j)			//main
	{
		if(j!=(no-1) && list[j+1]<list[j])
		{
			cout << "\nTerms are not in ascending order...\n";
			break;
		}
		else if(list[j+1]==list[j])
		{
			cout << "\nEqual terms are present...\n";
			break;
		}
		else if(j==no-1)
		{
			cout << "\nTerms are in ascending order...\n";
			searchflag=true;
		}
	}
	
	if(searchflag)					//search
	{
		cout << "\nEnter the term to search for: ";
		cin >> srch;
		
		for(int k=0;k<no;++k)
		{
			if (list[k]==srch)
			{
				cout << "\nThe term '" << srch << "' is the " << k+1 << "th term\n\n";
				found=true;
			}
		}
		if(!found)
			cout << "\nThe term '" << srch << "' was not found...\n\n";
	}
	return 0;
}
