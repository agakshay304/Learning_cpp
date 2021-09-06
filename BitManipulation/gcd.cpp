#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    

    while(b!=0)                         //Theory: Whenever we take out the remainder 
    {                                       //of two number ,the remainder has same gcd
        int rem=a%b;                        //as of the two no.
                                            //24%18=6     
        a=b;                                //18%6=0
        b=rem;                              //6%0=0
    }                                                                  
    return a;
}

int main()
{
    int a,b;
    cout<<"Enter Numbers to find GCD :";
    cin>>a>>b;

    cout<<gcd(a,b);
}