#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str="This String Has To Be Sorted";
    cout<<str<<endl;

    cout<<"Sorted String is: ";
    sort(str.begin(),str.end());

    cout<<str<<endl;
}