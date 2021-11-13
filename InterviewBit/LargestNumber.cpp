#include <iostream>
#include <vector>
#include <string>
using namespace std;


int mycompare(string X,string Y)
{
    string XY=X.append(Y);

    string YX=Y.append(X);

    return XY.compare(YX)>0?1:0;
}

string largestnumber(int a[],int n)
{
    vector<string> b;
    for(int i=0;i<n;i++)
    {
        b.push_back(to_string(a[i]));
    }

    sort(b.begin(),b.end(),mycompare);

    string ans="";

    for(int i=0;i<b.size();i++)
    {
        ans+=b[i];
    }

    int i=0;
    while(ans[i]=='0'){
        i++;
    }
    if(i==ans.length())
     ans="0";
    return ans;
}



int main()
{
    int a[]={3,30,34,5,9};
    cout<<largestnumber(a,5);
}