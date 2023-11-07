#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &v1)
{
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
        cout<<v1.at(i)<< "  ";
    }
}

int main()
{
    vector<int> v1;
    int element=0;
    for(int i=0;i<4;i++)
    {
        cout<<"Enter  Vector  ";
        cin>>element;
        v1.push_back(element);
    }
    display(v1);
}