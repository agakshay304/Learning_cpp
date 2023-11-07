#include <bits/stdc++.h>
#include <queue>
using namespace std;

void BFS(int G[][7], int start, int n)
{
    int i = start;
    queue<int> d;
    int visited[7] = {0};
    cout << i << " ";
    d.push(i);
    visited[i] = 1;
    while (!d.empty())
    {
        i = d.front();
        d.pop();
        for (int j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                d.push(j);
            }
        }
    }
}

int main()
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    BFS(G, 1, 7);
}