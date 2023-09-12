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

        void printReverse(){
            Node* last = NULL;
            while(last != this->head){
                Node* current = this->head;
                while(current != NULL){
                    if(current->next == last){
                        cout<<current->data<<" ";
                        last = current;
                        break;
                    }
                    current = current->next;
                }
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
    LinkedList l1;
    l1.addAtEnd(10);
    l1.addAtEnd(20);
    l1.addAtEnd(30);
    l1.addAtEnd(40);
    l1.addAtEnd(50);
    l1.print();
    l1.printReverse();
    return 0;
}