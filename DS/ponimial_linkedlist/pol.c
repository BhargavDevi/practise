#include <stdio.h>
#include <stdlib.h>
struct node
{
    int a, px, py, f;
    struct node *next;
};
typedef struct node Node;
int search(Node *p, int x, int y)
{
    Node *temp = p;
    while (temp != NULL)
    {
        if (temp->px == x && temp->py == y)
        {
            temp->f = 1;
            return temp->a;
        }
            temp = temp->next;
    }
        return 0;
}
Node *createEquation(Node *p, int a, int x, int y)
{
    Node *temp = p, *prev = NULL;
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL)
    {
        printf("there is issue in creating the node ");
        return p;
    }
    newnode->a = a;
    newnode->px = x;
    newnode->py = y;
    newnode->next = NULL;
    newnode->f = 0;
    if (p == NULL)
    {
        return newnode;
    }

    while (temp != NULL && temp->px > x)
    {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL)
    {
        newnode->next = p;
        return newnode;
    }
    prev->next = newnode;
    newnode->next = temp;
    return p;
}
Node *addEq(Node *p1, Node *p2)
{
    Node *temp, *add=NULL;
    int an = 0;
    temp = p1;
    while (temp != NULL)
    {
        an = search(p2, temp->px, temp->py);
        if (an != 0)
        {
            add = createEquation(add, (an + temp->a), temp->px, temp->py);
        }
        else
        {
            add = createEquation(add, temp->a, temp->px, temp->py);
        }
        temp = temp->next;
    }
    temp = p2;
    while (temp != NULL)
    {
        if (temp->f != 1)
        {
            add = createEquation(add, temp->a, temp->px, temp->py);
        }
        temp = temp->next;
    }
    return add;
}
void display(Node *p)
{
    Node *temp = p;
    if (temp == NULL)
    {
        printf("there is no elements in the list");
        /* code */ return;
    }

    while (temp != NULL)
    {
        printf("%d x^%d y^%d", temp->a, temp->px, temp->py);
        temp = temp->next;
        if (temp!= NULL)
        {
            printf(" + ");
            /* code */
        }
    }
    printf("\n");
}
int main()
{
    Node *p1=NULL, *p2=NULL, *p3=NULL;
    int a, x, y;
    while (1)
    {
        printf("Enter the coefficient :\n");
        scanf("%d",&a);
        if (a == 999)
        {
            break;
        }

        printf("Enter the power of x and y:\n");
        scanf("%d %d",&x,&y);
        p1 = createEquation(p1,a,x,y);
    }
    while (1)
    {
        printf("Enter the coefficient 2:\n");
        scanf("%d",&a);
        if (a == 999)
        {
            break;
        }

        printf("Enter the power of x and y:\n");
        scanf("%d %d",&x,&y);
        p2 = createEquation(p2,a,x,y);
        /* code */
    }
    p3=addEq(p1,p2);
    printf("the first equation :\n");
    display(p1);
    printf("the second equation :\n");
    display(p2);
    printf("P1+P2\n");
    display(p3);
}