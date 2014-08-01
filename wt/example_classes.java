class ExampleClasses
{
	public static void main(String args[])
	{
		Book b1 = new Book("Java", "Balgurusamy", "Tata McGraw Hill");
		
		b1.printInfo();
		
	}
}

class Book
{
		String title = new String();
		String author = new String();
		String publisher = new String();
		
		void printInfo()
		{
			System.out.println(title);
			System.out.println("Written by  " + author);
			System.out.println("Published by  " + publisher);
		}
		
		Book(String t, String a, String p)
		{
			title = t;
			author = a;
			publisher = p;		
		}
}