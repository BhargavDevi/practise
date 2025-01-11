#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *insert(Node *first, int data1)
{
    Node *newnode, *temp;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data1;
    newnode->next = NULL;
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("%d is been inserted ", data1);
    return (first);
}

Node *delete_first(Node *first)
{
    Node *temp;
    if (first == NULL)
    {
        printf("overflow");
    }
    else
    {

        temp = first;
        first = first->next;
        printf("%d is been deleted ", temp->data);
        free(temp);
    }
    return (first);
}void display(Node *first)
{
    Node *temp=first;
    if (temp == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
Node * insertpos(Node * list ,int ele,int pos){
    Node * temp,* newnode;
    int count =1;
    if(newnode==NULL){
        printf("issue in the memory allocation");
        return list;
    }
    newnode=(Node *)malloc(sizeof(Node));
    newnode->data=ele;
    newnode->next=NULL;
    if(pos==1){
        newnode->next=list;
        return newnode;
    }
    temp=list;
    while (temp!=NULL&&count<(pos-1))
    {    
         temp=temp->next;
         count++;
    }
    if(temp!=NULL){
        newnode->next=temp->next;
        temp->next=newnode;
        return list;
    }
    return list;
}
int main()
{
    Node *first = NULL;
    int choise, data,ele,pos;
    while (1)
    {
        printf("1.Insert\n2.delete_first\n3.display\n4.delete_end\n5.insertposition\n6.exit\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d", &data);
            first=insert(first, data);
            break;
        case 2:
            first=delete_first(first);
            break;
        case 3:
            display(first);
            break;
        
        case 5:
           printf("enter the element to insert and its position");
           scanf("%d %d",&ele,&pos);
           first=insertpos(first,ele,pos);
           break;
        case 6:
           exit (0);
        default:
            printf("invalid");
        }
        printf("Choise :");
    }
}