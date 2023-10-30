#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class Queue{
    public:
        Node* head;
        Node* tail;
        Queue(){
            this->head = this->tail = NULL;
        }
        void enQueue(int data){
            Node* newnode = new Node(data);
            if(head == NULL){
                head = newnode;
                tail = newnode;
                cout<<newnode->data<<" has been enqueued"<<endl;
                return;
            }
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            cout<<newnode->data<<" has been enqueued"<<endl;
        }

        int dequeue(){
            if(head == NULL){
                cout<<"Nothing to dequeue"<<endl;
                return -1;
            }
            Node* t = head;
            head = head->next;
            cout<<t->data<<" has beeen dequeued"<<endl;
            int val = t->data;
            delete t;
            return val;
        }

        void peek(){
            if(this->head != NULL){
                cout<<"First Element: "<<this->head->data<<endl;
            }
            else{
                cout<<"Queue is Empty!"<<endl;
            }
        }
};

int main(){
    Queue q1;
    q1.enQueue(1);
    q1.peek();
    q1.dequeue();
    q1.peek();
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.enQueue(5);
    q1.peek();
    q1.dequeue();
    q1.peek();
    return 0;
}