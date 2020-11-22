/* Write a C program to enter two matrices in normal (conventional) form. 
Write a function to convert two matrices to tuple form and display it. 
Find the product of the two matrices in tuple form and display the product in tuple form*/
#include<stdio.h>
struct tuple{
    int row;
    int col;
    int value;
};
int sparse_to_tuple(int a[][100],int r,int c, struct tuple t[], int num)
{
    int i,j,k=1;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]!=0)
            {
                t[k].row = i;
                t[k].col = j;
                t[k].value = a[i][j];
                k++;
            }
    t[0].row = r;
    t[0].col = c;
    t[0].value = k-1;
    printf("\nThe Matrix %d in Tuple form is :\n",num);
    printf("Row\tCol\tValue\n");
    for(i=0;i<k;i++)
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].value);
    return k;
}
void sparse_multiply(struct tuple t1[],struct tuple t2[], struct tuple x[], int k1, int k2, int p,int q) //t1*t2
{   int i,j,n=1,k=1;
    struct tuple t3[100];
    x[0].row = t1[0].row;
    x[0].col = t2[0].col;
    for(i=1;i<k1;i++)
        for(j=1;j<k2;j++)
        {
            if(t1[i].col == t2[j].row)
            {
                t3[k].row = t1[i].row;                
                t3[k].col = t2[j].col;
                t3[k].value = t1[i].value * t2[j].value;
                k++;
            }
        }
        for(i=1;i<k;i++)
         {   int flag = 0;
            for(j=1;j<n;j++)
            {
                if(t3[i].row == x[j].row && t3[i].col == x[j].col)
                {
                    x[j].value += t3[i].value;
                    flag=1;
                }
            }
            if(flag == 0)
            {
                x[n].row = t3[i].row;
                x[n].col = t3[i].col;
                x[n].value = t3[i].value;
                n++;
            }
        }
        x[0].value = n-1;
        printf("\nThe Product of the matrices in tuple form is : \n");
        printf("Row\tCol\tValue\n");
        int a;
        printf("%d\t%d\t%d\n",x[0].row,x[0].col,x[0].value);
        for(i=0;i<p;i++)
            for(j=0;j<q;++j)
                for(a=1;a<n;a++)
                {
                    if(x[a].row == i && x[a].col == j)
                        printf("%d\t%d\t%d\n",x[a].row,x[a].col,x[a].value);    
                }
}
int main()
{   int i,j,s1[100][100],s2[100][100],row_1,col_1,row_2,col_2,k1,k2;
    struct tuple t1[100], t2[100], x[100];
    printf("\nEnter the number of rows and columns of matrix 1:\n"); 
    scanf("%d %d",&row_1,&col_1);
    printf("\nEnter the number of rows and columns of matrix 2:\n"); 
    scanf("%d %d",&row_2,&col_2);
    if (col_1 != row_2)
    {
        printf("\nMultiplication not possible if columns of matrix 1 and rows of matrix 2 dont match");
    }
    else
    {
    printf("\nEnter the first sparse matrix : \n");
    for(i=0;i<row_1;i++)
        for(j=0;j<col_1;j++)
            scanf("%d",&s1[i][j]);
    printf("\nEnter the second sparse matrix : \n");
    for(i=0;i<row_2;i++)
        for(j=0;j<col_2;j++)
            scanf("%d",&s2[i][j]);
    k1 = sparse_to_tuple(s1,row_1,col_1,t1,1);
    k2 = sparse_to_tuple(s2,row_2,col_2,t2,2);
    sparse_multiply(t1,t2,x,k1,k2,row_1,col_2);
    }   
}