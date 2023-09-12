#include <bits/stdc++.h>
using namespace std;

class Node{

    private:

        int data;
        Node* next;

    public:

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        void addAtEnd(int data){
            Node* temp = new Node(data);
            if(this->next == NULL){
                this->next = temp;
            }
            else{
                Node* current = this->next;
                while(current->next != NULL){
                    current = current->next;
                }
                current->next = temp;
            }
        }

        void InsertInPlace(int data, int index){
            if(index < 1){
                cout<<"Invalid Index"<<endl;
            }
            else{
                int count = 1;
                Node* temp = this->next;
                while(count < index-1){
                    temp = temp->next;
                }
                Node *newNode = new Node(data);
                Node* t = temp->next;
                temp->next = newNode;
                newNode->next = t;
            }
        }

        void DeleteFromPlace(int index){
            if(index < 1){
                cout<<"Invalid Index"<<endl;
            }
            else{
                int count = 1;
                Node* temp = this->next;
                while(count < index-1){
                    temp = temp->next;
                }
                Node* t = temp->next->next;
                temp->next = t;
            }
        }

        void print(){
            Node* current = this->next;
            int count = 1;
            while(current != NULL){
                cout<<count<<". "<<current->data<<endl;
                count++;
                current = current->next;
            }
            cout<<endl;
        }

        void printReverse(){
            Node* last = NULL;
            while(last!=this->next){
                Node* temp = this->next;
                while(temp != NULL){
                    if(temp->next==last){
                        cout<<temp->data<<endl;
                        last = temp;
                    }
                    temp = temp->next;
                }
            }
        }

        ~Node(){
            Node* current = this->next;
            while(current != NULL){
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

};

int main(){
    Node n(0);
    n.addAtEnd(100);
    n.addAtEnd(200);
    n.addAtEnd(300);
    n.addAtEnd(400);
    n.print();
    n.InsertInPlace(600, 2);
    n.print();
    n.DeleteFromPlace(2);
    n.print();
    n.printReverse();
    return 0;
}