#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int low=0;
        int mid=0;
        int high=n-1;
        
        if(mid<=high)
        {
            if(arr[mid]>0)
            {
                swap(arr[mid],arr[low]);
                mid++;
                low++;
            }
            else
            if(arr[mid<0])
            {
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
    void swap(int arr[],int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}