/*Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubstring(string s)
{
    int n=s.length();
    int mx=INT_MIN;
    unordered_map<char,int> mp;
    int i=0,j=0;

    while(j<n)
    {
        mp[s[j]]++;
         if(mp.size()==j-i+1)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()<j-i+1)
        {
            while(mp.size()<j-i+1)
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
    //string s="pwwkew";
    string s="abcdabc";
    int ans=longestSubstring(s);

    cout<<ans<<endl;
}