#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[50];
    int id, pr, qu;
    struct node *next;
    /* data */
};
typedef struct node Node;
Node *insertEnd(Node *h, int id, int pr, int qu, char *na)
{
    Node *temp = h->next, *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("allocation error");
        return h;
    }
    newnode->id = id;
    newnode->pr = pr;
    newnode->qu = qu;
    strcpy(newnode->name, na);
    newnode->next = NULL;
    h->id++;
    if (temp == NULL)
    {
        newnode->next = newnode;
        h->next = newnode;
        return newnode;
    }
    while (temp->next != h->next)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = h->next;
    return h;
}
Node *insertFirst(Node *h, int id, int pr, int qu, char *name)
{
    Node *newnode, *temp = h->next;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("allocation error");
        return h;
    }
    newnode->id = id;
    newnode->pr = pr;
    newnode->qu = qu;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    h->id++;
    if (temp == NULL)
    {
        newnode->next = newnode;
        h->next = newnode;
        return newnode;
    }
    while (temp->next != h->next)
        temp = temp->next;

    newnode->next = h->next;
    h->next = newnode;
    temp->next = newnode;
    return h;
}
Node *deleteN(Node *h, int pos)
{
    Node *temp, *prev = NULL, *t1 = NULL;
    temp = h->next;
    if (pos < 1 || pos > h->id)
    {
        printf("invalid position");
        return h;
    }
    for (int i = 1; i < pos; i++)
    {
        prev = temp;
        prev = temp->next;
    }
    h->id--;
    if (prev == NULL)
    {
        while (t1->next != h->next)
        {
            t1 = t1->next;
            /* code */
        }
        t1->next = temp->next;
        h->next = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    printf("   ID:%d \n Prise:%d\n. Quantity:%d \n name of the product :%s. are DELETED \n", temp->id, temp->pr, temp->qu, temp->name);
    free(temp);
    return h;
}

void display(Node *h){
    Node* temp=h->next;
    if(temp==NULL){
        printf("list is empty");
        return ;
    }
    do
    {
    printf("ID:%d \n Prise:%d\n. Quantity:%d \n name of the product :%s \n", temp->id, temp->pr, temp->qu, temp->name);
        temp=temp->next;
    }
    while (temp!=h->next);
    }
int main()
{
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    int choise, id, pr, qu,pos;
    char name[50];
    if(head==NULL){
        printf("Allocatio error");
        return 0;
    }
    head->id=0;
    head->next=NULL;
    while (1)
    {
        printf("1.insert at end\n 2.insert at first\n3.delete at position \n4.display\n 5. exit\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("element to insert ID  Prise. Quantity. name of the product ");
            scanf("%d %d %d %s", &id, &pr, &qu, name);
            head=insertEnd(head, id, pr, qu, name);
            break;
            /* code */
        case 2:
            printf("element to insert ID  Prise. Quantity. name of the product ");
            scanf("%d %d %d %s", &id, &pr, &qu, name);
            head=insertFirst(head, id, pr, qu, name);
            break;
        case 3:
            printf("enter the position");
            scanf("%d",&pos);
             head=deleteN(head,pos);
             break;
        case 4:
            display(head);break;
        case 5:exit(0);
        default:
            printf("INVALID");
        }
        /* code */
    }
}