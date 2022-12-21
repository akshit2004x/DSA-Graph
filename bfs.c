#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;
void enqueue(int item)
{
    struct node *new;
    new = (struct node *)malloc(sizeof (struct node));
    new->data=item;
    new->next=NULL;
    if(front==NULL)
    {
        front=new;
        rear=new;
    }
    else
    {
        rear->next=new;
        rear=new;
    }
}
int dequeue()
{
    int item;
    if(front==NULL)
        printf("underflow");
    else
    {
        struct node* temp=front;
        item=temp->data;
        front=front->next;
        free(temp);
        return item;
    }
}
int isempty()
{
    return front==NULL;
}
void BFS(int G[][7],int start,int n)
{
    int i=start,j;
    int visited[7]={0};
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
    while(!isempty())
    {
        i=dequeue();
        for(int j=1;j<n;j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}
void DFS(int G[][7],int start,int n)
{
    static int visited[7]={0};
    int j;
    if(visited[start]==0)
    {
        printf("%d ",start);
        visited[start]=1;
        for(j=1;j<n;j++)
        {
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
        }
    }
}
int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    BFS(G,3,7);
    printf("\n");
    DFS(G,3,7);
    return 0;
}