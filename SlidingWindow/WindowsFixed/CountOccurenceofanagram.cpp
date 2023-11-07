#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int search(string pat, string txt) {
	    unordered_map<char,int> mp;
	    int ans =0;
	   
	    for(char i : pat) {
	        if(mp[i]>=1) 
            mp[i]++;
	        else 
            mp[i]=1;
	    }
	    int cnt = mp.size();
	  int i =0;
	  int j =0;
	  int k = pat.size();
	  
	  while(j<txt.size()) {
	     if(mp.find(txt[j])!=mp.end())
	       {
	           mp[txt[j]]--;
	           if(mp[txt[j]]==0)
               cnt--;
	       }
	      
	      if(j-i+1<k) 
          j++;
	      else if(j-i+1==k) {
	          if(cnt==0){
	              ans++;
	          }
	            if(mp.find(txt[i])!=mp.end())
	          {
	              if(mp[txt[i]]==0)
                  cnt++;
	              mp[txt[i]]++;   
	          }
	          i++;
	          j++;
	      }
	  }
	  return ans;
}

int main()
{
    string s="aabaabaa";
    string pattern ="aaba";

    int ans=search(pattern,s);

    cout<<ans;
}