#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 4
struct queue
{
    char data[size][30];
    int front,rear;
};
typedef struct queue Queue;
void insert(Queue *q, char *ele){
    if(q->rear==size-1){
        printf("Queue is full");
        return ;

    }
    q->rear+=1;
    strcpy(q->data[q->rear],ele);
    if(q->front==-1){
        q->front=0;
    }
}

void display(Queue q){
    if(q.rear==-1&&q.front==-1){
        printf("queue is empty");
        return ;
    }
    for (int  i = q.front; i<=q.rear; i++)
    {
        printf("%s\n",q.data[i]);

    }
    
}
char* delete(Queue *q){
    static char num[30]=" ";
    strcpy(num," ");
    if(q->front==-1&&q->rear==-1){
        printf("Queue is empty");
        return NULL;

    }
    strcpy(num,q->data[q->front]);
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    q->front=q->front+1;printf("Deleted element is %s\n",num);
    return num;
}
int main(){
Queue q;int ch;
q.front=q.rear=-1;
char cha[30];
while (1)
{
   


printf("1.I\t2.display\t3.delete\t4.exit\n");
scanf("%d",&ch);
switch (ch)
{
case 1:
    printf("Enter the character ");
    scanf("%s",cha);
    insert(&q,cha);

    break;
case 2:
    display(q);
    break;
case 3:
    delete(&q);
    

    break;
case 4:
    exit(0);
default:
printf("Invalid");
}
}
return 0;


}