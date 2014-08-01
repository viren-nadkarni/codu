import java.lang.Math;
import java.util.Scanner;

class MathDemo
{
	public static void main(String args[])
	{
		int i;
		
		Scanner s = new Scanner(System.in);
		
		i = s.nextInt();
		
		for(; i < 10; ++i)
		{
			System.out.println("Square root of " + (i + 1) + " is " + Math.sqrt(i+1) );
		}
		
	}
}
