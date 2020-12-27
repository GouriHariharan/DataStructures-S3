/*Write a C program to insert a set of keys into a hash table of size m=13 using
the division method and the collision resolution technique as linear probing.*/
#include<stdio.h>
#include<stdlib.h>
#define N 13
int hash[13];
void display()
{
    printf("\nThe Hash Table contains :");
    for(int i = 0; i<N; i++)
    {
        if(hash[i]!=0)
            printf("\n%d at index %d",hash[i],i);
    }
}
void linearProbe(int key, int el)   
{   
    int k = key;
    do
    {
        key = (key+1)%N;    //collision resolution
        if(hash[key] == 0)
        {
            hash[key] = el;
            return;
        }
    }while(key!=k); //probed all 13 positions
}
void generateKey(int el)
{
    int key = el%N;
    if(hash[key]==0)
    {
        hash[key] = el;    
    }
    else            //collision case
        linearProbe(key,el);
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
        generateKey(el);
        printf("\nDo you want to continue storing elements?(y/n)");
        scanf(" %c",&c);
        if(c == 'n')
            display();
    }
    
}