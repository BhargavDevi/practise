#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
struct node
{
    char ch;
    struct node *lptr,*rptr;
    
};
typedef struct node Tree;
Tree *create_node(char postfix[]){
    int sp=-1,i=0;
    Tree * stack[30];
     char c;
     Tree *newnode;
     while ((c=postfix[i++])!='\0')
     {
     newnode=(Tree*)malloc(sizeof(Tree));
     newnode->ch=c;
     newnode->lptr=newnode->rptr=NULL;
        if(isalnum(c)){
            stack[++sp]=newnode;
        }
        else{
            newnode->lptr=stack[sp--];
            newnode->rptr=stack[sp--];
            stack[++sp]=newnode;
        }
     }
     return (stack[sp--]);
}
float eval(Tree *root){
    float num;
    switch (root->ch)
    {
    case '+':
        return eval(root->lptr)+eval(root->rptr);
    case '-':
        return eval(root->lptr)- eval(root->rptr);
    case '*':
        return eval(root->lptr)* eval(root->rptr);
    case '/':
        return eval(root->lptr)/ eval(root->rptr);
    case '^':
        return pow(eval(root->lptr), eval(root->rptr));
    default:
        if(isalpha(root->ch)){
            printf("Enter the value of %c\n",root->ch);
            scanf("%f",&num);
            return num;

        }
        else{
            return (root->ch-'0');
        }
    }
}
int main(){
    float res;
    char postfix[30];
    Tree *root=NULL;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    root=create_node(postfix);
    res=eval(root);
    printf("The result is %f",res);
    return 0;
}
