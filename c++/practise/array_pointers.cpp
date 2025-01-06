#include<iostream>
using namespace std;;
int  main(){
   int num[5],*ptr,sum=0;
cout<<"Enter the 5 array";
for (int  i = 0; i < 5; i++)
{
    cin>>num[i];
ptr=&num[0];
if(*ptr%2==0){
    sum=sum+*ptr;
    ptr++;
}
}
cout<<sum;

}