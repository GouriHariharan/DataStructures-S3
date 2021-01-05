//Selection Sort
#include<stdio.h>
void selectionSort(int a[100],int n)
{
    int i,j,small,temp;
    for(i=0;i<n;i++)
    {
        small = i;
        for(j = i+1;j<n;j++)
            if(a[j]<a[small])
                small = j;   
        temp = a[i];
        a[i] = a[small];
        a[small] = temp;
    }
    printf("\nThe Array after Sorting in Ascending Order is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
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
    selectionSort(a,n);
}