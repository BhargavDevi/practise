#include<stdio.h>
#include<stdlib.h>
#define size 5
struct queue
{
    int data[size];
    int front ,rear;
    
};
typedef struct queue Queue;

void insert(Queue *q,int ele){
    if(q->rear==size-1){
        printf("Queue is overflow");
        return;
    }
    q->rear=(q->rear+1)%size;
    q->data[q->rear]=ele;
    if(q->front==-1){
        q->front=0;
    }
    printf("element %d has been inserted\n",ele);

}
    int delete (Queue *q){

    int num=-1;
    if(q->rear==-1||q->front==-1){
        printf("underflow");
        return num;

    }
num=q->data[q->front];
if(q->front==q->rear){
      q->front=q->rear=-1;
}
else{
    q->front=(q->front+1)%size;
 
}

return num;
}
void display(Queue q) {
    if (q.front == -1) {
        printf("Queue is underflow\n");
        return;
    }

    printf("The elements in the queue are: ");
    for (int f = q.front; ; f = (f + 1) % size) {
        printf("%d ", q.data[f]);
        if (f == q.rear) {
            break; }
    }
    printf("\n");}
int main(){
    Queue qu;
    int choise,ele,d ;
    qu.rear=qu.front=-1;
    while(1){
        printf("1. insert \n 2.display\n 3.delete\n 4.exit\n ");
        scanf("%d",&choise);


  switch (choise)
    {
    case 1:
        printf("Enter the number to be inserted.  :");
        scanf("%d",&ele);
        insert(&qu,ele);
        break;
    case 2:
        display(qu);
        break;
        
    case 3:
        d=delete(&qu);
        printf("The element deleted is %d\n",d);
        break;

    case 4:
        exit(0);
    default:
        printf("invalid");
    }
}}

