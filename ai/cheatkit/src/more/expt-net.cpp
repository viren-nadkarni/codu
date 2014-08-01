//to develop an expert system to analyse internet related problems
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>
#include<graphics.h>

void description(char *);
void solution(char *);

void descriptionis(char * first,char * second,char * problem)
{
if((stricmp(first,problem))==0)
printf("%s",second);
}


void solutionis(char * first,char * second,char * problem)
{
if((stricmp(first,problem))==0)
printf("%s",second);
}



void problemis(char * first,char * problem)
{
if((strcmp(first,problem))==0)
{
printf("\nDescription:-\n");
description(problem);
printf("\n\n\n\n\n\n\t\t\tPress Enter");
getch();
clrscr();
printf("\n\t\t\tINTERNET RELATED PROBLEMS");
printf("\nSolution:-\n");
solution(problem);
printf("\n\t\t\tPress Enter");
getch();
}
}

void solution(char * problem)
{
solutionis("IE not opening","1.Reinstall IE\na) Log onto the PC as Administrator\nb) Click | Start | Run |\nc) In the Open box, type REGEDIT and then click <OK>.\n**Note**\nTo reinstall only the Internet Explorer 6 browser component on Windows XP SP1, use the registry key below.\nPlease note that this only works on Windows XP SP1, Windows XP SP2 will crash if this is used.\n**End of Note**",problem);
solutionis("IE not opening","\n2.Modify the registry key:\na) Locate the appropriate registry subkey:\nHKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\ActiveSetup\InstalledComponents\{89820200-ECBD-11cf-8B85-00AA005B4383}\nb) Right-click the Installed (REG_DWORD) value\nc) Click <Modify>.\nd) Change the value data from 1 to 0 and then click <OK>. ",problem);
solutionis("IE not opening","\n3.Quit Registry Editor and then install Internet Explorer 6.",problem);
solutionis("autocomplete","Steps to turn off the autocomplete in IE\n1.  Click on | Tools | Internet Options | Content |\n2. Select Autocomplete\n3. Remove the tick from relevant tick boxes",problem);
solutionis("blank/transparent window","1.Repair Internet Explorer:\na) Click | Start | and then select | Run |\nb) Type MSINFO32 in the 'Open' command line and press <Enter> or click <OK>.\nc) Click | Tools | and from the menu select 'Internet Explorer Repair Tool'.\nd) From the next menu select the repair option.\n\n*Note**\nThe above option may only be available on older versions of IE and Windows\n**End of Note**",problem);
solutionis("blank/transparent window","\n2.a) Click | Start | Run |\nb) Type REGSVR32.ULMON.DLL in the Open command line and press <Enter> or click <Ok>\nc) You will be prompted if the command was successful.",problem);
solutionis("cannot access external","1. Check internet option settings:\na) Click | Tools | Internet options |\nb) Choose the Connections tab and click on LAN settings.\nc) Check that Automatically detect settings and Use automatic configuration script are selected or ticked.\nd) Check that the following line is entered in the Use Automatic Configuration Script:\n- http://www.uct.ac.za/cache.pac\n2. Refer to the Internet flowchart for troubleshooting:\na) See the attachment or\nb) Open it from G:\PCS\INFO\FLS FLOWCHARTS\n3. Should all of the above already be in place, then re-install TCP/IP\na) Click | Start | Control panel |\nb) Select the Network settings tab or icon.\nc) Delete the TCP/IP setting.\nd) Reboot PC.\ne) Re-install TCP/IP.\n**Note**\nFor detailed information on the TCP/IP stack for windows XP refer to the TCP/IP Reload nodes under | Windows Problems | Windows XP |\n**End of Note**",problem);
solutionis("cannot display page","1.Check if the user has a valid IP number by running WINIPCFG for Windows 98 or IPCONFIG for Windows XP.",problem);
solutionis("cannot download file","To resolve this problem,\n1. Clear the Temporary Internet files\na) Open Internet Explorer\nb) Click on | Tools | Internet Options | select the General Tab\nc) Under Temporary Internet files, click <Delete Files>\nd) In the Delete Files dialog box that appears, click <OK>.\n2. Clear the History\na) Under History, click <Clear History>\nb) In the dialog box that appears, click <OK>.\nc) Quit Internet Explorer.",problem);
solutionis("cannot download file","\n3. Delete the Internet Explorer INDEX.DAT file:\na) Log on to the computer by using the account of a user who does not experience the problem.\nb) Open a Command prompt box.\nc) Change the directory to the following path:\n- C:\Documents and Settings\username\Local Settings\Temporary Internet Files\Content.IE5\nd) Type DEL INDEX.DAT and then press <ENTER>\ne)  Close the Command prompt and then restart the computer.\n**Note**\nWhere username = the user account that has the problem.\n**End of Note**",problem);
solutionis("clear history files","1. Open Internet Explorer:\na) Click on | Tools | Internet options|\nb) Click on the <Clear History> button under the General tab.",problem);
solutionis("content advisor password","1. Open REGEDIT\na) Go to HKLM\Software\Microsoft\Windows\CurrentVersion\policies\ratings\nb) Delete the value called key\nc) Close REGEDIT\n2. Disable Content Advisor\na) Open the properties for IE\nb) Go to the Content Advisor\nc) Select Disable\nd) It will prompt for the password, Use the password: blank",problem);
solutionis("debug script errors","1.Open IE:\na) Click on | Tools | Internet Options |\nb) Click on the Advanced Tab on the top right-hand side of the new window.\nc) Under the Browsing section there is an option to Disable Script Debugging\nd) Make sure that it is ticked by clicking on it once.\ne) Click <OK>.\nf) Test IE now.",problem);
solutionis("default URL","1.Open Internet Explorer\na) Click on | Tools | Internet options |\nb) On the General tab - next to address type in your default web address or URL.\nc) Click <Apply>\nWhen the user clicks on a link that opens into a new window, nothing appears in that window.",problem);
solutionis("DNS error","1.a) Click | Start | Run |\nb) In the command line type WINIPCFG\nc) Click <OK>\nd) Release and then renew the IP number.",problem);
}

