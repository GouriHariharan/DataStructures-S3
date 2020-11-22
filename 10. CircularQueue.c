//Circular Queue 
#include<stdio.h>
int MAX,front=-1, rear=-1;
int isempty()
{
    if(front<0)  
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
void insert(int CQ[MAX])
{
    if(isfull())
        printf("\nThe CQueue is FULL!\n");
    else
    {
        int el;
        printf("\nEnter element to be added in queue : \n");
        scanf("%d",&el);
        if(isempty())           //if queue is initially empty
            front = 0;
        rear = (rear + 1) % MAX;
        CQ[rear]= el;
    }
}
void delete(int CQ[MAX])
{
    if(isempty())
        printf("\nCQueue is EMPTY!...\n");
    else
    {
        printf("\nThe element removed is : %d\n",CQ[front]);
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX;
    }
}
void display(int CQ[MAX])
{
    int i;
    if(isempty())
        printf("\nCQueue is EMPTY!...\n");
    else
    {   printf("\nCQueue now contains : \n");
        for(i=front; i!=rear; i = (i+1)%MAX)
            printf("%d\n",CQ[i]);
        printf("%d\n",CQ[i]);
    }
}
int main()
{
    printf("\nEnter the size of Circular Queue : ");
    scanf("%d",&MAX);
    int CQ[MAX],c;
    do
    {
        printf("\nCIRCULAR QUEUE OPERATIONS MENU");
        printf("\n------------------------------");
        printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. EXIT");
        printf("\nEnter your choice : \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: insert(CQ);
                    break;
            case 2: delete(CQ);
                    break;
            case 3: display(CQ);
                    break;
            case 4: printf("\nExiting....");
                    break;
            default : printf("\nPlease Try Again\n");
        }
    }while(c!=4);
}
