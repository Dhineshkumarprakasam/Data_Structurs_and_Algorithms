#include <iostream>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;

    Node(char data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }

    Node(char data, Node *left, Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

Node *stk[100];
int top=-1;

Node *root=nullptr;

void display(Node *root, int height=0){
    if(root==nullptr)
        return;
    
    for(int i=0;i<height;i++)
        cout<<" ";
    cout<<root->data<<endl;
    display(root->left,height+1);
    display(root->right,height+1);
}

void inorder(Node *root){
    if(root==nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void buildTree(string str){
    Node *newnode;
    for(int i=0;i<str.length();i++){
        if(isalnum(str[i])){
            newnode = new Node(str[i]);
            stk[++top]=newnode;
        }

        else{
            Node *first = stk[top--];
            Node *second = stk[top--];
            newnode = new Node(str[i],second,first);
            stk[++top]=newnode;
        }
    }

    root = stk[top];
}


int main(){
    buildTree("ABC*+D/");
    display(root);
    inorder(root);
}
