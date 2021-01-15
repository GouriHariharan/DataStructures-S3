/*menu driven program to implement a binary search tree and
to perform Traversing – inorder, preorder, & postorder*/
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
struct node* preorder(struct node* root)    //DLR
{
    if(root == NULL)
        return root;
    printf("%d ",root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}
struct node* inorder(struct node* root)     //LDR
{
    if(root == NULL)
            return root;
    inorder(root->leftChild);
    printf("%d ",root->data);
    inorder(root->rightChild);    
}
struct node* postorder(struct node* root)   //LRD
{
    if(root == NULL)
            return root;
    postorder(root->leftChild);
    postorder(root->rightChild);  
    printf("%d ",root->data);
}
int main()
{
    int i,n,el,c;
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    printf("\nEnter the elements of the tree : \n");
    for(i=0;i<n;++i)
    {
        scanf("%d",&el);
        insert(el);
    }
    do
    {
        printf("\nBINARY SEARCH TREE TRAVERSAL MENU");
        printf("\n---------------------------------");
        printf("\n1. Preorder Traversal(DLR)\n2. Inorder Traversal(LDR)\n3. Postorder Traversal(LRD)\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("\nPreorder Traversal (DLR) : ");
                     preorder(root);
                     printf("\n");
                     break;
            case 2 : printf("\nInorder Traversal (LDR) : ");
                     inorder(root);
                     printf("\n");
                     break;
            case 3 : printf("\nPostorder Traversal (LRD) : ");
                     postorder(root);
                     printf("\n");
                     break;
            case 4 : printf("\nExiting...");
                     break;
            default: printf("\nPlease Try Again");
                     printf("\n");
        }
    }while(c!=4);
}