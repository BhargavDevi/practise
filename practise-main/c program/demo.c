#include <stdio.h>
int main(){
    int a[30],sixe,i;
    printf("Enter the size of the array ");
    scanf("%d",&sixe);
    printf("ENter the elements of array");
    for ( i = 0; i < sixe; i++)
    {
        /* code */
     scanf("%d",&a[i]);
    }
    for ( i = 0; i < sixe; i++)
    {
        /* code */
     printf("%d",a[i]);
    }

    return 0;
}