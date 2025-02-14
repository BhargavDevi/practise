#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *list(Node *list, int data)
{
    Node *temp, *newnode, *perv = NULL;
    temp = list;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("Error in creating a node\n");
        return list;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (list == NULL)
    {
        printf("%d has been inserted\n", data);
        return newnode;
    }
    while (temp->next != NULL && temp->data < data)
    {
        perv = temp;
        temp = temp->next;
    }
    if (perv == NULL)
    {
        newnode->next = temp;
        list=newnode;
    }
    else
    {
        perv->next = newnode;
        newnode->next = temp;
    }
    printf("%d has been inserted\n", data);
    return list;
}
int search(Node *list1, int sid)
{
    Node *temp;
    temp = list1;
    if (temp == NULL)
        return 0;
    while (temp->next != NULL && temp->data < sid){
    if (temp->data == sid)
        return 1;
        temp = temp->next;}
    if (temp == NULL)
        return 0;
    return 0;
}
void display(Node *list)
{
    Node *temp=list;
    if (list == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
    Node *unionLists(Node *l1, Node *l2) {
Node *l3 = NULL,
*temp;
temp = l1;
while (temp != NULL) {
if (search(l3, temp->data)==0)
l3 = list(l3, temp->data);
temp = temp->next;
}
temp = l2;
while (temp != NULL) {
if (search(l3, temp->data)==0)
l3 = list(l3, temp->data);
temp = temp->next;
}
return l3;
}

int main()
{
    Node *list1 = NULL, *list2 = NULL,*list3=NULL;
    int choise, data;

    while (1)
    {
        printf("1.insert list1\n2.insert list2\n3.union\n4.display\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("enter the list1 data\n");
            scanf("%d", &data);
            list1 = list(list1, data);
            break;
        case 2:
            printf("enter the list2 data\n");
            scanf("%d", &data);
            list2 = list(list2, data);
            break;
            case 3:
            list3=unionLists(list1,list2);
          break;
        case 4:
        printf("-------------------\n");
            display(list1);
        printf("-------------------\n");
            display(list2);
        printf("-------------------\n");
        printf("union:\n");
        display(list3);
            break;
        case 5:
            exit(0);
        default:
            printf("Element invalid\n");
            break;
        }
    }
}
