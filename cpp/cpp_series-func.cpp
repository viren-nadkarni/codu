//Prints the series
//	f(n) = (f(n-1)*f(n-2)) + 1
//	f(0)=1
//	f(1)=1
//makes use of functions
#include <iostream>

using namespace std;

void nextt(int *, int *series);

int main()
{
	int terms, i, series[11];
	int *i_ptr;
	
	series[0]=1;
	series[1]=1;
	
	cout << "Enter the number of terms (max. 10): ";
	cin >> terms;
	
	i_ptr=&i;
	
	while(i<terms)
		nextt(i_ptr,series);		

	for(int j=0; j<terms ;++j)
		cout << series[j] << "  ";
	cout << endl;
	
	return 0;
}

void nextt(int *i_ptr, int series[])
{
	if (*i_ptr>1)
	{
		series[*i_ptr]= (series[*i_ptr-1] * series[*i_ptr-2]) + 1;
	}
		
	*i_ptr=*i_ptr+1;
		
}
