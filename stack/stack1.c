#include <stdio.h>
#include <stdbool.h>
#define size 100
struct Stack
{
    int data[size];
    int sp;
};
typedef struct Stack stack;
void init(stack *st)
{
    st->sp = -1;
}
void push(stack *st, int ele)
{

    if (st->sp == (size - 1))
    {
        printf("stack is full");
        return;
    }
    st->sp = st->sp + 1;

    st->data[st->sp] = ele;
    printf("pushed on to the stack %d \n", ele);
}
int pop(stack *st)
{

    if (st->sp == -1)
    {
        printf("stack is empty ");
        return -1;
    }

    return st->data[(st->sp)--];
}

void display(stack st)
{
    int s = 0;
    if (st.sp == -1)
    {
        printf("stack is empty");
        return;
    }
    s = st.data[st.sp];
    for (int i = st.sp; i >= 0; i--)
    {
        printf("%d \n", st.data[i]);
    }
    printf("\n");
}
int top(stack *st)
{
    return st->data[st->sp];
}

int main()
{
    stack st;
    init(&st);
    int choise, k, t;

    while (1)
    {
        printf("\nEnter the choise u want to select \n 1.push \n 2.pop.\n 3.display \n 4.exit  :");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enetr your element to be pushed into the stack ");
            scanf("%d", &k);
            push(&st, k);
            break;
        case 2:
            k = pop(&st);
            if (k != -1)
                printf("Element poped is %d", k);
            else
                printf("no element");
            break;
        case 3:
            display(st);
            break;
        case 4:
            t = top(&st);
            printf("stack top is %d", t);
            break;
        case 5:
            return 0;
        default:
            printf("invalid choise ");
        }
    }
    return 0;
}