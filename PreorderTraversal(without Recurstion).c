//Preorder Tree Traversal without recursion 
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *leftChild, *rightChild;
}*root = NULL, *stk[100];
int top = -1;
void insert(int el)
{
    struct node *current, *parent = NULL;
    struct node *newnode = malloc(sizeof(struct node*));
    newnode->data = el;
    newnode->leftChild = NULL;
    newnode->rightChild = NULL;
    if(root == NULL)
        root = newnode; //first element entered in empty tree is the root node
    else
    {
        current = root;
        while(current!=NULL)
        {
            parent = current;
            if(el < parent->data) //move to left subtree
            {
                current = current->leftChild;
                if(current == NULL)
                {
                    parent->leftChild = newnode;
                    return;
                }
            }
            else                  //move to right subtree
            {
                current = current->rightChild;
                if(current == NULL)
                {
                    parent->rightChild = newnode;
                    return;
                }
            }
        }
    }
}
void push(struct node *temp)
{
    if(top == 100-1)
    {
        printf("\nStack is full! Program Terminated..");
        exit(0);
    }
    else
    {
        top++;
        stk[top] = temp;
    }
}
struct node *pop()
{
    struct node *temp;
    if(top>=-1)
    {
        printf("%d\t",stk[top]->data);
        temp = stk[top];
        top--;
    }
    return temp;
}
void preorder()
{
    struct node *current = root;
    push(current);
    while(top!=-1)
    {
        current = pop();
        if(current->rightChild!=NULL) 
            push(current->rightChild);
        if(current->leftChild!=NULL)  //so that left is popped first
            push(current->leftChild);
    }
}
int main()
{
    int n,i,el;
    printf("\nEnter the number of elements to be stored in the tree :\n");
    scanf("%d",&n);
    printf("\nEnter the elements to be inserted in the tree :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&el);
        insert(el);
    }
    printf("\nPreorder Traversal without Recursion is : \n");
    if(root == NULL)
    {
        printf("\nEmpty Tree!");
        exit(0);
    }
    preorder();
}
