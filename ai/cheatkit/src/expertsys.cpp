#include<stdio.h>
#include<conio.h>
#include<iostream.h>
using namespace std;

void symt1()
{
     int i;
     cout<<"\n# POSSIBLE CAUSES :\n\t-Loose alternator drive belt.\n\t-Defective regulator.\n\t-Loose or defective wiring.";
     cout<<"\n\n# SOLUTION :\n\t-Check drive belt tension. Inspect belt forcracking or glazing.\n\tReplace belt if required.";
     cout<<"\n\t-Alternators with external regulators-replace regulator.\n\tAlternators with internal regulators-replace alternators.";
     cout<<"\n\t-Check connectors to all wires attached to alternator and battery, \n\tincluding all plastic connectors for good contact";
     cout<<"\n";
     for (i=0;i<40;i++)
        cout<<"..";
     cout<<"\n\nPress any key to continue . . . . .";
     getch();
}

void symt2()
{
     int i;
     cout<<"\n# POSSIBLE CAUSES :\n\t-Loose or worn drive belt.\n\t-Loose or defective wiring.\n\t-Defective battery.\n\t-Loose or corroded battery cables and connectors.\n\t-Defective fusible link(s).";
     cout<<"\n\n# SOLUTION :\n\t-Check drive belt tension. Inspect belt forcracking or glazing.\n\tReplace belt if required.";
     cout<<"\n\t-Check connectors to all wires attached to alternator and battery,\n\t including all plastic connectors for good contact";
     cout<<"\n\t-Replace battery, if fails load test";
     cout<<"\n\t-Check all cables and connectors for tightness.\n\tMake sure if they are free of rust and corrosion";
     cout<<"\n\t-Replace fusible link(s).";
     cout<<"\n";
     for (i=0;i<40;i++)
        cout<<"..";
     cout<<"\n\nPress any key to continue . . . . .";
     getch();
}

void symt3()
{
     cout<<"\n# POSSIBLE CAUSES :\n\t-Loose or worn drive belt.\n\t-Bad bearing inside alternator.\n\t-Loose mounting bolts.";
     cout<<"\n\n# SOLUTION :\n\t-Check drive belt tension. Inspect belt forcracking or glazing.\n\tReplace belt if required.";
     cout<<"\n\t-Replace alternators.";
     cout<<"\n\t-Tighten all mounting bolts.";
     cout<<"\n";
     for (int i=0;i<40;i++)
        cout<<"..";
     cout<<"\n\nPress any key to continue . . . . .";
     getch();
}

void symt4()
{
     cout<<"\n# POSSIBLE CAUSES :\n\t-Loose alternator drive belt.\n\t-Defective battery.\n\t-Defective regulator.";
     cout<<"\n\n# SOLUTION :\n\t-Check drive belt tension. Inspect belt forcracking or glazing.\n\tReplace belt if required.";
     cout<<"\n\t-Replace battery if fails load test.";
     cout<<"\n\t-Alternators with external regulators-replace regulator.\n\tAlternators with internal regulators-replace alternators.";
     cout<<"\n";
     for (int i=0;i<40;i++)
        cout<<"..";
     cout<<"\n\nPress any key to continue . . . . .";
     getch();
}

void symt5()
{
     cout<<"\n# POSSIBLE CAUSES :\n\t-Defective regulator.\n\t-Battery overcharging.";
     cout<<"\n\n# SOLUTION :\n\t-Alternators with external regulators-replace regulator.\n\tAlternators with internal regulators-replace alternators.";
     cout<<"\n\t-Check battery posts, cables and connections.\n\tReplace battery if condition persists.";       
     cout<<"\n";
     for (int i=0;i<40;i++)
        cout<<"..";
     cout<<"\n\nPress any key to continue . . . . .";
     getch();
}

void symt6()
{
     cout<<"\n# POSSIBLE CAUSES :\n\t-Defective wiring or electrical components-Stereo,Amplifires,Phones etc\n\t-Defective regulator.\n\t-Defective fusible link(s).";
     cout<<"\n\n# SOLUTION :\n\t-Check wirings for burnt fusible link(s), misrouting or breaks.";
     cout<<"\n\t-Alternators with external regulators-replace regulator.\n\tAlternators with internal regulators-replace alternators.";
     cout<<"\n\t-Replace fusible link(s).";
     cout<<"\n";
     for (int i=0;i<40;i++)
        cout<<"..";
     cout<<"\n\nPress any key to continue . . . . .";
     getch();
}

int main()
{   int choice,i;
    cout<<"\tWELCOME TO AUTOMOBILE (MOTOR CAR) EXPERT SYSTEM\n";
    cout<<"\t````````````````````````````````````````````````\n";
    do
    {
    cout<<"\n\t";
    for (i=0;i<40;i++)
        cout<<"-";
    cout<<"\n\t|\t\t........\n\t|\t\t| MENU |\n\t|\t\t........\n\t|\n";
    cout<<"\t|Enter the symptoms. PRESS\n\t|  1.Dash warning lamp stays on or flashes erratically.";
    cout<<"\n\t|  2.Battery does not stay charged.\n\t|  3.Alternator makes accessive noise.";
    cout<<"\n\t|  4.Voltage gauge shows discharge.\n\t|  5.Battery requires water frequently.";
    cout<<"\n\t|  6.Lights or fuses burn out frequently.\n\t|  7.Quit\n\t|";
    cout<<"\n\t|\n\t|ENTER YOUR CHOICE------->";
    cin>>choice;
    cout<<"\n";
    for (i=0;i<40;i++)
        cout<<"..";
    
    switch (choice)
    {      case 1:symt1();
           break;
           case 2:symt2();
           break;
           case 3:symt3();
           break;
           case 4:symt4();
           break;
           case 5:symt5();
           break;
           case 6:symt6();
           break; 
           case 7:cout<<"\n\n\tTHANK YOU FOR USING EXPERT SYSTEM\n";break;     
           default:cout<<"\nINVALID ENTRY. Please TRY again.\n";break;
    }
    }while(choice!=7);
    getch();
}
