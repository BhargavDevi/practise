#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 100
struct queue

{
    int data[size];
    int front, rear;
    /* data */
};
typedef struct queue qu;
void insert(qu *q, int ele)
{
    if ((q->front + 1) % size == q->rear)
    {
        printf("Queue is full");
        return;
    }
    q->front = ((q->front) + 1) % size;
    q->data[q->front] = ele;
    if (q->front == -1)
    {
        q->front = 0;
    }
    printf("inserted element is %d", ele);
}

void display(qu q)
{
    int i;
    if (q.front == -1)
    {
        printf("Queue is empty");
        return ;
    }
    for ( i = q.rear; i != q.front; i=(i + 1) % size)
    {
        printf("%d/n", q.data[i]);
    }    
    printf("%d\n",q.data[q.front]);
}
int main()
{
    qu q;
    int choise, ele;
    q.front = q.rear = -1;
    while (1)
    {
        printf("1.insert \n 2.display\n 3.exit \n");
        printf("enter the choise ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the element to be inserted ");
            scanf("%d", &ele);
            insert(&q, ele);
            break;
        case 2:
            display(q);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid");
        }
    }
     return 0;

}
