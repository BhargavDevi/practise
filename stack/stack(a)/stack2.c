#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#define size 20
struct stack{
    char data[size][size];
    int sp;

};
typedef struct stack st;
void init (st *st){
    st->sp=-1;
}

void push(st *st,char str[])
{
    if (st->sp==size-1){
        printf("stack is full");
        return;
    }
    st->sp+=1;
    strcpy(st->data[st->sp],str);
    // st->data[st->sp]=a; 
    printf("stack has entered the string %s",str);

    
}
void display(st st){
    if (st.sp==-1){
        printf("stack is full");
        return;
    }
    // int temp;
    for(int i=st.sp;i>=0;i--){
        printf("%s",st.data[st.sp]);
    }
}


int main (){
    st s;
    char a[20];

    init(&s);
    printf("enter the name ");
    scanf("\n%s",a);
    push(&s,a);
    display(s);



}