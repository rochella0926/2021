#include <iostream>
using namespace std;

int main()

{

    int n,i;
    float sum, avr;

    int grade[10]={90,100,95,60,70,50,20,100,98,100};
    
    n=10;

    for(i=0;i<n;i++){
        sum += grade[i];
    }

  avr = sum / n; // 평균을 구함

  cout<<"Grade's average is "<<avr<<endl;


  }
