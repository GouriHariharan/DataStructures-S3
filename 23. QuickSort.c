//Quick Sort
#include<stdio.h>
int partition(int a[100], int lb, int ub)
{
    int temp,pivot = a[lb];
    int up = ub, down = lb;
    while(down<up)
    {
        while(a[down]<=pivot && down<ub)
            down++;
        while(a[up]>pivot)
            up--;
        if(down<up)
        {
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }
    a[lb] = a[up];
    a[up] = pivot;
    return up;
}
void quickSort(int a[100],int lb, int ub)
{
    int j;
    if(lb>=ub)
        return;
    j = partition(a,lb,ub);
    quickSort(a,lb,j-1);
    quickSort(a,j+1,ub);
    return;
}
int main()
{
    int a[100],n,i;
    printf("\nEnter the number of elements :\n");
    scanf("%d",&n);
    printf("\nEnter the array to be sorted :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nThe Array is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    quickSort(a,0,n-1);
    printf("\nThe Array Sorted in Ascending order using Quick Sort is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}