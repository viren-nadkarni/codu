//unification algorithm
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
int m=0,n=0,set;
//checking whether string is a variable or constant
int isconstant(char * string)
{
int len,i,c;
len=strlen(string);
for(i=0;i<len;i++)
{
c=isupper(string[i]);
if(c==0)
return 0;
}
return 1;
}

int isvariable(char * string)
{
int len,i,c;
len=strlen(string);
for(i=0;i<len;i++)
{
c=islower(string[i]);
if(c==0)
return 0;
}
if(len==1)
return 1;

else
return 0;
}

//finds the number of arguments in a given predicate
int no_of_arguments(char * string)
{
int num=1,len,i;
char c;
len=strlen(string);
for(i=0;i<len;i++)
{
if(string[i]==',')
num++;
}
return num;
}

//checking whether to strings are identical
int isidentical(char * string1,char * string2)
{
int c;
c=strcmp(string1,string2);
if(c==0)
return 1;
else
return 0;
}

//checking whether initial symbol of predicates are same
int initial_symbol(char * l1,char * l2)
{
int len,i;
char c='.';
len=strlen(l1);
for(i=0;i<len;i++)
{
c=l1[i];
if(c=='(')
break;

if(l1[i]!=l2[i])
return 0;
}
return 1;
}


//unifies two predicates
char * unify(char l1[50],char l2[50])
{
int arg1,arg2;//no of arguments of the predicates
int v1,v2; //checking variables
int c1,c2; //checking constants
int id,init; //checking identical,predicate
int i,j,x,y,len,z,r,h;
char * ptr,c,variable;
char subst[30],s[30],temp[40],literal[30],remainder[30];
char a1[20],a2[20];//arguments

//checking whether variables
v1=isvariable(l1);
v2=isvariable(l2);

//checking whether constants
c1=isconstant(l1);
c2=isconstant(l2);

//step 1
//if both l1,l2 are variables or constants
if(((v1==1)&&(c2==1))||((v2==1)&&(c1==1))||((v1==1)&&(v2==1))||((c1==1)&&(c2==1)))
{
//if identical
id=isidentical(l1,l2);
if(id==1)
return "NIL";

/*
//if both are costants
if(c1==1&&c2==1)
return "NIL";
*/

//if l1 is variable and occurs in l2
else if(v1==1)
{
c=l1[0];
ptr=strchr(l2,c);
if(ptr)
return "FAIL";

else
{
for(i=0;i<strlen(l2);i++)
temp[i]=l2[i];
temp[i]='/';
for(x=0;x<strlen(l1);x++)
{
i++;
temp[i]=l1[x];
}
temp[++i]='\0';
return temp;
}
}

//if l2 is variable and occurs in ll
else if(v2==1)
{
c=l2[0];
ptr=strchr(l1,c);
if(ptr)
return "FAIL";

else
{
for(i=0;i<strlen(l1);i++)
temp[i]=l1[i];
temp[i]='/';
for(x=0;x<strlen(l2);x++)
{
i++;
temp[i]=l2[x];
}
temp[++i]='\0';
return temp;
}
}

else
return "FAIL";
}

//step 2
init=initial_symbol(l1,l2);
if(init==0)
return "FAIL";

//step 3
//finding the number of arguments in a predicates
arg1=no_of_arguments(l1);
arg2=no_of_arguments(l2);

if(arg1!=arg2)
return "FAIL";

//step 4
subst[0]='N';
subst[1]='I';
subst[2]='L';
subst[3]='\0';

//step 5
for(i=1;i<=arg1;i++)
{
if(i==1)
{
while(l1[n]!='(')
{
n++;
}
n++;

while(l2[m]!='(')
{
m++;
}
m++;
}

j=0;
while((l1[n]!=',')&&(l1[n]!=')'))
{
a1[j]=l1[n];
j++;
n++;
}
a1[j]='\0';
n++;

j=0;
while((l2[m]!=',')&&(l2[m]!=')'))
{
a2[j]=l2[m];
m++;
j++;
}
a2[j]='\0';
m++;

strcpy(s,unify(a1,a2));

if((strcmp(s,"FAIL"))==0)
return "FAIL";

if((strcmp(s,"NIL"))!=0)
{
printf("\n");
y=0;
while(s[y]!='/')
{
literal[y]=s[y];
y++;
}
literal[y]='\0';
y++;
variable=s[y];

//replacing the literal in first predicate
y=n;
len=strlen(literal);

while(y<strlen(l1))
{
if(l1[y]==variable) //when variable is encountered
{
set=y;
r=y+1;
h=0;
while(r<strlen(l1))
{
remainder[h]=l1[r];
r++;
h++;
}
remainder[h]='\0';
z=0;
while(z<len)
{
l1[y]=literal[z];
y++;
z++;
}

z=0;
while(z<strlen(remainder))
{
l1[y]=remainder[z];
y++;
z++;
}
l1[y]='\0';
y=set;
}
y++;
}//end if while

//replacing the literal in second predicate
y=m;
len=strlen(literal);

while(y<strlen(l2))
{
if(l2[y]==variable) //when variable is encountered
{
set=y;
r=y+1;
h=0;
while(r<strlen(l2))
{
remainder[h]=l2[r];
r++;
h++;
}
remainder[h]='\0';
z=0;
while(z<len)
{
l2[y]=literal[z];
y++;
z++;
}

z=0;
while(z<strlen(remainder))
{
l2[y]=remainder[z];
y++;
z++;
}
l2[y]='\0';
y=set;
}
y++;
}//end if while

strcat(s," | ");
strcat(s,subst);
strcpy(subst,s);
}
}
//step 6
return subst;
}

void main()
{
int wish;
char predicate1[50],predicate2[50];//predicates
char result[50];
clrscr();
textmode(2);
//Inputting the predicates
do
{
clrscr();
m=n=0;
cprintf("All Constants In Capital Letters , ");
cprintf("Variables Character In Lowercase");
printf("\n\nEnter Predicate 1:");
scanf("%s",predicate1);
printf("\nEnter Predicate 2:");
scanf("%s",predicate2);
//displaying the predicates
cprintf("\n\nThe Result Of Unification of predicates are:");
//unifying the two predicates
strcpy(result,unify(predicate1,predicate2));
printf("\n");
printf("\n%s",result);
printf("\n\nDo You Want To Continue(1/0):");
scanf("%d",&wish);
}while(wish);
getch();
}