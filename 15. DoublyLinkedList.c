/*Write a menu driven program in C to implement a doubly linked list and to perform thefollowing
i) Insert a node at the beginning of the list
ii) Insert a node after a particular node in the list
iii) Insert a node at the end of the list
iv) Delete a node containing a particular item*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *nextlink;
    struct node *prevlink;
};
struct node *newnode,*start = NULL,*loc = NULL;
void createNewNode(int item)
{
    newnode = malloc(sizeof(struct node));
    newnode->data = item;
    newnode->prevlink = NULL;   
    newnode->nextlink = NULL;
}
void display()
{   
    loc = start;
    while(loc->nextlink != NULL)
    {
        printf("%d -><-",loc->data);
        loc = loc->nextlink;
    }
    printf("%d\n",loc->data);
}
void insertAtBeginning(int item)
{
    createNewNode(item);
    if(start != NULL)
    {
        start->prevlink = newnode;
        newnode->nextlink = start;
    }
    start = newnode;
    display();
}
void insertAtPosition(int item, int pos)
{   //pos=position of node after which we have to insert 
    createNewNode(item);
    int temp;
    loc = start;
    for(temp = 1;temp<pos;temp++)
    {
        loc = loc->nextlink; 
        if(loc == NULL) //if pos > no of nodes in list
        {
            printf("\nPosition greater than number of nodes in list. Cannot insert\n");
            return;
        }
    }
    newnode->nextlink = loc->nextlink;
    loc->nextlink = newnode;
    newnode->prevlink = loc;
    if(newnode->nextlink != NULL)   //if inserted node is at end of list
        newnode->nextlink->prevlink = newnode;
    display(); 
}
void insertAtEnd(int item)
{
    createNewNode(item);
    loc = start;
    while(loc->nextlink!=NULL)
        loc = loc->nextlink;
    loc->nextlink = newnode;
    newnode->prevlink = loc;
    display();
}
void deleteItem(int item)
{
    loc = start;
    while(loc->data!=item)
    {
        loc=loc->nextlink; 
        if(loc == NULL)
        {
            printf("\nElement not in list\n");
            return;
        }
    }
    if(loc == start)
    {
        if(loc->nextlink == NULL)
        {
            printf("\nEmpty list after deletion\n");
            start = NULL;
            return;
        }
        else
        {
            start = start->nextlink;
            start->prevlink = NULL;
        }
    }
    else
    {
            loc->prevlink->nextlink = loc->nextlink;
        if(loc->nextlink != NULL)       //element to be deleted not in end node
            loc->nextlink->prevlink = loc->prevlink;
    }
    display();
}
int main()
{   int c;
    int item,pos;
    do{
        printf("\nDOUBLY LINKED LIST OPERATIONS MENU");
        printf("\n----------------------------------");
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
                        printf("\nEmpty list! Cannot delete\n");
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
