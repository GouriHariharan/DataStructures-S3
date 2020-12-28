/*Write a C program to insert a set of keys into a hash table of size m=13 using
the division method and the collision resolution technique as linear probing.*/
#include<stdio.h>
#include<stdlib.h>
#define N 13
int hash[13];
void display()
{
    printf("\nThe Hash Table contains :\n");
    for(int i = 0; i<N; i++)
    {
        if(hash[i]!=0)
            printf(" %d at index %d,",hash[i],i);
        else
        printf(" _,");
    }
}
void linearProbe(int keyVal, int el)   
{   
    int k = keyVal;
    do
    {
        keyVal = (keyVal+1)%N;    //collision resolution
        if(hash[keyVal] == 0)
        {
            hash[keyVal] = el;
            return;
        }
    }while(keyVal!=k); //probed all 13 positions
}
void generateKeyVal(int el)
{
    int keyVal = el%N;
    if(hash[keyVal]==0)
    {
        hash[keyVal] = el;    
    }
    else            //collision case
        linearProbe(keyVal,el);
}
int main()
{   
    int el,count = 0;
    char c = 'y';
    printf("\nGiven Hash Table of size %d",N);
    while(c =='y')
    {
        count+=1;   //can store upto 13 elements
        if(count > N)
        {
            printf("\nHash Table is full!");
            display();
            exit(0);
        }
        printf("\nEnter the element to be stored in the hash table:\n");
        scanf("%d",&el);
        generateKeyVal(el);
        printf("\nDo you want to continue storing elements?(y/n)");
        scanf(" %c",&c);
        if(c == 'n')
            display();
    }
    
}
