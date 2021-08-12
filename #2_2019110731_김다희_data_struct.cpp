//Average by subject,Average by student
#include <iostream>
using namespace std;

int main()

{

    int lang_scores[10]={100,98,78,45,98,77,90,91,77,86};
    int eng_scores[10]={43,60,58,93,58,90,40,71,70,96};
    int math_scores[10]={79,88,70,90,59,79,66,90,97,55};

//Average by subject
    
    float lang_avr, eng_avr, math_avr;
   
    //language
    float sum=0;
    for (int i=0;i<10;i++){
        sum+=lang_scores[i];
    }
    lang_avr=sum/10;
    cout<<"lang_avr is "<<lang_avr<<endl;
    
    //english
    sum=0;
    for (int i=0;i<10;i++){
        sum+=eng_scores[i];
    }
    eng_avr=sum/10;
    cout<<"eng_avr is "<<eng_avr<<endl;
    
    //math
    sum=0;
    for (int i=0;i<10;i++){
        sum+=math_scores[i];
    }
    math_avr=sum/10;
    cout<<"math_avr is "<<math_avr<<endl;
    
    //Average by student
    float student_avr[10]={};
    
    for(int n=0;n<10;n++){
    student_avr[n]=(lang_scores[n]+eng_scores[n]+math_scores[n])/3;
    cout<<"student["<<n<<"]'s avr is "<<student_avr[n]<<endl;
    }
    
}
