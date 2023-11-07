/*Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;


int main(){
    priority_queue<pair<int, pair<int,int> > > max_heap; // {(x^2+y^2),(x,y)}
    int n,k;
    cout << "Enter array length:- ";
    cin >> n;
    int arr[n][2];
    cout << "Enter the 2D array:- "<< endl;
    int ele;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin >> ele;
            arr[i][j]=ele;
        }
    }
    cout << "Enter k value:- ";
    cin >> k;
    for(int i=0;i<n;i++){
        int x=arr[i][0];
        int y=arr[i][1];
        max_heap.push(make_pair(x*x+y*y,make_pair(x,y)));
        if(max_heap.size()>k){
            max_heap.pop();
        }
    }
    cout << "The k closest points to origin are:- " <<endl;
    while(!max_heap.empty()){
        pair<int,int > p=max_heap.top().second;
        cout << p.first << " " << p.second << endl;
        max_heap.pop();
    }
}