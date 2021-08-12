//단일연결리스트 삽입_A
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* link;
};

Node *Head=NULL;

void insert_node_A(Node *pre, Node *new_node){
    if( Head == NULL ){    // 공백리스트인 경우
            // new_node->link = NULL;
            Head = new_node;
        }
        else if( pre == NULL ){     // pre가 NULL이면 첫번째 노드로 삽입
            new_node->link = Head;
            Head = new_node;
        }
        else {         // pre 다음에 삽입
            new_node->link = pre->link;
            pre->link = new_node;
        }
    }
    
void insert_node_B(Node *new_node){
    if( Head == NULL ){    // 공백리스트인 경우
            // new_node->link = NULL;
            Head = new_node;
        }
        else  {
            Node *list= Head;

            while(list->link != NULL)
                list = list->link;
            list->link = new_node;
        }

}

void insert_node_C(Node *new_node){
    new_node->link=Head;
    Head=new_node;
}
void print_list(){
    
    for(Node *ptr=Head; ptr !=NULL;ptr=ptr->link)
    {cout<<ptr->data<<">>";}
}

void delete_node(int x){//x값을 갖는 노드를 연결리스트에서 삭제
    
        Node *list = Head;

        if( Head == NULL )  return;     // 삭제할 것이 없음
        else if( Head->data == x )     // 찾는 노드(삭제 노드)가 첫 노드인 경우
        {      // delete list; free(list);
                Head = Head->link;
                return;
        }
        else             // 나머지 경우
        {        while(list->link != NULL)
                  {         if( list->link->data == x )
            {    list->link = list->link->link;
                //delete list; free(list->link);
                return;
            }
            list = list->link;
                   }
        }
    }


int main(){
    
    int data_number;
    cout<<"전테 입력 데이터의 개수는?";
    cin>>data_number;
    
    
    for(int i=0; i<data_number;i++){
        //input new data
        int i_data;
        cout<<"input new node";
        cin>>i_data;
        //new node+update
        Node *new_node=new Node;
        new_node->data = i_data;
        new_node->link=NULL;
        
        //insert
        insert_node_C(new_node);
        
    }
    //print
    print_list();
    
    //remove
    for(int i=0;i<3;i++){
        int del_data;
        cout<<"삭제할 노드의 값 입력";
        cin>>del_data;
        delete_node(del_data);
        cout<<"##삭제 후 구성된 연결 리스트 : ";
        print_list();
    }
   

    
}
