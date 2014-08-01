class MultipleClasses
{
	public static void main(String args[])
	{
		Grammar g = new Grammar("English");
		g.a.contents = "123";
		
		g.a.printContents();
		
		g.printGrammar();
	}	
}

class Grammar
{
	String name = new String();
	Alphabet a = new Alphabet();
	
	Grammar(String n)
	{
		name = n;
	}
	
	void printGrammar()
	{
		System.out.println("Name: " + name);
		System.out.println("Alphabet: " + a.contents);
	}
}

class Alphabet
{
	String contents = new String();
		
	void printContents()
	{
		System.out.println(contents);
	}
}