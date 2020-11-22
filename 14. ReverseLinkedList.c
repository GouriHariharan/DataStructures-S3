//Reversing a linked list 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
void create(struct node **start, int val)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;
    newnode->link = *start;
    *start = newnode;
}
void reverse()
{
    struct node *prev = NULL, *loc = NULL, *next = NULL;
    loc = start; 
    while(loc!=NULL)
    {
        next = loc->link;
        loc->link = prev;
        prev = loc;
        loc = next;
    }
    start = prev;
}
void display()
{
    struct node *loc;
    loc = start;
    while(loc->link!=NULL)
    {
        printf("%d -> ",loc->data);
        loc = loc->link;
    }
    printf("%d\n",loc->data);
}
int main()
{
    int n;
    char c;
    printf("\nEnter the data elements to be stored in linked list");
    printf("\n(Insert from beginning)");
    do
    {
        printf("\nEnter the element : ");
        scanf("%d",&n);
        create(&start,n);
        printf("\nDo you want to continue insertion ?(y/n) ");
        scanf("\n%c",&c);
    }while(c == 'y');
    printf("\nThe linked list is : ");
    display();
    reverse();
    printf("\nThe reversed linked list is : ");
    display();
}