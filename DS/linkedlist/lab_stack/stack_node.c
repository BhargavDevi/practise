#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *push(Node *list, int data)
{
    Node *newnode, *temp;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("Error in creating a node");
        return list;
    }
    newnode->data = data;
    newnode->next = NULL;
    temp = list;
    if (temp == NULL)
    {
        return newnode;
    }
    newnode->next = temp;
    printf("%d inserted\n", data);
    return newnode;
}
Node *delete(Node *list)
{
    Node *temp;
    temp = list;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return list;
    }
    list = list->next;
    printf("The element deleted is %d\n", temp->data);
    free(temp);
    return list;
}
Node *delete_last(Node *list)
{
    Node *temp, *prev=NULL;
    temp = list;
    if (list == NULL)
    {
        printf("empty\n");
        return list;
    }
    while (temp->next!= NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        printf("%d deleted\n",temp->data);
        free(temp);
        list=NULL;
        return list;
    }
    prev->next=NULL;
    printf("%d deleted\n", temp->data);
    free(temp);
    return list;
}
Node*position(Node*list,int data,int pos){
    Node *temp,*prev=NULL;
    temp=list;
    Node *newnode;
    newnode=(Node *)malloc(sizeof(Node));
    if (newnode==NULL)
    {
        printf("error in creating a node\n");
        return list;
    }
    newnode->data=data;
    newnode->next=NULL;
    int count=1;
    if (pos<=0)
    {
        printf("invalid position\n");
        return list;
    }
    while (temp->next!=NULL&&count<(pos-1) )
    {
        prev=temp;
        temp=temp->next;
    count++;
    }
    if (count<pos)
    {
        printf("invalid position\n");
        free(newnode);
        return list;
    }
    if (prev==1)
    {
        newnode->next=list;
        return newnode;
    }
    prev->next=newnode;
    newnode->next=temp;
    return list;
}
void display(Node *list)
{
    Node *temp;
    temp = list;
    if (temp == NULL)
    {
        printf("The list is emty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}
int main()
{
    int ele, choise,pos;
    Node *list = NULL;
    while (1)
    {
        printf("1.push\n2.display\n3.pop\n4.delete last\n5.position\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the element to push\n");
            scanf("%d", &ele);
            list = push(list, ele);
            break;
        case 2:
            display(list);
            break;
        case 3:
            list = delete (list);
            break;
        case 4:
            list = delete_last(list);
            break;
            case 5:
            printf("Enter the element to be inserted at a position \n");
            printf("Enter the element \n");
            scanf("%d",&ele);
            printf("Enter the position\n");
            scanf("%d",&pos);
            list=position(list,ele,pos);
        case 6:
            exit(0);
        default:
            printf("invalid choise\n");
            break;
        }
    }
}
