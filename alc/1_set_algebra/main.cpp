#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

using namespace std;

class Set
{	
public:
	int * list, size;
	Set()
	{
		size=0;
		list=NULL;
	}
	Set(int x)
	{
		list=new int[x];
		size=x;
	}
	
	bool isPresent(int x)
	{
		for(int i=0;i<size;++i)
			if(x==list[i])
				return true;
		
		return false;
	}
	
	void clear()
	{
		size=0;
		delete list;
		list=NULL;
	}
	
	void clean()
	{
		for(int i=0;i<size;++i)
		{
			for(int j=i+1;j<size;++j)
			{
				if(list[i]==list[j])
				{	
					for(int k=j;k<size-1;k++)
						list[k]=list[k+1];
					size--;
				}
			}
		}
	}
	
	void insert(int x)
	{
		if(list==NULL)
			list=new int[32];
		list[size++]=x;
	}
	
	void operator=(Set a)
	{
		if(list!=NULL)
		{
			delete list;
			list=NULL;
		}
		
		list=new int[a.size];
		size=a.size;
		
		for(int i=0;i<size;++i)
			list[i]=a.list[i];
	}
};

/*
 *
 *
 *
 *
 *
 */


Set set_complement(Set *, int &);
Set set_intersect(Set *,int &);
Set set_union(Set *,int &);
Set set_differ(Set &, Set &);

Set set_complement(Set setlist[], int &totalsets)
{
	Set univ, result;
	
	univ=set_union(setlist,totalsets);
	
	for(int i=0;i<univ.size;i++)
	{
		if(!setlist[0].isPresent(univ.list[i]))
		{
			result.insert(univ.list[i]);		
		}
	}
	
	result.clean();
	return result;
}

Set set_differ(Set &a, Set &b)
{
	Set result;
	
	for(int i=0;i<a.size;++i)
		if(!b.isPresent(a.list[i]))
			result.insert(a.list[i]);
		
	result.clean();
	return result;
}

Set set_union(Set setlist[],int &totalsets)
{
	Set result;
	bool flag=false;
	
	for(int i=0;i<totalsets;i+=2)
	{
		for(int m=0;m<setlist[i].size;++m)
		{
			for(int n=0;n<setlist[i+1].size;++n)
			{
				if(setlist[i].list[m]==setlist[i+1].list[n])
				{
					flag=true;
					break;
				}
			}
			if (!flag)
				result.insert(setlist[i].list[m]);
			flag=false;
		}
		for(int o=0;o<setlist[i+1].size;++o)
			result.insert(setlist[i+1].list[o]);
	}
	result.clean();
	return result;
}

Set set_intersect(Set setlist[],int &totalsets)
{
	Set a,tmp;
	bool flag=false;
	
	a=setlist[0];
	
	for(int i=1;i<totalsets;i++)
	{
		tmp.clear();
		for(int m=0;m<a.size;m++)
		{
			for(int n=0;n<setlist[i].size;n++)
			{
				if(a.list[m]==setlist[i].list[n])
				{
					flag=true;
					break;
				}
			}
			if(flag)
				tmp.insert(a.list[m]);
			flag=false;
		}
		a=tmp;
	}
	a.clean();
	return a;
}


/*
 *
 *
 *
 *
 *
 */

void writeFile(Set &, string &);
int readFile(Set *,int &,char *);

void writeFile(Set &a, string &func)
{
	ofstream writeObj(OUTPUT_FILE,ios::app);
	
	if(writeObj==NULL)
	{
		cout << "\nCouldn't write the file";
		exit(1);
	}
	
	writeObj << endl << func << "={";
	
	for(int i=0;i<a.size;++i)
	{
		writeObj << a.list[i] << " ";
	}
	writeObj << "}";
	writeObj.close();
}

