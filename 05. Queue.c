//Implementing queue using array
#include<stdio.h>
int n,rear=-1,front=-1;
int isempty()
{
    if(front<0 || front>rear)  
        return 1;
    else
        return 0;   
}
void enqueue(int queue[100])
{
    if(rear == n-1)
        printf("\nThe Queue is FULL!\n");
    else
    {
        int el;
        printf("\nEnter element to be added in queue : \n");
        scanf("%d",&el);
        if(front==-1)           //if queue is initially empty
            front = 0;
        rear = rear + 1;
        queue[rear]= el;
    }
}
void dequeue(int queue[100])
{
    if(isempty())
        printf("\nQueue is EMPTY!...\n");
    else
    {
        printf("\nThe element removed is : %d\n",queue[front]);
        front = front + 1;
    }
}
void display(int queue[100])
{
    if(isempty())
        printf("\nQueue is EMPTY!...\n");
    else
    {   printf("\nQueue now contains : \n");
        for(int i=front; i<=rear; i++)
            printf("%d\n",queue[i]);
    }
    
}
int main()
{
    int queue[100];
    int c;
    printf("\nEnter the size of Queue : \n");
    scanf("%d",&n);
    do
    {  
        printf("\nQUEUE OPERATIONS MENU");
        printf("\n---------------------");
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT");
        printf("\nEnter your choice : \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: enqueue(queue);
                    break;
            case 2: dequeue(queue);
                    break;
            case 3: display(queue);
                    break;
            case 4: printf("\nExiting....");
                    break;
            default : printf("\nPlease Try Again\n");
        }
    }while(c!=4);
}