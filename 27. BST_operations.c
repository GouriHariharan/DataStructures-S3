/*Menu driven program to implement a binary search tree and to perform operations
i) Insertion
ii) Deletion
iii) Searching*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *leftChild, *rightChild;
};
struct node* root = NULL;
void insert(int el)
{
    struct node* current;
    struct node* parent;
    struct node* temp = malloc(sizeof(struct node));
    temp->data = el;
    temp->leftChild = NULL;
    temp->rightChild = NULL;
    if(root == NULL)
        root = temp;
    else
    {
        current = root;
        parent = NULL;
        while(current != NULL)
        {
            parent = current;
            if(el<parent->data)
            {
                current = current->leftChild;
                if(current == NULL)
                {
                    parent->leftChild = temp;
                    return;
                }
            }
            else
            {
                current = current->rightChild;
                if(current == NULL)
                {
                    parent->rightChild = temp;
                    return;
                }
            }
        }
    }
}
struct node* search(int e)
{
    struct node *pos = root;
    while(pos->data != e)
    {
        if(pos != NULL)
        {
            if(pos->data > e)
                pos = pos->leftChild;
            else
                pos = pos->rightChild;
            if(pos == NULL)
                return NULL;
        }
    }
    return pos;
}
struct node* getMin(struct node *root)
{
    while(root->leftChild != NULL)
        root = root->leftChild;
    return root;
}
struct node* delete(struct node* root, int e)
{
    if(root == NULL)
        return root;
    else if(e < root->data)
        root->leftChild = delete(root->leftChild,e);
    else if(e > root->data)
        root->rightChild = delete(root->rightChild,e);
    else
    {
        if(root->leftChild == NULL && root->rightChild == NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root->leftChild == NULL)
        {
            struct node *temp = root;
            root = root->rightChild;
            free(temp);
        }
        else if(root->rightChild == NULL)
        {
            struct node *temp = root;
            root = root->leftChild;
            free(temp);
        }
        else
        {
            struct node *temp = getMin(root->rightChild);
            root->data = temp->data;
            root->rightChild = delete(root->rightChild, temp->data);
        }
    }
    return root;
}
void inorder(struct node* root)     //LDR
{
    if(root == NULL)
        return;
    inorder(root->leftChild);
    printf("%d ",root->data);
    inorder(root->rightChild);    
}
int main()
{
    int i,el,c,e;
    struct node* temp = NULL;
    do
    {
        printf("\nBINARY SEARCH TREE OPERATIONS MENU");
        printf("\n---------------------------------");
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("\nEnter the element of tree: ");
                     scanf("%d",&el);
                     insert(el);
                     if(root == NULL)
                        printf("\nThe Tree is empty!");
                     else
                     {
                        printf("\nThe binary search tree displayed inorder is :\n");
                        inorder(root);
                        printf("\n");
                     }
                     break;
            case 2 : if(root == NULL)
                     {
                         printf("\nEmpty tree! Cannot perform deletion\n");
                         break;
                     }
                     printf("\nEnter the element to be deleted: ");
                     scanf("%d",&e);
                     root = delete(root,e);
                     if(root!=NULL)
                     {
                         printf("\nThe binary search tree after deletion is :\n");
                         inorder(root);
                         printf("\n");
                     }
                     else
                        printf("\nEmpty tree after deletion\n");
                     break;
            case 3 : if(root == NULL)
                     {
                         printf("\nEmpty tree! Cannot search\n");
                         break;
                     }
                     printf("\nEnter the element to be searched for :");
                     scanf("%d",&e);
                     temp = search(e);
                     if(temp!=NULL)
                        printf("\nThe element is found in binary search tree\n");
                     else
                        printf("\nThe element is not present in the binary search tree\n");
                     break; 
            case 4 : printf("\nExiting...\n");
                     break;
            default: printf("\nPlease Try Again\n");
        }
    }while(c!=4);
}