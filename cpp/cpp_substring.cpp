/* looks for matching substring in a string */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int lmainstr=0, lsubstr=0, i=0, j=0, flagb=0, x, y, endflag=0;
	char mainstr[50], substr[50];
	
	
	//input
	cout << "Enter the main string:\n";
	cin >> mainstr;	
	cout << "Enter the substring:\n";
	cin >> substr;
	
	
	//finds array length
	for (x=0;mainstr[x]!='\0';x++)
	lmainstr++;
	
	for (y=0;substr[y]!='\0';y++)
	lsubstr++;
	
	
	//main algorithm
	while(i<lsubstr)
	{
		while (j<lmainstr&&endflag!=1)
		{
			if (substr[i]==mainstr[j])
			{
				flagb++;
				j=i+1;
				break;
			}
			else if (flagb==lsubstr)
			{
				endflag=1;
			}
			else
				j++;
		}
		if (endflag==1)
			break;
		else
			i++;
	}
	

	//output
	if(flagb==lsubstr)
	{
		cout << "Substring found!\n";
	}
	else 
	{
		cout << "Substring could no be found.\n";
	}
	
	return 0;
}
