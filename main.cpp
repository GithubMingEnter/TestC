#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp;
    temp=a; 
    a=b;
    b=temp;
}

int main(){
    int a=2, b=3;
    cout<<"a="<<&a<<"  b="<<&b<<endl;
    swap(a,b);
    cout<<"a="<<&a<<"  b="<<&b<<endl;//只是将值交换了，但是其地址没有改变
    cout<<"test"<<endl;
    cout<<"git"<<endl;
    
    getchar();
    return 0;
}