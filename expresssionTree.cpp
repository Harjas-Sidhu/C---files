#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;
        Node(char data){
            left = right = NULL;
            this->data = data;
        }
};

class Expressiontree{
    public:
        Node* root;
        Expressiontree(){
            root = NULL;
        }
        void append(char data, Node* root){
            Node* newnode = new Node(data);
            if(root == NULL){
                root = newnode;
                return;
            }
            if(isdigit(data)){
                append(data, root->right);
            }
            else{
                append(data, root->left);
            }
        }
};

int main(){
    int n = 0;
    cin>>n;
    Expressiontree et;
    for(int i = 0; i < n; i++){
        char c = 'c';
        cin>>c;
        et.append(c, et.root);
    }
    return 0;
}