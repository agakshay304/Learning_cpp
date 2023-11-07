#include <iostream>
#include<vector>
#include<deque>
using namespace std;


 vector<int> maxSlidingWindow(vector<int>& A, int B) {
     vector<int> ans;  
     if(A.size()<B){
        ans.push_back(*max_element(A.begin(),A.end()));
        return ans;
    }
    deque<int> Q;
    int i=0,j=0;
    while(j<A.size()){
        while(!Q.empty() && Q.back()<A[j]){
                Q.pop_back();
        }
        Q.push_back(A[j]);
        if(j-i+1 <B){
            j++;
        }
        
        else if(j-i+1 == B){
            ans.push_back(Q.front());
            if(A[i]==Q.front()){
                Q.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
        
    }

int main()
{
    vector<int> a;
    // {1,3,-1,-3,5,3,6,7};
    a.push_back(1);
    a.push_back(3);
    a.push_back(-1);
    a.push_back(-3);
    a.push_back(5);
    a.push_back(3);
    a.push_back(6);
    a.push_back(7);
    vector<int> ans=maxSlidingWindow(a,3);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
}