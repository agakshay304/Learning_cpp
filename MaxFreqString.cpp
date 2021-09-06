#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str="akshay";
    int freq[26];
    for(int i=0;i<26;i++)
    {
        freq[i]=0;
    }

    for(int i=0;i<str.length();i++)
    {
        freq[str[i]-'a']++;
    }

    char ans='a';
    int maxf=0;

    for(int i=0;i<str.length();i++)
    {
        if(freq[i] >=maxf)
        {
            maxf=freq[i];
            ans=i+'a';
        }
    }

    return 0;
}