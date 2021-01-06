//Merge Sort 
#include<stdio.h>
void merge(int a[100],int lb, int mid, int ub)
{
    int k=0, l=lb, u=mid+1;
    int b[100];
    int n = ub-lb+1;
    while(l<mid+1 && u<ub+1)  //merging sublists
    {
        if(a[l]<a[u])
        {
            b[k] = a[l];
            l++;
            k++;
        }
        else
        {
            b[k] = a[u];
            k++;
            u++;
        }
    }
    while(l<mid+1)   //if elements in 1st sublist > 2nd sublist
    {               //we need to add these remaining elements into b[]
        b[k] = a[l];
        l++;
        k++;
    }
    while(u<ub+1)   //if elements in 2nd sublist < 1st sublist
    {              //we need to add these remaining elements into b[]
        b[k] = a[u];
        u++;
        k++;
    }
    l = lb;
    for(k=0; k<n; k++)  //copying sorted b[] into a[]
    {
        a[l] = b[k];
        l++;
    }
}
void mergeSort(int a[100],int lb,int ub)
{
    if(lb==ub)
        return;
    else
    {
        int mid = (ub+lb)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
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
    mergeSort(a,0,n-1);
    printf("\nThe Array Sorted in Ascending order using Merge Sort is :\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}