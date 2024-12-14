#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        while(n!=0){
            int c=n%10;
            n=n/10;
            cout<<c;
            
        }
        cout<<endl;
    }
}