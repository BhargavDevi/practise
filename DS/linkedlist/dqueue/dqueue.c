#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lptr, *rptr;
};
typedef struct node Node;
Node *f = NULL, *r = NULL;
void insert_left(int data)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->lptr = NULL;
    newnode->data = data;
    if (f == NULL)
    {
        newnode->rptr = NULL;
        f = r = newnode;
    }
    newnode->rptr = f;
    f->lptr = newnode;
    f = newnode;
    printf("%d has been inserted ", f->data);
}
void insert_right(int data)
{
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->rptr = NULL;
    if (r == NULL)
    {
        newnode->lptr = NULL;
        r = f = newnode;
    }
    newnode->lptr = r;
    r->rptr = newnode;
    r = newnode;
    printf("%d has been inserted ", r->data);
}
void rm_left()
{
    Node *temp;
    temp = f;
    if (f == NULL)
    {
        printf("empty");
        return;
    }
    if (f == r){
        f=r=NULL;
    }
    else{
        f = f->rptr;
    f->lptr = NULL;
    }
    printf("Element deleted is %d\n", temp->data);
    free(temp);
}

void rm_right()
{
    Node *temp;
    temp = r;
    if (r == NULL)
    {
        printf("empty");
        return;
        /* code */
    }

    if (r == f)
        f = r = NULL;
    else{
    r = r->lptr;
    r->rptr = NULL;
        }
            printf("The element deleted is %d\n", temp->data);
    free(temp);
}
int main()
{
    Node *list = NULL;
    int choise, ele;
    while (1)
    {
        printf("1.insert at left\n2.insert at right\n3.remove_left\n4.remove_right\n5.exit\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("enter the first number\n");
            scanf("%d", &ele);
            insert_left(ele);
            break;
        case 2:
            printf("enter the first number\n");
            scanf("%d", &ele);
            insert_right(ele);
            break;
        case 3:
            rm_left();
            break;
        case 4:
            rm_right();
            break;
        case 5:
            exit(0);

        default:
        printf("invalid");
            break;
        }
    }
    return 0;
}