int readFile(Set setlist[],int &currentset,char setname[])
{
	ifstream readObj(INPUT_FILE);
	
	int opsum=0,array[32],count=0,sn=0;
	char ch='0';
	
	if(readObj==NULL)
	{
		cout << "\nCouldn't read the file";
		exit(1);
	}
	
	while(readObj.eof()==false)
	{
		ch=readObj.get();
		
		switch(ch)
		{
			case 'v':
				opsum+=1;
				break;
			case '^':
				opsum+=2;
				break;
			case '-':
				opsum+=4;
				break;
			case '!':
				opsum+=8;
				break;
			default:
				break;
		}
		
		if(ch=='\n')
		{
			setlist[currentset].list=new int[count];
			setlist[currentset].size=count;
			
			for(int i=0;i<count;++i)
			setlist[currentset].list[i]=array[i];
			
			if(count!=0)
				currentset++;
			
			count=0;
			
			continue;
		}
		
		if(ch>='A' && ch<='Z')
			setname[sn++]=ch;
		setname[sn]='\0';
		
		if(ch>='0' && ch<='9' )
			array[count++]=atoi(&ch);
	}
	
	// for(int k=0;k<currentset;++k)
	// {
		// for(int l=0;l<setlist[k].size;++l)
		// {
			// cout << setlist[k].list[l] << " ";
		// }
		// cout << endl;
	// }
	
	
	return opsum;
}

void writeFile(Set &result, char ch, char setname[])
{
	ofstream writeObj(OUTPUT_FILE,ios::app);
	int i=1;
	
	if(writeObj==NULL)
	{
		cout << "\nCouldn't write the file";
		exit(1);
	}
	
	writeObj << endl;
	
	switch(ch)
	{
		case 'v':
			writeObj << setname[0];
			while(setname[i]!='\0')
				writeObj << ch << setname[i++];
			break;
		case '^':
			writeObj << setname[0];
			while(setname[i]!='\0')
				writeObj << ch << setname[i++];
			break;
		case '-':
			writeObj << setname[0] << ch << setname[1];
			break;
		case '!':
			writeObj << ch << setname[0];
			break;
	}
	
	writeObj << "={";
	
	for(int j=0;j<result.size;++j)
	{
		writeObj << result.list[j];
		if(j+1!=result.size)
			writeObj << ",";
	}
	
	i=writeObj.tellp();
	writeObj.seekp(i-2);
	writeObj << "}";
	
}


/*
 *
 *
 *
 *
 */
 
int main(int argc, char * argv[])
{
	Set setlist[16], result(32);
	int opcode=0,totalsets=0;
	char setname[16];
	ofstream outfile;
	
	opcode=readFile(setlist,totalsets,setname);
	
	if(opcode>=8)
	{
		//complement with union of all sets as universal set
		result=set_complement(setlist,totalsets);
		writeFile(result,'!',setname);	
				
		opcode-=8;
	}
	
	if(opcode>=4 && totalsets>1)
	{
		//difference between first two sets
		result.clear();
		result=set_differ(setlist[0],setlist[1]);
		writeFile(result,'-',setname);
		
/*		cout << "\ndifference:";
		for(int k=0;k<result.size;++k)
			cout << result.list[k] << " ";		
*/	
		opcode-=4;
	}
	
	if(opcode>=2)
	{
		//intersection of all sets
		result.clear();
		result=set_intersect(setlist,totalsets);
		writeFile(result,'^',setname);
		
/*		cout << "\nintersection:";
		for(int i=0;i<result.size;++i)
			cout << result.list[i] << " ";		
*/		
		opcode-=2;
	}
	
	if(opcode==1)
	{
		//union of all sets
		result.clear();		
		result=set_union(setlist,totalsets);
		writeFile(result,'v',setname);
		
/*		cout << "\nunion: ";
		for(int i=0;i<result.size;++i)
			cout << result.list[i] << " ";
*/
	}
	
	outfile.open(OUTPUT_FILE,ios::app);
	outfile << endl << "_____________________\n";
	outfile.close();
	return 0;
}
