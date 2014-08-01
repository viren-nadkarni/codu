class FibonacciSeries
{
	public static void main(String args[])
	{
		int number = 13;
		
		Fib f = new Fib(number);
		
		f.series();
	}
}

class Fib
{
	int num;

	Fib(int tmp)
	{
		num = tmp;
	}

	void series()
	{
		int i;
		
		for(i = 0; i < num; ++i)
			System.out.print( val(i) + " ");	
	}
	
	int val(int g)
	{
		if( g == 0 || g == 1)
			return 1;
		else 
			return val(g - 1) + val( g - 2 );
	}
}
