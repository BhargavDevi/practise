#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lptr, *rptr;
};
typedef struct node Node;
Node *create_node(Node *root, int info)
{
    Node *newnode, *x, *parent=NULL;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->lptr = newnode->rptr = NULL;
    newnode->data = info;
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        x = root;
        while (x != NULL)
        {
            parent = x;
            if (x->data < info)
            {
                x = x->rptr;
            }
            else if (x->data > info)
            {
                x = x->lptr;
            }
            else
            {
                printf("Node alreaady exist");
                free(newnode);
                return root;
            }
          
    }
        
            if (parent->data < info)
            {
                parent->rptr=newnode;
            }
            else
            {
                parent->lptr=newnode;
            }
    }
    printf("%d has been inserted \n", info);
    return root;
}
void inorder(Node *root)
{
    
    if (root != NULL)
    {
        inorder(root->lptr);
        printf("%d \n", root->data);
        inorder(root->rptr);
    }
}
void preorder(Node *root)
{
    
    if (root != NULL)
    {
        printf("%d \n", root->data);
        inorder(root->lptr);
        inorder(root->rptr);
    }
}
void postorder(Node *root)
{
    
    if (root != NULL)
    {
        inorder(root->lptr);
        inorder(root->rptr);
        printf("%d \n", root->data);
    }
}
Node * delete_node(Node *root,int key){
    Node *curr,*q,*success,*parent=NULL;
    if (root==NULL)
    {
        printf("the root is empty");
        return root;
    }
    curr=root;
    while (curr!=NULL)
    {
        if(curr->data==key)
           break;
        parent=curr;
        curr=(key<curr->data)?curr->lptr:curr->rptr;
    }
    if(curr==NULL){
        printf("the node was not found");
        return root;
    }
    if (curr->lptr==NULL)
    {
        q=curr->rptr;
    }
    else if (curr->rptr==NULL)
    {
        q=curr->lptr;
    }
    else{
        success=curr->rptr;
        while (success->lptr!=NULL)
        {
            success=success->lptr;
        }
        success->lptr=curr->lptr;
        q=curr->rptr;
    }
    if (parent==NULL)
    {
        return q;
    }
    else if(parent->lptr==curr)
        parent->lptr=q;
    else
        parent->rptr=q;
    printf("The element deleted is %d\n",curr->data);
    free(curr);
    return root;
}
int main()
{
    Node *root = NULL;
    int data, choise,key;
    while (1)
    {
        printf("1.insert the data \n2.inorder display\n3.preorder\n4.postorder\n5.delete data\n6.exit");
        printf("Enter your choise\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d",&data);
            root = create_node(root, data);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Enter the element to be deleted");
            scanf("%d",&key);
            root=delete_node(root,key);
            break;
        case 6:
            exit(0);
        default:
            printf("non d the choise is present \n");
            break;
        }
    }
    return 0;
}