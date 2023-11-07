#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		void DFS1(int i,vector<bool> &visited,stack<int> &mystack,vector<int> adj[])
	{
	    if(visited[i]==true)
	    {
	        return;
	    }
	    visited[i]=true;
	    for(int j:adj[i])
	    {
	        if(!visited[j])
	        {
	            DFS1(j,visited,mystack,adj);
	        }
	    }
	        mystack.push(i);
	}
	
	void DFS2(int curr,vector<bool> &visited,vector<int>adj[],int V)
	{
	    if(visited[curr])
	    return ;
	    visited[curr]=true;
	    for(int j:adj[curr])
	    {
	        if(!visited[j])
	        {
	            DFS2(j,visited,adj,V);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> mystack;
        int count=0;
        vector<bool> visited(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS1(i,visited,mystack,adj);
            }
        }
        vector<int>transpose[V];
       for(int i=0;i<V;i++){
           visited[i]=false;
           for(auto it:adj[i])
           {
               transpose[it].push_back(i);
           } }
        while(!mystack.empty())
        {
            int curr=mystack.top();
            mystack.pop();
            if(!visited[curr])
            {
                DFS2(curr,visited,transpose,V);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}