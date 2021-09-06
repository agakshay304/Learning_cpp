#include <iostream>
#include <string>
using namespace std;


void towerofhanoi(int n,char src,char des,char help)
{

    if(n==0)
    {
        return;
    }
    towerofhanoi(n-1,src,help,des);
    cout<<"Move From "<<src<<"To"<<des<<endl;
    towerofhanoi(n-1,help,des,src);
}



int main()
{
    towerofhanoi(3,'A','C','B');
}
