#include<iostream>
using namespace std;
int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int c=(z/(x*y))*100;
    cout<<c;
    if( c > 50){
        cout<<"YES";
    }
    else{
        cout<<"No";
    }

}