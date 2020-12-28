/*Given a natural language text, store each words in a hash table of size m=26 using 
the mod function. Find the number of key comparisons for a 
successful search, if the collision resolution technique used is 
1) linear probing 2) Quadratic probing*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define m 26
char h1[m][50],h2[m][50];
void display(char h[][50])
{
    for(int i=0;i<26;i++)
    {
        if(h[i][0] == '0')
            printf(" _,");
        else
            printf(" %s at index %d,",h[i],i);
    }
}
void hash1(char s[50])  
{
    int hash = (toupper(s[0]) % m); //hash function
    if(h1[hash][0] != '0')          //linear probing
    {
        do{
            hash = (hash+1)%m;
        }while(h1[hash][0]!='0');
    }
    strcpy(h1[hash],s);
}
void hash2(char s[50])
{
    int hash = (toupper(s[0]) % m);
    if(h2[hash][0] !='0')
    {   int i = 1;
        do{
            hash = (hash+(i*i))%m;
            i+=1;
        }while(h2[hash][0]!='0');
    }
    strcpy(h2[hash],s);
}
void searchLinear(char w[50])
{
    printf("\nIn Hash table using Linear Probing : \n");
    int count = 1;
    int hash = (toupper(w[0]) % m);
    while(strcmp(h1[hash],w) != 0)
    {
        hash = (hash+1)%m;   
        count++;
        if(count>m)
        {
            printf("\nWord not found\n");
            return;
        }
    }
    printf("\nWord %s found at index %d",w,hash);
    printf("\nNumber of key comparisons :%d",count);
}
void searchQuad(char w[50])
{
    printf("\nIn Hash table using Quadratic Probing : \n");
    int count = 1;
    int hash = (toupper(w[0]) % m);
    int i = 1;
    while(strcmp(h2[hash],w) != 0)
    {
        hash = (hash+(i*i))%m;
        i+=1;   
        count+=1;
        if(count>m)
        {
            printf("\nWord not found\n");
            return;
        }
    }
    printf("\nWord %s found at index %d",w,hash);
    printf("\nNumber of key comparisons :%d",count);
}
int main()
{
    int i;
    for(i=0;i<m;i++)    //initializing char hash arrays with zeroes
    {
        h1[i][0] = '0';
        h2[i][0] = '0';
    }
    int n;
    char s[50],w[50]; 
    printf("\nEnter the number of words in the text(max 26 words) :");
    scanf("%d",&n);
    if(n>26)
    {
        printf("\nCannot store text with more than 26 words!");
        exit(0);
    }
    printf("\nEnter the natural language text\n");
    for(i=0;i<n;i++)
        {
            scanf("%s", s);
            hash1(s);
            hash2(s);
        }
    printf("\nHash Table using collision resolution as linear probing :\n");
    display(h1);
    printf("\nHash Table using collision resolution as quadratic probing :\n");
    display(h2);
    printf("\n\nEnter the word to be searched for : ");
    scanf("%s",w);
    searchLinear(w);
    searchQuad(w);
}