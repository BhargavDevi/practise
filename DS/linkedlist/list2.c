#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    /* data */
};
typedef struct node Node;
Node * insert(Node *first,int ele){
    Node* temp=first,*newnode;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=ele;
    newnode->next=NULL;
    if(first==NULL){
        return newnode;
    }
    
   while (temp->next!=NULL)
        temp=temp->next;
   temp->next=newnode; 
   
   printf("New element inserted is %d\n",ele);
   return first;
}
Node * delete_first(Node *first){
    Node *temp=first;
    if (temp==NULL)
    {
        printf("empty\n");
        return first;
        /* code */
    }
    first=first->next;
    printf("%d is deleted\n",temp->data);
    free(temp);
    return first;
}
void display(Node *first){
    Node *temp=first;
    if(first==NULL){
        printf("Empty\n");
        return ;
    }
    printf("Elements are :\n");
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    Node *first = NULL;
    int choise, data;
    while (1)
    {
        printf("1.Insert\n2.delete_first\n3.display\n4.exit\n");
        scanf("%d", &choise);
        printf("Choise :");
        switch (choise)
        {
        case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d", &data);
            first=insert(first,data);
            break;
        case 2:
            first=delete_first(first);
            break;
        case 3:
            display(first);
            break;
            case 4:
            exit(0);

        default:
            printf("invalid");
        }
    }
}