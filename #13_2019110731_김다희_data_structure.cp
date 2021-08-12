
//연결리스트 큐
#include <iostream>
using namespace std;

#define element int


class Node{
public:
    element data;
    Node* link;
};

Node *front=NULL;
Node *rear=NULL;


bool is_queue_empty(){
    return(front=NULL);//***
}

void enQueue(element data){
    Node *new_node=new Node;
    new_node->data=data;
    new_node->link=NULL;
    
    if(is_queue_empty()){
        front=rear=new_node;
    }else{
        rear->link=new_node;
        rear=new_node;
    }
 
}

element deQueue(){
    if(is_queue_empty()){
        cout<<"ERROR:Queue Empty"<<endl;
        return -1;
    }else{
       element x=Stack[top];
       // top--;
       // return x;
        return Stack[top--];
    }
    
}

element peek(){
    if(is_stack_empty()){
        cout<<"ERROR:Stack Empty"<<endl;
        return  -1;
    }else
        return Stack[top];
}

void print_stack(){
    cout<<"STACK STATUS"<<endl;
    
    if(is_stack_empty()) return;
    else{
        for(int i=top; i>=0;i--)
            cout<<Stack[i]<<endl;
    }
}

bool check_matching(char sentence[]){
    
}
int main(){
    
    char string[100];
    cout<<"수식을 입력하세요 : ";
    cin>>string;
    
    if(check_matching(string)==true)
        cout<<string<<" => 괄호 OK"<<endl;
    else
        cout<<string<<" => 괄호 ERROR"<<endl;
}



