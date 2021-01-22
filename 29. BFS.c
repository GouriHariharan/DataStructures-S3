#include <stdio.h>
#include <stdlib.h>

struct node
{
    int v;
    struct node *link;
}*a[100], *temp, *current, *head;

int V, q[100], visited[100];
int front = -1, rear = -1;
void enqueue(int x)
{
    if(front == 100-1)
    {
        printf("\nThe Queue is Full!");
        exit(0);
    }
    if(front == -1)
        front = 0;
    rear++;
    q[rear] = x;
}

int dequeue()
{
    int x = q[front];
    front++;
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
    return x;
}

void bfs()
{
    visited[0] = 1; //starting from v1
    enqueue(0);
    while(rear != -1)
    {
        int x = dequeue();
        printf("v%d\t", x+1);
        temp = a[x];
        while (temp != NULL)
        {
            if (visited[temp->v] == 0)
            {
                visited[temp->v] = 1;
                enqueue(temp->v);
            }
            temp = temp->link;
        }
    }
}

void main()
{
    printf("Enter number of vertices (start from v1):\n");
    scanf("%d", &V);
    int i, j, n, av;
    for (i = 0; i < V; i++) //for each of the vertices
    {
        a[i] = (struct node *)malloc(sizeof(struct node));
        a[i]->v = i;
        a[i]->link = NULL;
        current = a[i];
        printf("\nEnter the number of adjacent vertices of v%d :",i+1);
        scanf("%d",&n);
        printf("Enter the adjacent vertices of v%d\n", i+1);
        for(int j=0; j<n; j++)  //all adj vertices to given vertex
        {
            scanf("%d", &av);    
            temp = (struct node *)malloc(sizeof(struct node));
            temp->v = av - 1;
            temp->link = NULL;
            current->link = temp;
            current = temp;
        }
    }
    bfs();
}