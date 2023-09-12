#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            this->head = NULL;
        }
        void addAtEnd(int data){
            Node* newNode = new Node(data);
            if(this->head == NULL){
                this->head = newNode;
            }
            else{
                Node* current = this->head;
                while(current->next != NULL){
                    current = current->next;
                }
                current->next = newNode;
            }
        }

        void print(){
            Node* current = this->head;
            while(current != NULL){
                cout<<current->data<<" ";
                current = current->next;
            }
            cout<<endl;
        }

        ~LinkedList(){
            Node* current = this->head;
            while(current != NULL){
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
};

int main(){
    
    return 0;
}