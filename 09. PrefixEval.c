//Prefix Evaluation
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
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
int prefix_eval(char pref[MAX])
{
    int i,val,len;
    int op1, op2;
    len = strlen(pref);
    i = len - 1;
    while(i>=0)                 //scanning from right of expression
    {
        if(isalpha(pref[i]))            //checking if input is operand
        {
            printf("\nEnter the value of %c : ",pref[i]);
            scanf("%d",&val);    
            opstk_push(val);   
        }
        else
        {
            op1 = opstk_pop();  //opposite condition of postfix for prefix
            op2 = opstk_pop();
            switch(pref[i])
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
        --i;
    }
    return(opstk_pop());
}
int main()
{
    char pref_exp[MAX];
    printf("\nEnter a valid Prefix Expression :\n");
    scanf("%s",pref_exp);
    int x = prefix_eval(pref_exp);
    printf("\nThe Result is : %d\n", x);
}