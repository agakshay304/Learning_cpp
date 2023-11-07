#include <iostream>
using namespace std;
//Ques No of ways a tiles of 2*1 can be fitted on a floor of 2*n
//solution Same as Fibonacci 

int tilling(int n)
{
    if(n==0){
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    return tilling(n-1)+tilling(n-2);
        //first call stand for taking tiles vertically
        //second call stand for taking tiles horizonatally
}

int main()
{
    cout<<tilling(4);
}
