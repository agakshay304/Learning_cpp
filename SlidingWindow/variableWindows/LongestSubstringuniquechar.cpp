/*"aabbcc", k = 1
Max substring can be any one from {"aa" , "bb" , "cc"}.

"aabbcc", k = 2
Max substring can be any one from {"aabb" , "bbcc"}.

"aabbcc", k = 3
There are substrings with exactly 3 unique characters
{"aabbcc" , "abbcc" , "aabbc" , "abbc" }
Max is "aabbcc" with length 6.

"aaabbb", k = 3
There are only two unique characters, thus show error message.*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubstring(string s,int k)
{
    int n=s.length();
    int mx=INT_MIN;
    unordered_map<char,int> mp;
    int i=0,j=0;

    while(j<n)
    {
        mp[s[j]]++;
        if(mp.size()<k)
        j++;
        else if(mp.size()==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    if(mx==INT_MIN)
    {
        return -1;
    }
    return mx;
}

int main()
{
    string s="aabacbebebe";
    //string s="aaabbb";
    int ans=longestSubstring(s,3);

    cout<<ans<<endl;
}