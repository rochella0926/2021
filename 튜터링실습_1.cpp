#include <iostream>
using namespace std;

int main(){
    int *ptr;
    int a[5]={1,2,3,4,5};
    int b[2][5]={{1,2,3,4,5},{100,2,3,4,5}};
    
    ptr=a;
    
   cout<<(ptr+1)<<endl;//a[1]의 주소값
    
    cout<<*(ptr+2)<<endl;//a[2]의 값
    
    cout<<(a+4)<<endl;//a[4]의 주소값
    
    
    cout<<*(++ptr)<<endl;//a[1]의 값
    
    cout<<*b[1]<<endl;//b[1][0]의 값
}
