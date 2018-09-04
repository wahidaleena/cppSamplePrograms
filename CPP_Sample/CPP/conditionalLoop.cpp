#include<iostream>
#include<conio.h>

using namespace std;

int func1(void)
{
return 5;
}

int func2(void)
{
return 10;
}

int main()
{
     // Variable Declaration
     int counter, n, fact = 1;
     // Get Input Value
     cout<<"Enter the Number :";
     cin>>n;

     //for Loop Block
     for (int counter = 1; counter <= n; counter++)
     {
         fact = fact * counter;
     }

     for (int i=0;i<5;i++)
     {
     for (int j=0;j<5;i++)
     {
     cout << "Entered"<<end1;
     }
     }

     if(func1()>func2())
     {
     cout<<"Enter"<<end1;
     }

     if ( number > 0)
     {
         cout << "You entered a positive integer: " << number << endl;
     }
     else if (number < 0)
     {
        cout<<"You entered a negative integer: " << number << endl;
     }
     else
     {
        cout << "You entered 0." << endl;
     }

     string str;
     do {
     cout << "Enter text: ";
     getline (cin,str);
     cout << "You entered: " << str << '\n';
     } while (str != "goodbye");

     cout<<n<<" Factorial Value Is "<<fact;
     // Wait For Output Screen
     getch();
     return 0;
 }