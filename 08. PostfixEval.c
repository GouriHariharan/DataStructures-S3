//Postfix evaluation
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
char opstk[MAX];
int top = -1;
void opstk_push(int x)
{
    if(top == MAX-1)
        printf("\nStack Overflow!");
    else
    {
        top = top + 1;
        opstk[top] = x;
    }
}
int opstk_pop()
{
    if(top == -1)
        printf("\nStack Empty!");
    else
    {
        int x = opstk[top];
        top = top - 1;
        return x;
    }
}
int post_eval(char post[MAX])
{
    int i=0,val;
    int op1, op2;
    while(post[i] != '\0')
    {
        if(isalpha(post[i]))            //checking if input is operand
        {
            printf("\nEnter the value of %c : ",post[i]);
            scanf("%d",&val);    
            opstk_push(val);   
        }
        else
        {
            op2 = opstk_pop();
            op1 = opstk_pop();
            switch(post[i])
            {
                case '^' : opstk_push(pow(op1,op2));
                           break;
                case '/' : opstk_push(op1/op2);
                           break;
                case '*' : opstk_push(op1*op2);
                           break;
                case '+' : opstk_push(op1+op2);
                           break;
                case '-' : opstk_push(op1-op2);
                           break;
                default  : printf("Symbol not recognised");
            }
        }
        ++i;
    }
    return(opstk_pop());
}
int main()
{
    char post_exp[MAX];
    printf("\nEnter a valid Postfix Expression :\n");
    scanf("%s",post_exp);
    int x = post_eval(post_exp);
    printf("\nThe Result is : %d\n", x);
}