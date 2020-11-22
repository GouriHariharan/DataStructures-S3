/*WAP in C to enter a matrix in normal(Conventional )form.Write a function to convert
the matrix to tuple form and display it.Also find the transpose of the matrix represented
in tuple form and display the transpose in tuple and normal form */
#include<stdio.h>
struct tuple{
    int row;
    int col;
    int value;
};
int sparse_to_tuple(int s[][100], int r, int c, struct tuple t[])
{
    int i,j,k=1;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(s[i][j]!=0)
            {
                t[k].row = i;
                t[k].col = j;
                t[k].value = s[i][j];
                k++;
            }
    t[0].row = r;
    t[0].col = c;
    t[0].value = k-1;
    printf("Row\tCol\tValue\n");
    for(i=0;i<k;i++)
        printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].value);
    printf("\n");
    return k;
}
void tuple_transpose(struct tuple t[100],int k)
{
    struct tuple tt[100];
    for(int i=0;i<k;i++)
    {
        tt[i].row = t[i].col;
        tt[i].col = t[i].row;
        tt[i].value = t[i].value;
    }
    printf("\nThe Transpose in Tuple form is : \n"); //matrix indexing starts at [0,0]
    printf("Row\tCol\tValue\n");
    for(int i=0;i<k;i++)
        printf("%d\t%d\t%d\n",tt[i].row,tt[i].col,tt[i].value);
    printf("\n");
}
int main()
{   struct tuple t[100],u[100];
    int row_s, col_s, i, j, k, l, s[100][100],p[100][100];
    printf("\nEnter the number of rows and columns : \n");
    scanf("%d %d",&row_s,&col_s);
    printf("\nEnter the matrix (sparse) : \n");
    for(i=0;i<row_s;i++)
        for(j=0;j<col_s;j++)
            scanf("%d",&s[i][j]);
    printf("\nThe sparse matrix in conventional form is : \n");
    for(i=0;i<row_s;i++)
    {
        for(j=0;j<col_s;j++)
            printf("%d ",s[i][j]);
        printf("\n");
    }
    printf("\nThe Tuple form of matrix is : \n"); //matrix indexing starts at [0,0]
    k = sparse_to_tuple(s,row_s,col_s,t);
    tuple_transpose(t,k);
    for(i=0;i<col_s;i++)
        for(j=0;j<row_s;j++)
            p[i][j] = 0;
    int a;
    for(a=1;a<k;a++)
    {
        for(i=0;i<col_s;i++)
            for(j=0;j<row_s;j++)
                if(t[a].col==i && t[a].row==j)
                    p[i][j]=t[a].value;
    }
    printf("\nThe Transpose in conventional form is :\n");
    for(i=0;i<col_s;i++)
    {
        for(j=0;j<row_s;j++)
            printf("%d ",p[i][j]);
        printf("\n");
    } 
    printf("\nTranspose in tuple form in order of positions :\n");
    l = sparse_to_tuple(p,col_s,row_s,u);
}