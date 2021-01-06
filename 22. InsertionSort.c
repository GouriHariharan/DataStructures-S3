//Insertion Sort
#include<stdio.h>
void insertionSort(int a[100],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = a[i];
        j = i-1;
        while(temp<a[j]&&j>=0)
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
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
    insertionSort(a,n);
}