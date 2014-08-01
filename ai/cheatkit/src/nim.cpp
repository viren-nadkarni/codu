/*
This program plays a game of Nim with the user.
*/
#include<conio.h>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
 int size=10;

//check minimax no.
//rules
int checkmaxmin(int size)
{
     int compTakeOff;
    if(size==10)
    {
                compTakeOff=2;
             //   cout<<"\nSelect "<<compTakeOff;
    } 
    else if(size==9)
    {
         compTakeOff=2;
          //cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==8)
    {
         compTakeOff=2;
      //    cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==7)
    {
         compTakeOff=2;
        //  cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==6)
    {
         compTakeOff=2;
      //    cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==5)
    {
         compTakeOff=2;
        //  cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==4)
    {
         compTakeOff=1;
      //    cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==3)
    {
        compTakeOff=1; 
       //  cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==2)
    {
        compTakeOff=2; 
       //  cout<<"\nSelect "<<compTakeOff;
    }
    else if(size==1)
    {
         compTakeOff=1;
         // cout<<"\nSelect "<<compTakeOff;
         //
        
    }
     
     return compTakeOff;
     
}

void printprotons(int size)
{
 int i;
 printf("\n");
 for(i=0;i<size;i++)
 {
                    cout<<" @ ";    
     
     
     
}
}
int main()
{  
	int size, whoseTurn,  youTakeOff, mode;
	int flag=0;
	int countc=0;
	int  comptakeoff;
	
	
    
    /* introduce the game of Nim and display its rules */
	cout << "\t\t\t****** WELCOME TO THE GAME OF NIM ******\n";
	cout<<"\nTHERE ARE 10 PROTONS WITH US \n";
	cout << "THE NUMBER OF PROTONS YOU MUST DRAW BE 1 OR 2\n";
	cout << "THE PERSON WHO GETS THE LAST PROTONS WINS\n\n";
	cout<<"\n\n";

	//initialize the total protons
	     size=10;
    printprotons(size);
	
  /* determine who goes first and the initial number of marbles */
  cout<<"\n\nDo you want to play first or do you want the computer play first ? ";
  cout<<"\n1 - You want to play first\n";
  cout<<"\n0 - Computer should start the game\n";
  cout<<"\nPress as per your choice  :  \n";
  
  cin>>whoseTurn;

	if(whoseTurn==0)
		cout << "\nComputer plays first.\n";
	else
	    cout << "\nYou play first.\n";
	cout << "\nInitial number of marbles: 10" << endl;
	

    //initialise the turn
      mode = whoseTurn;


      /* deal with the case when computer plays first */	
	  if (mode==0)
       {
	    	         while (size>0)
                            {
		                    	if (whoseTurn==0)
                                    {
                                                 printprotons(size);
                                                 //check maxmin
                                                 comptakeoff = checkmaxmin(size);
                                                
		    	                                 size -= comptakeoff;
                                                 cout << "\n\nComputer takes off " << comptakeoff << " marble(s).\n";
                                                 cout << "\nCurrent number of marble(s): " << size <<"\n\n";
                              		}
		                        else 
                                     {
                                                 /* prompt user to enter a number */
			                                     	do
                                                      {   
                                                           flag=0;
                                                           printprotons(size);
					                                       cout << "\n\nEnter number of marble(s) to draw (1/2): ";
					                                       cin >> youTakeOff;
					                                       if(youTakeOff>=1 &&  youTakeOff<=2)
				                                    	    {
                                                                          flag=1;
                                                            }
                                                           else
                                                            {
                                                                           flag=0;
                                                             }
                                            	    } while(!flag);
	 	    	                                 size -= youTakeOff;
                                                 cout << "\nCurrent number of marble(s): " << size << "\n\n";
                                  }
			                      whoseTurn = whoseTurn==0 ? 1 : 0;
                         }   
    }
    else
     {
	                       while (size>0)
                             {
	   		                      if (whoseTurn==1)
                                  {
                                                   printprotons(size);
                                                   /* prompt user to enter a number */
			               	                       do 
                                                   {   
                                                             flag=0;
				                                             cout << "\n\nEnter number of marble(s) to draw (1/2): ";
					                                         cin >> youTakeOff;
					                                         if(youTakeOff>=1 &&  youTakeOff<=2)
					                                         {
                                                              flag=1;
                                                              }
                                                              else
                                                              {
                                                              flag=0;
                                                              }
                                                    } while(!flag);
	 	    	                                    size -= youTakeOff;
                                                    cout << "\nCurrent number of marble(s): " << size << "\n\n";
                                    }
                                  else
                                   {   
                                                         printprotons(size);
                              
		 	                                             comptakeoff = checkmaxmin(size);
                                                         size -= comptakeoff;
                                                         cout << "\n\nComputer takes off " << comptakeoff << " marble(s).\n";
                                                         cout << "\nCurrent number of marble(s): " << size <<"\n\n";
		                         	}
		                          whoseTurn = whoseTurn==0 ? 1 : 0;
                         }
	
    }
	if (whoseTurn == 1)
		cout << "The computer wins!" << endl;
	else
		cout << "You win!" << endl;
		
		scanf("sasdsad");
    	getch();
    	return 0;
}


