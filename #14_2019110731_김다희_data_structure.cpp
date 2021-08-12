//수식트리 계산
#include <iostream>
using namespace std;

#define element int

class TreeNode{
public:
    element data;
    TreeNode *left, *right;
    
    TreeNode(element value){
        data=value;
        left=right=NULL;
    }
};

void main(){
    //Expression Tree 구성
    //노드 7개 생성, 그리기
    
    TreeNode *n1=new TreeNode(3);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode('*');
    TreeNode *n4=new TreeNode(5);
    TreeNode *n5=new TreeNode(6);
    TreeNode *n6=new TreeNode('+');
    TreeNode *root=new TreeNode('+');
    
    
    //6개 가지, 연결하기
    
    n3->left=n1;
    n3->right=n2;
    n6->left=n4;
    n6->right=n5;
    root->left=n3;
    root->right=n6;
    
    cout<<
}
