//lexical analysis using if-else
#include<iostream>
#include<string>

using namespace std;

#define IGNORESPACE for(;stat[i]==' ';++i) {}

int main()
{
	char stat[30];
	int i=0;
	bool correct=false, forstat=false, whilestat=false;

	cout << "Enter a statment to analyze: \n";
	gets_s(stat);
	
	IGNORESPACE
	
	if(stat[i]=='f')//for for statments
	{
		forstat=true;
		++i;
		if(stat[i]=='o')
		{
			++i;
			if(stat[i]=='r')
			{
				++i;
				IGNORESPACE
				if(stat[i]=='(')
				{
					++i;
					IGNORESPACE
					if((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123))//identifier first character
					{
						while((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123) || (stat[i]>47&&stat[i]<58))//identifier subsequent characters
							++i;
						if(stat[i]=='=')
						{
							++i;
							IGNORESPACE
							while(stat[i]>47 && stat[i]<58)//numerical values
								++i;
							IGNORESPACE
							if(stat[i]==';')//semicolon 1 check
							{
								++i;
								IGNORESPACE
								if((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123))//identifier first character
								{
									while((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123) || (stat[i]>47&&stat[i]<58))//identifier subsequent characters
										++i;
									IGNORESPACE
									if((stat[i]=='='&&stat[i+1]=='=') || stat[i]=='<' || stat[i]=='>')//logical operator check
									{
										if(stat[i+1]=='=')//if == or <= or >=
											i+=2;
										else
											++i;
										IGNORESPACE
										while((stat[i]>47&&stat[i]<58) || (stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123))//alpha numerical values
											++i;
										IGNORESPACE
										if(stat[i]==';')//semicolon 2 check
										{
											++i;
											IGNORESPACE
											if((stat[i]=='+'&&stat[i+1]=='+') || (stat[i]=='-'&&stat[i+1]=='-'))//pre incrementation
											{
												i+=2;
												if((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123))//identifier first character
												{
													while((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123) || (stat[i]>47&&stat[i]<58))//identifier subsequent characters
														++i;
													IGNORESPACE
													if(stat[i]==')')
														correct=true;
													else
														cout<<"\nError with closing bracket\n";
												}	
												else
													cout << "\nError with identifier/incrementation/decrementation\n";
											}
											else if((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123))//post incrementation
											{
												while((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123) || (stat[i]>47&&stat[i]<58))//identifier subsequent characters
													++i;
												if((stat[i]=='+'&&stat[i+1]=='+') || (stat[i]=='-'&&stat[i+1]=='-'))
													i+=2;
												else
													cout << "\nError with incrementation/decrementation\n";
												IGNORESPACE
												if(stat[i]==')')
													correct=true;
												else
													cout<<"\nError with closing bracket\n";
											}
											else
												cout<<"\nImproper incrementation/decrementation\n";
										}
										else
											cout<<"\nImproper use of semicolon 2\n";
									}
									else
										cout<<"\nImproper logic operation\n";
								}
								else
									cout<<"\nImproper identifier for comparison\n";
							}
							else
								cout<<"\nImproper use of semicolon 1\n";
						}
						else
							cout<<"\nImproper assignment\n";
					}
					else
						cout<<"\nImproper identifier for assignment\n";
				}
				else
					cout<<"\nError with opening bracket\n";
			}
			else
				cout<<"\nError with for statment\n";
		}
		else
			cout<<"\nError with for statment\n";
	}
	else if(forstat)
		cout<<"\nError with for statment\n";
	

	if(stat[i]=='w')//for while statments
	{
		whilestat=true;
		++i;
		if(stat[i]=='h')
		{
			++i;
			if(stat[i]=='i')
			{
				++i;
				if(stat[i]=='l')
				{
					++i;
					if(stat[i]=='e')
					{
						++i;
						IGNORESPACE
						if(stat[i]=='(')
						{
							++i;
							IGNORESPACE
							if((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123))
							{
								++i;
								while((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123) || (stat[i]>47&&stat[i]<58))
									++i;
								IGNORESPACE
								if((stat[i]>59&&stat[i]<63))
								{
									++i;
									IGNORESPACE
									while((stat[i]>64&&stat[i]<91) || (stat[i]>96&&stat[i]<123) || (stat[i]>47&&stat[i]<58))
										++i;
									IGNORESPACE
									if(stat[i]==')')
										correct=true;
									else
										cout << "\nError with the closing bracket\n";
								}
								else
									cout << "\nImproper logic operator\n";
							}
							else
								cout << "\nImproper keyword\n";
						}
						else
							cout << "\nError with the opening bracket\n";
					}
					else
						cout << "\nError with while statment\n";
				}
				else
					cout << "\nError with while statment\n";
			}
			else
				cout << "\nError with while statment\n";
		}
		else
			cout << "\nError with while statment\n";
	}
	else if(whilestat)
		cout << "\nError with while statment\n";
			
	if(correct)
		cout<<"\nEntered statement is correct\n";
	cin.get();
	return 0;
}