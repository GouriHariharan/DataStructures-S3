//Polynomial addition using singly linked list 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expo;
    struct node* link;
}*begA = NULL, *begB = NULL, *begS = NULL, *newnode = NULL, *loc = NULL;
void insertNode(int c, int e, struct node **beg)
{
    newnode = malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->expo = e;
    newnode->link = NULL;
    if(*beg == NULL)
        *beg = newnode;
    else
    {
        loc = *beg;
        while(loc->link != NULL)
            loc = loc->link;
        loc->link = newnode;
    }
}
void display(struct node* loc)
{
    printf("%dx^%d",loc->coeff,loc->expo); 
    while(loc->link!=NULL)
    {
        loc = loc->link;
        printf(" + %dx^%d",loc->coeff,loc->expo);
    }
}
void PolynomialAddition()
{
    int c,e;
    struct node *locA = begA, *locB = begB;
    while(locA!=NULL && locB!=NULL)
    {
        if(locA->expo == locB->expo)
        {
            c = locA->coeff + locB->coeff;
            e = locA->expo;
            insertNode(c,e,&begS);   
            locA = locA->link;
            locB = locB->link;
        }
        else if(locA->expo > locB->expo)
        {
            insertNode(locA->coeff,locA->expo,&begS);
            locA = locA->link;
        }
        else
        {
            insertNode(locB->coeff,locB->expo,&begS);
            locB = locB->link;
        }
    }
    if(locA!=NULL) //no of terms of A > no of terms of B
    {
        while(locA!=NULL)
        {
            insertNode(locA->coeff,locA->expo,&begS);
            locA = locA->link;    
        }
    }
    if(locB!=NULL) //no of terms of A < no of terms of B
    {
        while(locB!=NULL)
        {
            insertNode(locB->coeff,locB->expo,&begS);
            locB = locB->link;   
        }
    }
    printf("\n\nThe Polynomial Sum is : \n");
    display(begS);
}
int main()
{
    int a,b,i,j,c,e;    //a,b are sizes of polynomials A,B
    printf("\nTerms of Polynomial must be in decreasing order \nof exponents and exclude terms with coefficient 0");
    printf("\nEnter the number of terms of first Polynomial(A): ");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        printf("\nEnter coefficient and exponent of term %d respectively :\n",i+1);
        scanf("%d %d",&c,&e);
        insertNode(c,e,&begA);
    }
    printf("The first Polynomial is : \n");
    display(begA);
    printf("\n\nEnter the number of terms of second Polynomial(B): ");
    scanf("%d",&b);
    for(j=0;j<b;j++)
    {
        printf("\nEnter coefficient and exponent of term %d respectively :\n",j+1);
        scanf("%d %d",&c,&e);
        insertNode(c,e,&begB);    
    }
    printf("The second Polynomial is : \n");
    display(begB);
    PolynomialAddition();    
}