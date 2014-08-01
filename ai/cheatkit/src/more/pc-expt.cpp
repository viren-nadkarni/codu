#include<iostream.h>
#include<conio.h>

 char ch;

 void RR(){ cout<<"SOLUTION: REPLACE RAM WITH TYPE LISTED IN MOTHERBOARD DOCUMENTATION"; }

 void bs()
   {
    cout<<"Does it runs on bench? : "; cin>>ch;
    clrscr();gotoxy(10,18);
      if(ch=='y')
	cout<<"SOLUTION: LOCATE SHORT OR SWAP CASE";
      else
	{
	 cout<<"Does CPU swap work? : "; cin>>ch;
	 clrscr();gotoxy(10,18);
	   if(ch=='y')
	     cout<<"SOLUTION: BAD CPU, CHECK VOLTAGE & HEATSINK ON REPLACEMENT";
	   else
	     cout<<"SOLUTION: BAD MOTHERBOARD";
	}
   }

 void main()
   {
    clrscr();

    gotoxy(10,18);     //35,25
    cout<<"Expert system for Troubleshooting the Motherboard";
    gotoxy(10,22);
    cout<<"Answer the following Questions with Yes(y) or No(n)";
    getch();
    clrscr();gotoxy(10,18);
    cout<<"Do you get Live Screen? : "; cin>>ch;
    clrscr();gotoxy(10,18);
      if(ch=='y')
	{
	 cout<<"Does it freeze on Boot Screen? : "; cin>>ch;
	 clrscr();gotoxy(10,18);
	   if(ch=='y')
	     {
	      cout<<"Does it freeze on Bare Bones? : "; cin>>ch;
	      clrscr();gotoxy(10,18);
		if(ch=='y')
		  {
		   cout<<"Does it freeze on Swapped RAM? : "; cin>>ch;
		   clrscr();gotoxy(10,18);
		     if(ch=='y')
		       {
			cout<<"Is CMOS setting default? : "; cin>>ch;
			clrscr();gotoxy(10,18);
			  if(ch=='y')
			    {
			     cout<<"Is Heatsink active? : "; cin>>ch;
			     clrscr();gotoxy(10,18);
			       if(ch=='y')
				 bs();
			       else
				 cout<<"\nSOLUTION: INSTALL NEW HEATSINK & CONNECT FAN";
			    }
			  else
			    cout<<"\nSOLUTION: LOAD DEFAULT FROM BIOS";
		       }
		     else
		       RR();
		  }
		else
		  cout<<"SOLUTION: PROCEED TO CONFLICT RESOLUTION CHART";
	     }
	   else
	     cout<<"SOLUTION: PROCEED TO MOTHERBOARD RESOLUTION CHART";
	}
      else
	{
	 cout<<"Is Power diagnostic done? : "; cin>>ch;
	 clrscr();gotoxy(10,18);
	   if(ch=='y')
	     {
	      cout<<"Is Video diagnostic done? : "; cin>>ch;
	      clrscr();gotoxy(10,18);
		if(ch=='y')
		  {
		   cout<<"Is RAM matched properly seated? : "; cin>>ch;
		   clrscr();gotoxy(10,18);
		     if(ch=='y')
		       {
			cout<<"Is CPU seated flat? : "; cin>>ch;
			clrscr();gotoxy(10,18);
			  if(ch=='y')
			    {
			     cout<<"Is the fan on heatsink active? : "; cin>>ch;
			     clrscr();gotoxy(10,18);
			       if(ch=='y')
				 {
				  cout<<"Do you hear beeps? : "; cin>>ch;
				  clrscr();gotoxy(10,18);
				    if(ch=='y')
				      RR();
				    else
				      {
				       cout<<"Is it default Motherboard setting? : "; cin>>ch;
				       clrscr();gotoxy(10,18);
					 if(ch=='y')
					   bs();
					 else
					   cout<<"SOLUTION: RESTORE DEFAULT MOTHERBOARD SETTINGS WITH JUMPER OR SWITCHES";
				      }
				 }
			       else
				 cout<<"SOLUTION: CHEAK FAN POWER POINT";
			    }
			  else
			    cout<<"SOLUTION: RESEAT CPU & HEATSINK";
		       }
		     else
		       cout<<"SOLUTION: RESEAT RAM INSTALL PAIRS IF REQUIRED";
		  }
		else
		  cout<<"SOLUTION: PROCEED TO VIDEO FAILURE DIAGNOTIC CHART";
	     }
	   else
	     cout<<"SOLUTION: PROCEED TO POWER SUPPLY FAILURE";
	}
   getch();
  }