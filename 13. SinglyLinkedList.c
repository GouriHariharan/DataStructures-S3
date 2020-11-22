/*Write a menu driven program in C to implement a singly 
linked list and to perform the following 
i)  Insert a node at the beginning of the list   
ii) Insert a node after a particular node in the list
iii) Insert a node at the end of the list 
iv) Delete a node containing a particular item*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *newnode,*start = NULL,*loc = NULL,*prev = NULL;
void createNewNode(int item)
{
    newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;   
}
void display()
{   
    loc = start;
    while(loc->link!=NULL)
    {
        printf("%d -> ",loc->data);
        loc = loc->link;
    }
    printf("%d\n",loc->data);
}
void insertAtBeginning(int item)
{
    createNewNode(item);
    if(start!=NULL)
        newnode->link = start;
    start = newnode;
    printf("\nThe linked list after insertion at beginning :\n");
    display();
}
void insertAtPosition(int item, int pos)
{   //pos=position of node after which we have to insert 
    int temp;
    createNewNode(item);  
    loc = start;
    for(temp = 1; temp<pos; temp++)
    {
        loc = loc->link;
        if(loc == NULL) //if pos > no of nodes in list
        {
            printf("\nPosition greater than number of nodes in list. Cannot insert\n");
            return;
        }
    }
    newnode->link = loc->link;
    loc->link = newnode;
    printf("\nThe linked list after insertion after given position :\n");
    display();
}
void insertAtEnd(int item)
{
    createNewNode(item);
    loc = start;
    while(loc->link!=NULL)
        loc=loc->link;
    loc->link = newnode;
    printf("\nThe linked list after insertion at end :\n");
    display();
}
void deleteItem(int item)
{
    loc = start;
    prev = start;
    while(loc->data!=item)
    {
        prev = loc;
        loc = loc->link;
        if(loc == NULL)
        {
            printf("\nElement not found in List.");
            return;
        }
    }
    if(loc == start && loc->data == item)
    {
        if(loc->link == NULL) //single node containing item
        {
            start = NULL;
            printf("\nList empty after deletion\n");
            return;
        }
        else                   //deleting starting element
            start = start->link;
    }
    else
        prev->link = loc->link;
    printf("\nThe linked list after deletion is :\n");
    display();
}
int main()
{   int c;
    int item,pos;
    do{
        printf("\nLINKED LIST OPERATIONS MENU");
        printf("\n---------------------------");
        printf("\n1. Insert a node at the beginning of the list");
        printf("\n2. Insert a node after a particular node in the list");
        printf("\n3. Insert a node at the end of the list");
        printf("\n4. Delete a node containing a particular item");
        printf("\n5. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("\nEnter the item to be inserted : ");
                     scanf("%d",&item);
                     insertAtBeginning(item);
                     break;
            case 2 : if(start == NULL)
                     {
                        printf("\nEmpty list. Please insert at beginning\n");
                        break;
                     }
                     printf("\nEnter the position of node after which item is to be inserted : ");
                     scanf("%d",&pos); 
                     printf("\nEnter the item to be inserted : ");
                     scanf("%d",&item);
                     insertAtPosition(item,pos);
                     break;
            case 3 : if(start == NULL)
                     {
                        printf("\nEmpty list. Please insert at beginning\n");
                        break;
                     }
                     printf("\nEnter the item to be inserted : ");
                     scanf("%d",&item);
                     insertAtEnd(item);
                     break;
            case 4 : if(start == NULL)
                     {
                        printf("\nEmpty list!\n");
                        break;
                     }
                     printf("\nEnter the item to be deleted : ");
                     scanf("%d",&item);
                     deleteItem(item);
                     break;
            case 5 : printf("\nExiting..");
                     exit(0);
            default: printf("\nPlease Try Again\n");
        }
    }while(c!=5);
}