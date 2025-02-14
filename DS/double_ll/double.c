#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
};
typedef struct node Node;
Node *last=NULL;
Node *insertlast(Node *h,int val){
    Node *newnode,*temp=last;
    newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Error in creating the node\n");
        return h;
    }
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(h->next==NULL){
        h->next=newnode;
        newnode->prev=h;
       last= newnode;
        h->data++;
        return h;
    }
    temp->next=newnode;
    newnode->prev=temp;
    last=newnode;
    h->data++;
    return h;
}
Node *insertV(Node*h,int val,int info){
    Node*temp=h->next;
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(h->next==NULL){
        printf("Position not found\n");
        free(newnode);
        return h;
    }
   while (temp!=NULL&&temp->data!=info)
   {
    temp=temp->next;
   }
   if(temp==NULL){
    printf("Element info not found\n");
    free(newnode);
    return h;
   }
   newnode->next=temp->next;
   newnode->prev=temp;
   if (temp->next!=NULL)
   {
    temp->next->prev=newnode;
   }
   temp->next=newnode;
   h->data++;
   if(temp==last)
  last= newnode;
   return h;
   
}
Node*delete_first(Node*h){
    Node *temp=h->next;
    if(h->next==NULL){
        printf("List is empty\n");
        return h;
    }
    printf("%d deleted\n",temp->data);
    h->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=h;
    free(temp);
    h->data--;
    return h;
}
Node *swap(Node *h,int n,int m){
    Node *temp;
    temp=h->next;
    if(h->next==NULL){
        printf("list is empty");
        return h;
    }
    if(n==m){
        printf("Need not swap the numbers\n");
        return h;
    }
    Node *np=NULL,*mp=NULL;
    while (temp!=NULL)
    {
        if(temp->data==n)
        np=temp;
        if(temp->data==m)
        mp=temp;
        temp=temp->next;
    }
    if(np==NULL||mp==NULL){
        printf("SWAP is not possible\n");
        return h;

    }
    int b=np->data;
    np->data=mp->data;
    mp->data=b;
    return h;
    
}
void display(Node *h){
    Node*temp=h->next;
    if(h->next==NULL){
        printf("Element not found\n");
        return;
    }
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    Node*h;
    h=(Node*)malloc(sizeof(Node));
    h->data=0;
    h->next=NULL;
    h->prev=NULL;
    int ele,choise,info,val,n,m;
    while (1)
    {
        printf("1.insert the element at last \n2.display\n3.insert at pos\n4.delete first\n5.swap\n");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
            printf("Enter the value to insert \n");
            scanf("%d",&ele);
            h=insertlast(h,ele);
            break;
        case 2:
          display(h);
          break;
          case 3:
          printf("Enter the info and value to put\n");
          scanf("%d %d",&info,&val);
        h=insertV(h,val,info);
        break;
        case 4:
        h=delete_first(h);
        break;
        case 5:
        printf("Enter the values to be swaped \n");
        scanf("%d%d",&n,&m);
        h=swap(h,n,m);
        break;
        default:
        printf("invalid");
            break;
        }
    }
    
}
