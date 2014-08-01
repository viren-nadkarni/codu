//Prints the series
//	f(n) = (f(n-1)*f(n-2)) + 1
//	f(0)=1
//	f(1)=1
//makes use of recursive functions
#include <iostream>

using namespace std;

void nextt(int *, int *, int *);

int main()
{
	int terms, i=0, series[11], a;
	int *i_ptr, *terms_ptr;
	
	series[0]=1;
	series[1]=1;
	
	cout << "Enter the number of terms (max. 10): ";
	cin >> terms;
	
	i_ptr=&i;
	terms_ptr=&terms;
	
	nextt(i_ptr,terms_ptr,series);		
	
	for(int j=0; j<terms ;++j)
		cout << series[j] << "  ";

	cout << endl;
	
	return 0;
}

void nextt(int *i_ptr, int *terms_ptr, int series[])
{
	if (*i_ptr>1)
		series[*i_ptr]= (series[*i_ptr-1] * series[*i_ptr-2]) + 1;
		
	if(*i_ptr!=*terms_ptr)
	{
		*i_ptr=*i_ptr+1;
		nextt(i_ptr,terms_ptr,series);
	}	
}
