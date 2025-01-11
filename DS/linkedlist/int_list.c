#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
Node *insert(Node *first, int data1)
{
    Node *newnode, *temp;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data1;
    newnode->next = NULL;
    if (first == NULL)
    {
        first = newnode;
    }
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("%d is been inserted ", data1);
    return (first);
}

Node *delete_first(Node *first)
{
    Node *temp;
    if (first == NULL)
    {
        printf("overflow");
    }
    else
    {

        temp = first;
        first = first->next;
        printf("%d is been deleted ", temp->data);
        free(temp);
    }
    return (first);
}
// Node * delete_end(Node * first ){
// Node *temp=first,*del;
// if (temp==NULL){
//     printf("empty");
// }
// else{
//     while (temp->next!=NULL)
//     {
//         temp=temp->next;
//     }
//     del=temp->next;
//     printf("Deleted data is %d",del->data);
//     free(del);
    
// }
// return first;
// }
void display(Node *first)
{
    Node *temp=first;
    if (temp == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
int main()
{
    Node *first = NULL;
    int choise, data;
    while (1)
    {
        printf("1.Insert\n2.delete_first\n3.display\n4.delete_end\n5.exit\n");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the data to be inserted\n");
            scanf("%d", &data);
            first=insert(first, data);
            break;
        case 2:
            first=delete_first(first);
            break;
        case 3:
            display(first);
            break;
            case 4:
            first=delete_end(first);
            break;
        case 5:
            exit(0);

        default:
            printf("invalid");
        }
        printf("Choise :");
    }
}