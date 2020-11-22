//Infix to Postfix Conversion
#include<stdio.h>
#include<ctype.h>
#define MAX 100
char opstk[MAX];
int top = -1;
int opstk_isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void opstk_push(char x)
{
    if(top == MAX - 1)
        printf("\nStack Overflow!");  
    else
    {
        top = top + 1;
        opstk[top] = x;
    }
}
char opstk_pop()
{   
    char x;
    if(opstk_isempty())
        printf("\nInvalid Infix Expression!");
    else
    {
        x = opstk[top];
        top = top - 1;
        return x;
    }
}
char opstk_peek()
{
    return  opstk[top];
}
int prec(char x)
{   
    if(x == '^')
        return 4;
    else if(x == '/' || x == '*')
        return 3;
    else if(x == '+' || x == '-')
        return 2;
    else if(x == '(')
        return 1;
    else
        return 0;
}
void infix_to_postfix(char in[],char post[])
{
    int i=0,j=0; //i = index of infix and j = index of postfix expression 
    char rem;    
    while(in[i]!='\0')
    {
        if(isalpha(in[i]) || isdigit(in[i]))    //checking if input is operand
        {
            post[j] = in[i];
            j++;
        }
        else if(in[i] == ')')        //if input is operator ')'
        {   
            while(opstk_peek() != '(')
            {
                post[j] = opstk_pop();
                j++;
            }
            rem = opstk_pop();      //to remove the '(' remaining in stack
        }
        else if(in[i] == '(')       //if input is operator '('
            opstk_push(in[i]);
        else                        //if input is any operator other than paranthesis
        {
            while(!opstk_isempty() && (prec(opstk_peek()) >= prec(in[i])))
            {
                post[j] = opstk_pop();
                j++;
            }
            opstk_push(in[i]);
        }
        ++i;
    }
    while(!opstk_isempty())
    {
        post[j] = opstk_pop();
        j++;
    }
    post[j] = '\0';
}
int main()
{
    char in_exp[MAX],post_exp[MAX];
    printf("\nEnter a valid Infix Expression (max size 100):\n");
    scanf("%s",in_exp);
    infix_to_postfix(in_exp,post_exp);
    printf("\nThe Postfix Expression is : \n");
    for(int k = 0; post_exp[k] != '\0'; k++)
        printf("%c",post_exp[k]);
}