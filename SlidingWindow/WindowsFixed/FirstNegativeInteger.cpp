/*Input : arr[] = {-8, 2, 3, -6, 10}, k = 2
Output : -8 0 -6 -6
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

Input : arr[] = {12, -1, -7, 8, -15, 30, 16, 28} , k = 3
Output : -1 -1 -7 -15 -15 0 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                vector<long long>ans;
                deque<long long>list;
                long long i=0,j=0;
                while(j<N){
                    if(A[j]<0)
                    list.push_back(A[j]);
                    if(j-i+1 < K)
                    {
                        j++;
                        continue;
                    }
                    else if(j-i+1 == K){
                        if(!list.empty())
                        ans.push_back(list.front());
                        else 
                        ans.push_back(0);
                        if(A[i]<0)
                        list.pop_front();
                        i++;
                    }
                    j++;
                }
                return ans;
 }


int main()
{
  long long int a[]={12, -1, -7, 8, -15, 30, 16, 28};
    vector<long long> ans=printFirstNegativeInteger(a,8,3);

    cout<<"ans is "<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;   
         }
}