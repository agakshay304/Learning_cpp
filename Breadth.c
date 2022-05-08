#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1;
int rear = -1;
int vertices;
int edges;
int i, j;
int v1, v2;
int count = 0;
int flag = 0;

void enqueue(int);
int dequeue();
void bfs(int);

int main()
{
	printf("Enter the number of vertices: ");
	scanf("%d", &vertices);
	printf("Enter the number of edges: ");
	scanf("%d", &edges);
	printf("Enter the adjacency matrix: \n");
	for (i = 0; i < vertices; i++)
	{
		for (j = 0; j < vertices; j++)
		{
			scanf("%d", &adjacency_matrix[i][j]);
		}
	}
	printf("Enter the source vertex: ");
	scanf("%d", &v1);
	bfs(v1);
	printf("\n");
	for (i = 0; i < vertices; i++)
	{
		if (visited[i] == 0)
		{
			bfs(i);
			printf("\n");
		}
	}
	return 0;
}

void enqueue(int v)
{
	if (rear == MAX_VERTICES - 1)
	{
		printf("Queue is full\n");
		return;
	}

   if (front == -1)
	{
		front = 0;
	}
	rear++;
	queue[rear] = v;
}

int dequeue()
{
	int v;
	if (front == -1 || front > rear)
	{
		printf("Queue is empty\n");
		return -1;
	}


	v = queue[front];
	front++;
	return v;
}

void bfs(int v)
{
	int i;
	enqueue(v);
	visited[v] = 1;
	while (front <= rear)
	{
		v = dequeue();
		printf("%d ", v);
		for (i = 0; i < vertices; i++)
		{
			if (adjacency_matrix[v][i] == 1 && visited[i] == 0)
			{
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}
