#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    /* data */
};
typedef struct node Node;
Node *sorted(Node *list,int value){
    Node *temp,*newnode;
    Node *prev=NULL;
    temp=list;
    newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("Error in opening the file");
        return list;
    }
    newnode->data=value;
    newnode->next=NULL;
    while (temp!=NULL && temp->data<value)
    {
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL){
        newnode->next=list;
        return newnode;
    }
    prev->next=newnode;
    newnode->next=temp;
    return list;
}
 int search(Node *list,int sdata){
    Node *temp=list;
    while (temp!=NULL)
    {
    
    if(temp->data==sdata){
        return 1;
    }
    temp=temp->next;
    }
    return 0;
}
Node * unionlist(Node *l1,Node *l2 ){
     Node *temp,*ulist=NULL;
     temp=l1;
     while (temp!=NULL)
     {
        if (search(ulist,temp->data)==0)
        {
            ulist=sorted(ulist,temp->data);
        }
        temp=temp->next;
     }
     temp=l2;
     while (temp!=NULL)
     {if (search(ulist,temp->data)==0)
        {
            ulist=sorted(ulist,temp->data);
        }
        temp=temp->next;
     }
    return ulist;
}
Node *intersection(Node *l1,Node *l2){
     Node * temp,*inter=NULL;
     temp =l1;
     while (temp !=NULL)
     {
        if(search(l2,temp->data)==1){
            inter=sorted(inter,temp->data);
        }
        temp=temp->next;

        /* code */
     }
     return inter;
     
}
void display(Node *list){
    Node *temp=list;
    if (temp==NULL)
    {
        printf("no elements in the list");
        return ;
        /* code */
    }
    
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    
    }
}
int main(){
    Node *l1=NULL,*l2=NULL,*ul=NULL,*il=NULL;
    int val,choise,sval;
    while (1)
    {
        printf("1.insert \n 2.insert 2nd list \n 3.union \n 4.display\n 5. intersection\n6.exit\n");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
             printf("enter the number to insert in list 1");
             scanf ("%d",&val);
             l1=sorted(l1,val);
             break;
        case 2:
            printf("enter the second list");
            scanf("%d",&sval);
            l2=sorted(l2,sval);
            break;
        case 3:
            ul=unionlist(l1,l2);
            break;
        case 4:
            printf("liat 1:\n");
            display(l1);
            printf("liat 2:\n");
            display(l2);
            printf("union list:\n");
            display(ul);
            printf("intersection :\n");
            display(il);
            break;
        case 5:
           il=intersection(l1,l2);
           break;
        case 6:exit (0);
        default:
        printf("invalid choise");

        }
        /* code */
    }
    return 0;
}
