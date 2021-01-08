//Heap Sort 
#include<stdio.h>
void swap(int a[100], int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void maxheapify(int a[100], int n, int i)
{
    int root = i;
    int leftChild = 2*i+1, rightChild = 2*i+2;
    if(leftChild<n && a[leftChild]>a[root])
        root = leftChild;
    if(rightChild<n && a[rightChild]>a[root])
        root = rightChild;
    if(root != i)
    {
        swap(a,root,i);
        maxheapify(a,n,root);
    }
}
void heapSort(int a[100],int n)
{
    int i,temp;
    for(i = n/2-1; i>=0; i--) //building heap with non-leaf elements
    {
        maxheapify(a,n,i);
    }
    //sorting the maxheap
    for(i = n-1; i>=0; i--)
    {
        swap(a,0,i); //index 0 holds root 
        maxheapify(a,i,0);
    }
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
    heapSort(a,n);
    printf("\nThe Array Sorted in Ascending order using Heap Sort is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}