//One variable Polynomial addition using array
#include<stdio.h>
#include<stdlib.h>
struct polynomialTerm
{
    int coeff;
    int expo;
}p[100];
void isfull(int s)
{
    if(s>=100)
    {
        printf("Terms limit exceeded!");
                exit(1);
    }
}
void polynomialAddition(int x,int y,int m,int n,int begS)
{   
    int s=begS;
    while((x<=y) && (m<=n))
    {
        if(p[x].expo > p[m].expo)       //exponent of A>B
        {   
            isfull(s);
            p[s].coeff = p[x].coeff;
            p[s].expo = p[x].expo;
            x++;
            s++;
        }
        else if(p[x].expo < p[m].expo)  //exponent of A<B
        {
            isfull(s);
            p[s].coeff = p[m].coeff;
            p[s].expo = p[m].expo;
            m++;
            s++;
        }
        else                            //same exponents  
        {
            isfull(s);
            p[s].coeff = p[x].coeff + p[m].coeff;
            p[s].expo = p[x].expo;
            x++; m++;
            s++;       
        }
    }
    for(;x<=y;x++)
    {   isfull(s);
        p[s].coeff = p[x].coeff;
        p[s].expo = p[x].expo;
        s++;    
    }
    for(;m<=n;m++)
    {   isfull(s);
        p[s].coeff = p[m].coeff;
        p[s].expo = p[m].expo;
        s++;    
    }
    printf("\n\nThe Polynomial Sum (in variable x) is :\n");
    printf("%dx^%d",p[begS].coeff,p[begS].expo);
    for(int i=begS+1;i<s;i++)
        printf(" + %dx^%d",p[i].coeff,p[i].expo);
}
int main()
{   
    int begA, begB, endA, endB, begSum;
    int a,b,i,j,k;    //a,b are sizes of polynomials A,B
    printf("\nTerms of Polynomial must be in decreasing order \nof exponents and exclude terms with coefficient 0");
    printf("\nEnter the number of terms of first Polynomial(A): ");
    scanf("%d",&a);
    begA = 0;
    for(i=0;i<a;i++)
    {
        printf("\nEnter coefficient and exponent of term %d respectively :\n",i+1);
        scanf("%d %d",&p[i].coeff,&p[i].expo);
    }
    endA = i-1;
    printf("The first Polynomial is : %dx^%d",p[begA].coeff,p[begA].expo);
    for(k=begA+1;k<i;k++)
        printf(" + %dx^%d",p[k].coeff,p[k].expo);
    printf("\n\nEnter the number of terms of second Polynomial(B): ");
    scanf("%d",&b);
    begB = i;
    for(j=0;j<b;j++)
    {
        printf("\nEnter coefficient and exponent of term %d respectively :\n",j+1);
        scanf("%d %d",&p[i].coeff,&p[i].expo);
        i++;
    }
    printf("The second Polynomial is : %dx^%d",p[begB].coeff,p[begB].expo);
    for(k=begB+1;k<i;k++)
        printf(" + %dx^%d",p[k].coeff,p[k].expo);
    endB = i-1;
    begSum = i;
    polynomialAddition(begA,endA,begB,endB,begSum);
    
}