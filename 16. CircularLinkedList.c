//Circlular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
} *temp = NULL, *loc = NULL;
void display()
{
    printf("\nThe Circular Linked List is : \n");
    loc = temp;
        printf("-> %d ->",loc->data);
    loc = loc->link;
    if(loc!=NULL)
    {
        while(loc!=temp)
        {
            printf(" %d ->",loc->data);  
            loc = loc->link;
        }
    }
    printf("\n");
}
void insertNode(int el, int prev_el)
{
    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = el;
    newnode->link = NULL;
    if(temp == NULL) 
    {
        temp = newnode;
        newnode->link = temp;
        display();
    }
    else
    {   loc = temp;
        do
        {
            if(loc->data == prev_el)
            {
                newnode->link = loc->link;
                loc->link = newnode;
                display();
                return;
                
            }
            loc = loc->link;    
        }while(loc!=temp);
        if(loc == temp)
            printf("\nElement is not list. Cannot perform insertion!\n");
    }
}
void deleteItem(int el)
{
    struct node *prevloc = NULL;
    loc = temp;
    do
    {
        if(loc->data == el)
        {
            if(loc->link == loc)
            {
                printf("\nThe List is Empty after deletion\n");
                temp = NULL;
                return;    
            }
            else
            {
                prevloc = loc->link;
                while(prevloc->link!=loc)   //setting prevloc pointing to node before loc
                {
                    prevloc = prevloc->link;
                }
                prevloc->link = loc->link;
                if(loc == temp)             //to retain temp after deleting node
                    temp = temp->link;
                display();
                return;
            }
        }
        loc = loc->link;
    }while(loc!=temp);
    if(loc == temp)
        printf("\nElement is not list. Cannot perform deletion!\n");
}
int main()
{   int c,el,prev_el = 0;
    do
    {
        printf("\nCIRCULAR LINKED LIST MENU");
        printf("\n-------------------------");
        printf("\n1. Insert an element after a particular node");
        printf("\n2. Delete node containing a particular element");
        printf("\n3. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : if(temp == NULL)
                     {
                        printf("\nEnter the initial element in list : ");
                        scanf("%d",&el);
                     }
                     else
                     {
                        printf("\nEnter data in node after which element is to be inserted : ");
                        scanf("%d",&prev_el);
                        printf("\nEnter the element to insert in node :");
                        scanf("%d",&el);
                     }
                     insertNode(el,prev_el);
                     break;
            case 2 : if(temp == NULL)
                     {
                        printf("\nEmpty list! Cannot delete\n");
                        break;
                     }
                     printf("\nEnter the element to be deleted : ");
                     scanf("%d",&el);
                     deleteItem(el);
                     break;
            case 3 : printf("\nExiting..");
                     exit(0);
            default: printf("\nPlease Try Again\n");
        }
    }while(c!=3);
}


