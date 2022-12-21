#include<stdio.h>

void DFS(int);
int graph[10][10], visited[10],total;

int main()
{
	int i,j;
	printf("\nEnter the total number of vertices in graph\n");
	scanf("%d",&total);
	/*Adjacency matrix input*/
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<total;i++)
	{
		for(j=0;j<total;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	for(i=0;i<total;i++)
	{
		visited[i] = 0;
	}
	printf("\nDFS traversal is \n");
	DFS(0);
}
void DFS(int vertex)
{
	int j;
	printf("%d\t",vertex);
	visited[vertex] = 1;
	for(j=0;j<total;j++)
	{
		if(visited[j]==0 && graph[vertex][j] == 1 )
		{
			DFS(j);
		}
	}
}