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

class Stack{
    public:
        Node* head;
        Node* top;
        Stack(){
            this->head = NULL;
            this->top = NULL;
        }
        void peek(){
            if(top != NULL){
                cout<<"TOP: "<<this->top->data<<endl;
            }
            else{
                cout<<"Empty Stack"<<endl;
            }
        }
        void push(int data){
            Node* newnode = new Node(data);
            if(newnode == NULL){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            if(head == NULL){
                head = newnode;
                top = newnode;
                return;
            }
            top->next = newnode;
            top = newnode;
        }
        void pop(){
            if(head == NULL){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            if(top == head){
                head = NULL;
                top = NULL;
                return;
            }
            Node* current = head;
            while(current->next != top){
                current = current->next;
            }
            delete top;
            top = current;
        }
};

int main(){
    Stack s1;
    s1.push(1);
    s1.peek();                   //TOP: 1
    s1.pop();
    s1.peek();                   //Empty Stack
    s1.push(2);
    s1.push(3);
    s1.peek();                   //TOP: 3
    s1.push(4);
    s1.push(5);
    s1.peek();                   //TOP: 5
    s1.pop();
    s1.peek();                   //TOP: 4
    return 0;
}