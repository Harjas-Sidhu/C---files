#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class BinaryTree{
    public:
        Node* root;
        BinaryTree(){
            root = NULL;
        }
        void append(vector <int> v){
            if(v.empty()){
                return;
            }
            queue <Node*> q;
            root = new Node(v[0]);
            q.push(root);
            int i = 1;
            while(i < v.size()){
                Node* current = q.front();
                q.pop();
                if(i < v.size()){
                    current->left = new Node(v[i++]);
                    q.push(current->left);
                }
                if(i < v.size()){
                    current->right = new Node(v[i++]);
                    q.push(current->right);
                }
            }
        }

        void level_wise_traversal(Node* root){
            if(root == NULL){
                return;
            }
            queue <Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* current = q.front();
                cout<<current->data<<" ";
                q.pop();
                if(current->left != NULL){
                    q.push(current->left);
                }
                if(current->right != NULL){
                    q.push(current->right);
                }
            }
        }

        void print(Node* root){
            if(root == NULL){
                return;
            }
            print(root->left);
            cout<<root->data<<" ";
            print(root->right);
        }

        int height(Node* root){
            if(root == NULL){
                return 0;
            }
            int lheight = height(root->left);
            int rheight = height(root->right);
            return (lheight>rheight?(lheight+1):(rheight+1));
        }
};

int main(){
    vector <int> v;
    int n = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        int k = 0;
        cin>>k;
        v.push_back(k);
    }
    BinaryTree b1;
    b1.append(v);
    b1.print(b1.root);
    cout<<endl;
    b1.level_wise_traversal(b1.root);
    cout<<endl<<b1.height(b1.root)<<endl;
    return 0;
}