void description(char * problem)
{
descriptionis("IE not opening","On Windows XP\nWhen you try to open IE or any *.htm, *.html file  IE appears to open and then a IE save file dialog box opens asking you to save or open the file, while IE closes.",problem);
descriptionis("autocomplete","How to turn off the autocomplete",problem);
descriptionis("blank/transparent window","If you are receiving blank transparent windows, try these in order.",problem);
descriptionis("cannot access external","User cannot access external website.",problem);
descriptionis("cannot display page","User gets an error:\nThe page cannot be displayed.\nThe page you are looking for is currently unavailable etc.",problem);
descriptionis("cannot download file","You cannot use Internet Explorer to download files.\nHowever, you can download files from the Internet when using a different User Account.\nThis problem can occur if an Internet Explorer index file is damaged.",problem);
descriptionis("clear history files","How do you clear your history in IE",problem);
descriptionis("content advisor password","The content advisor is enabled and you cannot remember the password.",problem);
descriptionis("debug script errors","When opening certain websites or, in some cases, any website using IE the client gets an error asking whether you wish to debug the script that there was an error in.",problem);
descriptionis("default URL","How do you set IE to open on the same web page",problem);
descriptionis("DNS error","User gets an error - cannot find server DNS",problem);
}


void search_problem(char * problem)
{
problemis("IE not opening",problem);
problemis("autocomplete",problem);
problemis("blank/transparent window",problem);
problemis("cannot access external",problem);
problemis("cannot display page",problem);
problemis("cannot download file",problem);
problemis("clear history files",problem);
problemis("content advisor password",problem);
problemis("debug script errors",problem);
problemis("default URL",problem);
problemis("DNS error",problem);
}

void main()
{
char * problem,plist[20][50],slist[10][50];
int i,n,j,k,len,flag,option;
int choice,wish,ans;
char temp[50];
textmode(2);

//problems related to internet
strcpy(plist[0],"IE not opening");
strcpy(plist[1],"autocomplete");
strcpy(plist[2],"blank/transparent window");
strcpy(plist[3],"cannot access external");
strcpy(plist[4],"cannot display page");
strcpy(plist[5],"cannot download file");
strcpy(plist[6],"clear history files");
strcpy(plist[7],"content advisor password");
strcpy(plist[8],"debug script errors");
strcpy(plist[9],"default URL");
strcpy(plist[10],"DNS error");
fflush(stdin);

do
{
printf("\n\t\t\tINTERNET RELATED PROBLEMS");
printf("\n\n1.FIND A SOLUTION\n2.SEARCH");
printf("\n\nEnter Your choice:");
scanf("%d",&option);
printf("\n\n\n\n\n\n\n\n\n\n\t\tPress Enter");
getch();
clrscr();

if(option==1)
{
for(i=0;i<11;i++)
{
printf("\n\t\t\tINTERNET RELATED PROBLEMS");
printf("\n\n\nQ.%d)Is Your Problem : %s",i+1,plist[i]);
printf("\nYes(1) or No(0):");
scanf("%d",&ans);
for(k=0;k<10;k++)
printf("\n");
printf("\t\tPress Enter");
getch();
clrscr();
if(ans==0)
continue;
else
{
search_problem(plist[i]);
clrscr();
break;
}
}
}

if(option==2)
{
fflush(stdin);
strcpy(temp,"");
i=3;
do
{
problem=(char *)malloc(i*sizeof(int));
printf("\n\tINTERNET RELATED PROBLEMS-Type 'all' To View The Problems");
printf("\n\n\nEnter The Problem(Letter , Word or Sentence):-%s",temp);
scanf("%s",problem);
strcat(temp,problem);
printf("\n");
//searching for the possible problems
len=strlen(temp);
n=0;
for(k=0;k<11;k++)
{
flag=0;
for(j=0;j<len;j++)
{
if(temp[j]!=plist[k][j])
flag=1;
}
if(flag==0)
{
strcpy(slist[n],plist[k]);
n++;
}
}

if(n!=0)
{
printf("\nProblems Are:-");
}

else
{
if(strcmp(temp,"all")==0)
{
for(j=0;j<11;j++)
{
printf("\n%d)%s",j+1,plist[j]);
strcpy(slist[j],plist[j]);
}
}
else
{
printf("\n\nNo Matches Found");
printf("\n\n\t\t\tPress Enter");
getch();
clrscr();
break;
}
}

for(j=0;j<n;j++)
printf("\n%d)%s",j+1,slist[j]);

printf("\n\nEnter Your Choice , 0 For No Selection :-");
scanf("%d",&choice);
printf("\n\n\t\t\tPress Enter");
getch();
clrscr();
if(choice!=0)
{
strcpy(problem,slist[choice-1]);
break;
}
free(problem);
i++;
}while(1);//end of do
printf("\n\t\t\tINTERNET RELATED PROBLEMS");
printf("\n");
//searching for the problem
search_problem(problem);
clrscr();
}

printf("\n\t\t\tINTERNET RELATED PROBLEMS");
printf("\n\n\nDo you want to continue(1/0):");
scanf("%d",&wish);
printf("\n\n\n\n\n\t\t\tPress Enter");
getch();
clrscr();
}while(wish);
}