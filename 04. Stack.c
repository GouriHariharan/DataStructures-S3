//Implementing stack using array
#include<stdio.h>
int n,top = -1;                     //n is size of stack array
int isempty()                       //checks if the stack is empty
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(int stack[100])   //pushes an element into the stack
{   int el;
    if(top == n-1)
        printf("\nThe stack is FULL! Cannot push element....\n");    
    else
    {   printf("\nEnter the element to be pushed :\n");
        scanf("%d",&el);
        ++top;
        stack[top]=el;
    }
}
void pop(int stack[100])            //pops the top element of stack
{   
    if(!isempty())
    {
        printf("\nElement popped is : %d\n",stack[top]);
        top = top-1;
    }
    else
        printf("\nThe stack is EMPTY!...\n");
}
void peek(int stack[100])           //peeks into topmost element of stack
{
    if(!isempty())
        printf("\nTopmost element is : %d\n",stack[top]);
    else
        printf("\nThe stack is EMPTY!...\n");
}
void display(int stack[100])        //displays the contents of stack
{   
    if(isempty())
        printf("\nThe stack is EMPTY!...\n");
    else
    {   printf("\nThe Stack contains :\n");
        for(int i=top;i>=0;i--)
          printf("\n%d",stack[i]);
    }
}
int main()
{
    int c,el,stack[100];
    printf("\nEnter the stack size : \n");
    scanf("%d",&n);
    do
    {
        printf("\nSTACK OPERATION MENU");   
        printf("\n--------------------");
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT");
        printf("\nEnter your choice :\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: push(stack);
                    break;
            case 2: pop(stack);
                    break;
            case 3: peek(stack);
                    break;
            case 4: display(stack);
                    printf("\n");
                    break;
            case 5: printf("\nExiting...");
                    break;
            default : printf("\nPlease Try Again");
        }
    }while(c!=5);    
}