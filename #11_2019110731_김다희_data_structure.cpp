//중위 표기식을 후위 표기식으로 변환 후 계산

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

char post_fix_expr[1000];
int p_index=0;

char *postfix(char expr[]){
    Stack mystack;
    
   // cout<<"입력 수식 : "<<expr<<endl;
    //cout<<"후위 수식 : ";
    //convert to postfix
    for(int i=0; i<strlen(expr);i++){
    if(expr[i]=='('){//왼쪽 괄호
        continue;
    }else if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*'||expr[i]=='/'){//연산자
        mystack.push(expr[i]);
    }else if(expr[i]==')'){//오른쪽 괄호
        //cout<<mystack.pop();
        post_fix_expr[p_index++]=mystack.pop();
       
    }else if(expr[i]==' '){
        continue;
    }else{//피연산자
        //cout<<expr[i];
        post_fix_expr[p_index++]=expr[i];
    }
    }
    //cout<<endl;
    post_fix_expr[p_index++]='\0';
    
    return post_fix_expr;
}

int calculate(char postfix[]){
    
    Stack mystack;
    
    for(int i=0; i<strlen(postfix);i++){
 
    //연산자면 pop 후 계산. 계산 결과는 다시 스택에 push
        if(postfix[i]=='+'){
            
            int opr2=mystack.pop();
            int opr1=mystack.pop();
            mystack.push(opr1+opr2);


        }else if(postfix[i]=='-'){
            
            int opr2=mystack.pop();
            int opr1=mystack.pop();
            mystack.push(opr1-opr2);
            
        }else if(postfix[i]=='*'){
            
            int opr2=mystack.pop();
            int opr1=mystack.pop();
            mystack.push(opr1*opr2);
            
        }else if(postfix[i]=='/'){
            
            int opr2=mystack.pop();
            int opr1=mystack.pop();
            mystack.push(opr1/opr2);
            
        }else if(postfix[i]>='0'&&postfix[i]<='9'){
            mystack.push(postfix[i]-'0');//문자를 숫자로 변환
        }
            
            
        //피연산자면 스택에 push
    }
    //최종 결과는 스택에 남아 있는 값
    //return **
    return mystack.pop();
}


int main(){
    
    char string[100];
    cout<<"중위표기 수식을 입력하세요 : ";
    cin.getline(string, 100);
    
    char *post_expr=postfix(string);
   // cout<<string>>"==>"<<post_expr<<endl;
    

    cout<<string<<" = "<<post_expr<<" = " <<calculate(post_expr)<<endl;


}



