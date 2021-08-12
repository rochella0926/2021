//이중연결리스트
#include <iostream>
using namespace std;

class CNode{
public:
    int data;
    CNode* link;
};

CNode *Head=NULL;

//insert

void insert_node_first(CNode *pre, CNode *new_node){
    if( Head == NULL ){    // 공백리스트인 경우
            new_node->link = new_node;
            Head = new_node;
        }
      
        else {         // pre 다음에 삽입
            new_node->link = Head->link;
            Head->link = new_node;
        }
    }
    
void insert_node_last(CNode *new_node){
    if( Head == NULL ){    // 공백리스트인 경우
            new_node->link = new_node;
            Head = new_node;
        }
        else  {
            new_node->link=Head->link;
            Head->link=new_node;
            Head=new_node;
        }

}


//remove_key값을 가진 노드 지우기

void remove_node( int key)
{
    if( Head == NULL ) return;
    else if(Head->link==Head&&Head->data==key) Head=NULL;
    else
    {     CNode *pre = Head;

        do
        {  if(pre->link->data==key){
            CNode *removed =pre->link;
            pre->link=removed->link;//pre->link값이 바뀜(removed를 사용한 이유)
            if(Head==removed)Head=pre;//헤드포인터 유지
            return;
        } pre=pre->link;
        }  while(pre != Head);
    }
}

//print
void print_list()
{
    if( Head == NULL ) return;
    else
    {     CNode *ptr = Head;

        do
        {cout << ptr->link->data;
         ptr = ptr->link;
        } while(ptr != Head);
        cout<<endl;
    }
}


int main(){
    
    int data_number;
    cout<<"전체 입력 데이터의 개수는?";
    cin>>data_number;
    
    
    for(int i=0; i<data_number;i++){
        //input new data
        int i_data;
        cout<<"input new node";
        cin>>i_data;
        //new node+update
        CNode *new_node=new CNode;
        new_node->data = i_data;
        new_node->link=NULL;
        
        //insert
  
       insert_node_last(new_node);
        
    }
    //print
    print_list();
    
    //remove
    for(int i=0;i<3;i++){
        int del_data;
        cout<<"삭제할 노드의 값 입력";
        cin>>del_data;
        remove_node(del_data);
        cout<<"##삭제 후 구성된 연결 리스트 : ";
        print_list();
    }
   

    
}
