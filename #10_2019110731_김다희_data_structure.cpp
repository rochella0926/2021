//중위 표기식을 후위 표기식으로 변환

#include <iostream>
using namespace std;

#define element int
const int MAX_SIZE=1000;


class Stack{
public:
    
    char mystack[MAX_SIZE];
    int top=-1;
    
    Stack(){top=-1;}
    
    bool is_stack_empty(){
        //if (top==-1) return true;
        // else return false;
        return(top==-1);;//***
    }

    bool is_stack_full(){
        //if (top==MAX_SIZE-1) return true;
      // else return false;
        return(top==MAX_SIZE-1);;//***
}

    void push(element data){
        if(is_stack_full()){
        cout<<"ERROR:STACK Full"<<endl;
        return;
        }else{
            // top++;
            //Stack[top]=data;
            mystack[++top]=data;
        }
 
    }

    element pop(){
        if(is_stack_empty()){
            cout<<"ERROR : Stack Empty"<<endl;
            return -1;
        }else{
            // element x=Stack[top];
            // top--;
            // return x;
            return mystack[top--];
        }
    
    }

    element peek(){
        if(is_stack_empty()){
            cout<<"ERROR : Stack Empty"<<endl;
            return  -1;
        }else
            return mystack[top];
    }
    void print_stack(){
        cout<<"STACK STATUS "<<endl;
    
        for(int i=top; i>=0; i--)
            cout<<mystack[i]<<endl;
            
    
    }};

void postfix(char expr[]){
    Stack mystack;
    
    cout<<"입력 수식 : "<<expr<<endl;
    cout<<"후위 수식 : ";
    //convert to postfix
    for(int i=0; i<strlen(expr);i++){
    if(expr[i]=='('){//왼쪽 괄호
        continue;
    }else if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'){//연산자
        mystack.push(expr[i]);
    }else if(expr[i]==')'){//오른쪽 괄호
        cout<<mystack.pop();
       
    }else if(expr[i]==' '){
        continue;
    }else{//피연산자
        cout<<expr[i];
    }
    }
    cout<<endl;
 
}
int main(){
    
    char string[100];
    cout<<"수식을 입력하세요 : ";
    cin.getline(string, 100);
    
    postfix(string);



}



