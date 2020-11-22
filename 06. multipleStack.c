//Multiple Stack in array
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
int top_1 = -1;
int top_2 = MAXSIZE;
int array[MAXSIZE];
void PUSH(int a, int el)
{
     if(a == 1)                      //if push is in stack1
    {
        if(top_1+1 == top_2)          //checking if array is full
        {
            printf("\nStack Overflow! Cant push element...\n");
        }
        else
        {
            top_1 = top_1 + 1;
            array[top_1] = el;
        }
    }
    else                            //if push is in stack2
    {
        if(top_1+1 == top_2)          //checking if array is full
        {
            printf("\nStack Overflow! Cant push element...\n");
        }
        else
        {
            top_2 = top_2 - 1;
            array[top_2] = el;
        }
    }
}
void POP(int a)
{
    if(a == 1)                      //POP STACK 1
    {
        if(top_1 > -1)             
        {
            printf("\nThe Element Popped is %d",array[top_1]);
            top_1 = top_1 - 1;
        }
        else                        //condition for empty stack 1
            printf("\nStack is Empty!\n");
        
    }
    else
    {
        if(top_2 < MAXSIZE)        //POP STACK 2
        {
            printf("\nThe Element Popped is %d",array[top_2]);
            top_2 = top_2 + 1;
        }
        else                       //condition for empty stack 2
            printf("\nStack is Empty!\n");
    }
}
void PEEK(int a)
{
    if(a == 1)                      //PEEK STACK 1
    {
        if(top_1 > -1)             
            printf("\nThe Topmost element of Stack 1 is : %d",array[top_1]);
        else                    //condition for empty stack 1
            printf("\nStack is Empty!\n");
    }
    else                            //PEEK STACK 2
    {
        if(top_2 < MAXSIZE)        
            printf("\nThe Topmost element of Stack 2 is : %d",array[top_2]);
        else                    //condition for empty stack 2
            printf("\nStack is Empty!\n");
    }        
}
void DISPLAY(int a)
{
    if(a == 1)                  //DISPLAY STACK 1
    {
        if(top_1 > -1)
        {   printf("\nContents of Stack 1 is : \n");
            for(int i=top_1; i>=0; --i)
                printf("%d\n",array[i]);
        }
        else                    //condition for empty stack 1
            printf("\nStack is Empty!\n");
    }    
    else                        //DISPLAY STACK 2 
    {
        if(top_2 < MAXSIZE)
        {   printf("\nContents of Stack 2 is : \n");
            for(int i=top_2; i<MAXSIZE; ++i)
                printf("%d\n",array[i]);
        }
        else                    //condition for empty stack 1
            printf("\nStack is Empty!\n");    
    }
}
int main()
{  
    int ch,c,x;
    do
    {
        printf("\nChoose a stack (1/2): \n");
        scanf("%d",&ch);
        if(ch!=1 && ch!=2)
        {
            printf("\nWrong choice!");
            break;
        }
        printf("\nSTACK %d OPERATION MENU",ch);
        printf("\n-----------------------");
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT");
        printf("\nEnter your choice :\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: printf("\nEnter the element to be pushed: \n");
                    scanf("%d",&x);
                    if(ch == 1)
                        PUSH(1,x);
                    else
                        PUSH(2,x);
                    break;
            case 2: if(ch == 1)
                        POP(1);
                    else
                        POP(2);
                    break;
            case 3: if(ch == 1)
                        PEEK(1);
                    else
                        PEEK(2);
                    break;
            case 4: if(ch == 1)
                        DISPLAY(1);
                    else
                        DISPLAY(2);
                    break;
            case 5: printf("\nExit...");
                    break;
            default: printf("\nPlease Try Again!");
        }
    }while(c!=5);
}