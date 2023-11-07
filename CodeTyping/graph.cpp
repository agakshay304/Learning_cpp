#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int> adj[])
{
    // int n=adj.size();

    for(int i=0;i<5;i++)
    {
        cout<<i<<":";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<"->";
        }
        cout<<endl;
    }
}

void dfs(int v,vector<int> adj[],vector<int> &visited)
{
    visited[v]=1;
    cout<<v;
    for(auto i:adj[v])
    {
        vector<int> component;
        if(!visited[i])
        {
            dfs(i,adj,visited);
        }
    }
}

void bfs(vector<int> adj[],vector<int> &visited,int node)
{
    queue<int> q;
    q.push(node);
    
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();
        cout<<frontNode<<" ";
        
        for(auto i:adj[frontNode])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
}


int main()
{
    int n=5;
    // cin>>n;
    vector<int> adj[n];

    // addEdge(adj,0,1);
    // addEdge(adj,1,2);
    // addEdge(adj,2,0);
    // addEdge(adj,0,3);

    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,3);
    addEdge(adj,1,2);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);

    print(adj);
    cout<<"Depth First Search"<<endl;
    vector<int> visited(5);
    for(int i=0;i<5;i++)
    {
        if(!visited[i])
        dfs(i,adj,visited);
    }
    cout<<endl;
    cout<<"Breadth First Search"<<endl;
    vector<int> visitedd(5,-1);
    for(int i=0;i<5;i++)
    {
        bfs(adj,visitedd,i); 
    }

}
