/*Write a C program to enter two matrices in normal (conventional) form. 
Write a function to convert two matrices to tuple form and display it.  
Find the sum of the two matrices in tuple form and display the sum in tuple form*/
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
void sparse_sum(struct tuple t1[], struct tuple t2[], int k1, int k2, struct tuple t3[])
{
    int k3;
    int i, m=1, n=1, k=1; //m,n are t1 and t2 indices respectively
    t3[0].row = t1[0].row;  //same as t2[0].row
    t3[0].col = t1[0].col;  //same as t2[0].col
    while(m<k1 && n<k2)
    {
        if((t1[m].row == t2[n].row)&&(t1[m].col == t2[n].col))
        {
            t3[k].row = t1[m].row;
            t3[k].col = t1[m].col;
            t3[k].value = t1[m].value + t2[n].value;
            k++;
            m++;
            n++;
        }
        else if(t1[m].row == t2[n].row)
        {
            if(t1[m].col < t2[n].col)
            {
                t3[k].row = t1[m].row;
                t3[k].col = t1[m].col;
                t3[k].value = t1[m].value;
                k++;
                m++;
            }
            else
            {
                t3[k].row = t2[n].row;
                t3[k].col = t2[n].col;
                t3[k].value = t2[n].value;
                k++;
                n++;    
            }
        }
        else if(t1[m].row < t2[n].row)
        {
            t3[k].row = t1[m].row;
            t3[k].col = t1[m].col;
            t3[k].value = t1[m].value;
            k++;
            m++;     
        }
        else if(t1[m].row > t2[n].row)
        {
            t3[k].row = t2[n].row;
            t3[k].col = t2[n].col;
            t3[k].value = t2[n].value;
            k++;
            n++;     
        }
    }
    if(m == k1)     //for larger number of non-zero elements in t2
        for(i=n;i<k2;i++)
        {
            t3[k].row=t2[n].row;
            t3[k].col = t2[n].col;
            t3[k].value = t2[n].value;
            n++;
            k++;
        }
    else if(n == k2)    //for larger number of non-zero elements in t1
        for(i=m;i<k1;i++)
        {
            t3[k].row = t1[m].row;
            t3[k].col = t1[m].col;
            t3[k].value = t1[m].value;    
            m++;
            k++;
        }
    t3[0].value = k-1;
    printf("\nThe Sum of the Matrices is :\n");
    printf("Row\tCol\tValue\n");
    for(i=0;i<k;i++)
    printf("%d\t%d\t%d\n",t3[i].row,t3[i].col,t3[i].value);
}
int main()
{   int i,j,s1[100][100],s2[100][100],row_s,col_s,k1,k2;
    struct tuple t1[100], t2[100], sum[100];
    printf("\nEnter the number of rows and column :\n"); //matices of same size
    printf("(For addition both matrices must be of same size)\n");
    scanf("%d %d",&row_s,&col_s);
    printf("\nEnter the first sparse matrix : \n");
    for(i=0;i<row_s;i++)
        for(j=0;j<col_s;j++)
            scanf("%d",&s1[i][j]);
    printf("\nEnter the second sparse matrix : \n");
    for(i=0;i<row_s;i++)
        for(j=0;j<col_s;j++)
            scanf("%d",&s2[i][j]);
    k1 = sparse_to_tuple(s1,row_s,col_s,t1,1);
    k2 = sparse_to_tuple(s2,row_s,col_s,t2,2);
    sparse_sum(t1,t2,k1,k2,sum);
        
}
