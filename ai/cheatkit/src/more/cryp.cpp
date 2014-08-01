#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<conio.h>

char *a,*b,*c;
int notused[11],oper,length;

int getunique(char str1[],char str2[],char str3[],char arr[])
{
	int k,flags[26];
	for(int i=0;i<26;i++)
		flags[i]=0;
	for(i=0;str1[i];i++)
		flags[str1[i]-'a']=1;
	for(i=0;str2[i];i++)
		flags[str2[i]-'a']=1;
	for(i=0;str3[i];i++)
		flags[str3[i]-'a']=1;
	for(i=k=0;i<26;i++)
		if(flags[i])
			arr[k++]=i+'a';
	arr[k]='\0';
	return k;
}

void assign(char letters[],int values[],int index)
{
	int i,done;
	long int num1,num2,num3;
	if(index==length)
	{
		if(values[a[0]-'a'] && values[b[0]-'a'] && values[c[0]-'a'])
		{
			for(num1=i=0;a[i];i++)
				num1=num1*10 + values[a[i]-'a'];
			for(num2=i=0;b[i];i++)
				num2=num2*10 + values[b[i]-'a'];
			for(num3=i=0;c[i];i++)
				num3=num3*10 + values[c[i]-'a'];
			done=0;
			if((num1+num2)==num3)
				done=1;

			if(done)
			{

				cout<<"\n"<<a<<"\t="<<num1<<"\n"<<b<<"\t="<<num2<<"\n"<<c<<"\t="<<num3;
			}
		}
		return;
	}
	for(i=0;i<10;++i)
		if(notused[i])
		{
			values[letters[index]-'a']=i;
			notused[i]=0;
			assign(letters,values,index+1);
			notused[i]=1;
		}
}

void perform_op(char str1[],char str2[],char str3[],int op)
{
	char letters[12];
	int values[26];

	length=getunique(str1,str2,str3,letters);
	a=str1,b=str2,c=str3,oper=op;
	for(int i=0;i<10;i++)
		notused[i]=1;

	assign(letters,values,0);
}

int main()
{
	char str1[10],str2[10],str3[10];
	int op;
	clrscr();
	cout<<"Enter string1:";
	cin>>str1;
	cout<<"\nEnter string2:";
	cin>>str2;
	cout<<"\nEnter string3:";
	cin>>str3;
	op=1;

	perform_op(str1,str2,str3,op);
	getch();
	return 0;
}
