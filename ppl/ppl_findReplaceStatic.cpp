//find and replace - static
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int ltext, lsearch, lreplace, i, flags=0;
	char text[]="The quick brown fox jumped over the lazy dog", search[]="quick", replace[]="slow";
	
	cout << "Original string: " << text << endl;
	cout << "Searching for: " << search << endl;
	cout << "Replacing with: " << replace << endl << endl;
		
	ltext=strlen(text);
	lreplace=strlen(replace);
	lsearch=strlen(search);
	
	for(i=0;i<=ltext;i++)
	{
		if(text[i]==search[0] && text[i+1]==search[1] && text[i+2]==search[2] && text[i+3]==search[3] && text[i+4]==search[4])
		{
			text[i]=replace[0];
			text[i+1]=replace[1];
			text[i+2]=replace[2];
			text[i+3]=replace[3];
			text[i+4]='*';
			break;
		}
		else if(flags==1)
		{
			cout << "Cannot find \"" << search << "\" in the string \"" << text << "\"\n";
		}
	}
	
	ltext=strlen(text);
	
	cout << "Modified string:\n";
	for (i=0;i<=ltext;i++)
	{
		if (text[i]!='*')
			cout << text[i];
		else
			continue;
	}

	cout << endl;

	return 0;
}