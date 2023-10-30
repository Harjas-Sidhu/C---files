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

class BST{
    public:
        Node* root;
        BST(){
            root = NULL;
        }
        void append(int data){
            Node* newnode = new Node(data);
            if(root == NULL){
                root = newnode;
                return;
            }
            Node* temp = root;
            while(temp != NULL){
                if(temp->data >= data){
                    if(temp->left == NULL){
                        temp->left = newnode;
                        return;
                    }
                    temp = temp->left;
                }
                else if(temp->data < data){
                    if(temp->right == NULL){
                        temp->right = newnode;
                        return;
                    }
                    temp = temp->right;
                }
            }
        }
        void inorderTreversal(Node* root){
            if(root == NULL){
                return;
            }
            inorderTreversal(root->left);
            cout<<root->data<<" ";
            inorderTreversal(root->right);
        }
        void preorderTreversal(Node* root){
            if(root == NULL){
                return;
            }
            cout<<root->data << " ";
            preorderTreversal(root->left);
            preorderTreversal(root->right);
        }
        void postorderTreversal(Node* root){
            if(root == NULL){
                return;
            }
            postorderTreversal(root->left);
            postorderTreversal(root->right);
            cout<<root->data<<" ";
        }
        void kth_smallest(int& k, Node* root){
            if(root == NULL){
                return;
            }
            kth_smallest(k, root->left);
            k--;
            if(k==0){
                cout<<root->data<<endl;
                return;
            }
            kth_smallest(k, root->right);
        }
};

int main(){
    int n = 0;
    BST b1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int data = 0;
        cin>>data;
        b1.append(data);
    }
    cout<<"Inorder traversal: ";
    b1.inorderTreversal(b1.root);
    cout<<endl;
    int m = 0;
    cin>>m;
    b1.kth_smallest(m, b1.root);
    return 0;
}