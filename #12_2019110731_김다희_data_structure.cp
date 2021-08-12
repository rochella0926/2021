
//큐의 기본함수와 구현, 태스트-배열
#include <iostream>
using namespace std;

#define element int
#define MAX_SIZE 100


class QUEUE{
public:
    element Queue[MAX_SIZE];
    int front,rear;
    QUEUE(){
        front=rear=-1;
    }
    
    bool is_queue_empty(){
        return(front=rear);
    }

    bool is_queue_full(){
       
        return(rear==MAX_SIZE-1);;//***
    }

    void enQueue(element data){
        if(is_queue_full()){
            cout<<"ERROR: Queue Full"<<endl;
            return ;
            
        }else{
          Queue[++rear]=data;
        }
    }

    element deQueue(){
        if(is_queue_empty()){
            cout<<"ERROR: Queue Empty"<<endl;
            return -1;
        }else{
           
            return Queue[++front];
        }
        
    }

    element peek(){
        if(is_queue_empty()){
            cout<<"ERROR: Queue Empty"<<endl;
            return -1;
        }else{
            return Queue[front+1];
        }
    }

    void print_queue(){
        cout<<"QUEUE STATUS (front = "<<front<<", rear = "<<rear<<endl;
        
        if(is_queue_empty()) return;
        else{
            for(int i=front+1;i<=rear;i--)
                cout<<Queue[i]<<endl;
        }
        cout<<endl;
    }
 
};


int main(){
    
    QUEUE MyQueue;
    MyQueue.enQueue(10);
    MyQueue.enQueue(50);
    MyQueue.enQueue(40);
    MyQueue.enQueue(30);
    MyQueue.enQueue(20);
    MyQueue.deQueue();
    MyQueue.print_queue();
    
    
    MyQueue.enQueue(100);
    MyQueue.enQueue(60);
    MyQueue.enQueue(50);
    MyQueue.deQueue();
    MyQueue.print_queue();
    
}



