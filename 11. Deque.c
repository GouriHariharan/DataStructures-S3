//Deque using Array
#include<stdio.h>
int MAX;
int front=-1,rear=-1;
int isempty()
{
    if(front<0 && rear<0)  
        return 1;
    else
        return 0;   
}
int isfull()
{
    if(front==rear+1 ||(front==0 && rear==MAX-1))
        return 1;
    else 
        return 0;
}
void insertRight(int deque[MAX])
{   
    if(isfull())
        printf("\nQueue is full!");
    else
    {
        if(isempty()) //initially empty queue
        {
            front = 0;
            rear = 0;
        }
        else if(rear == MAX-1)    
            rear = 0;
        else
            rear = rear + 1;
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&deque[rear]);
    }
}
void insertLeft(int deque[MAX])
{
    if(isfull())
        printf("\nQueue is full!");
    else
    {
        if(isempty()) //initially empty queue
        {
            front = 0;
            rear = 0;
        }
        else if(front == 0)
            front = MAX-1;
        else
            front = front - 1;
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&deque[front]);
    }
}
void deleteLeft(int deque[MAX])
{
    if(isempty())
        printf("Deque is Empty!");
    else
    {
        printf("\nThe element removed is : %d\n",deque[front]);
        if(front == rear)   //only one element
        {
            front = -1;
            rear = -1;
        }
        else if(front == MAX-1)
            front = 0;
        else
            front = front + 1;
    }
}
void deleteRight(int deque[MAX])
{
    if(isempty())
        printf("Deque is Empty!");
    else
    {
        printf("\nThe element removed is : %d\n",deque[rear]);
        if(front == rear)   //only one element
        {
            front = -1;
            rear = -1;
        }
        else if(rear == 0)
            rear = MAX-1;
        else
            rear = rear - 1;
    }    
}
void display(int deque[MAX])
{
    int i;
    if(isempty())
        printf("\nDeque is EMPTY!...\n");
    else
    {   printf("\nDeque now contains : \n");
        for(i=front; i!=rear; i = (i+1)%MAX)
            printf("%d\n",deque[i]);
        printf("%d\n",deque[i]);
    }   
}
int main()
{
    int c;
    printf("\nEnter the size of Deque : \n");
    scanf("%d",&MAX);
    int deque[MAX],ch;
    do
    {       printf("\nDEQUE OPERATIONS MENU");
            printf("\n---------------------");
            printf("\n1. Insert at right end\n2. Insert at left end\n3. Delete from right end\n4. Delete from left end\n5. Display\n6. Exit");
            printf("\nEnter your choice : \n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1 : insertRight(deque);
                         break;
                case 2 : insertLeft(deque);
                         break;
                case 3 : deleteRight(deque);
                         break;
                case 4 : deleteLeft(deque);
                         break;
                case 5 : display(deque);
                         break;
                case 6 : printf("\nExit...");
                         break;
                default :printf("\nPlease try again!");
            }
    }while(ch!=6);
}
