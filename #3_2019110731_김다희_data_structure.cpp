//Average by subject,Average by student
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* link;
};

Node *Head=NULL;

int insert_node(Node *pre, Node *new_node){
    if( Head == NULL ){    // 공백리스트인 경우
            // new_node->link = NULL;
            Head = new_node;
        }
        else if( pre == NULL ){     // pre가 NULL이면 첫번째 노드로 삽입
            new->link = Head;
            Head = new_node;
        }
        else {         // pre 다음에 삽입
            new_node->link = pre->link;
            pre->link = new_node;
        }
    }
    
}

int print_list(){
    
    for(Node *ptr=Head; ptr !=NULL;ptr=ptr->link)
    {cout<<ptr->data<<endl;}
}

int main(){
    for(int i=0; i<0;i++){
        //input new data
        int i_data;
        cin>>i_data;
        //new node+update
        Node *new_node=new Node;
        new_node->=i_data;
        new_node->link=NULL;
        
        //insert
        insert_node(new_node);
        
    }
}
