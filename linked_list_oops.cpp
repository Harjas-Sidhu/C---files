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

        static Node* head(){
            return this->next;
        }

        void add(int data){
            Node* newNode = new Node(data);
            if(this->next == NULL){
                this->next = newNode;
            }
            else{
                Node* temp = this->next;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void insert(int data, int place){
            if(place < 1){
                cout<<"Invalid Index"<<endl;
            }
            else{
                Node* newNode = new Node(data);
                newNode->data = data;
                newNode->next = NULL;
                int count = 1;
                Node* temp = this->next;
                while(count != place-1){
                    temp = temp->next;
                    count++;
                }
                Node* t = temp->next;
                temp->next = newNode;
                newNode->next = t;
            }
        }

        void del(int place){
            if(place < 1){
                cout<<"Invalid Index"<<endl;
            }
            else{
                int count = 1;
                Node* temp = this->next;
                while(count != place-1){
                    temp = temp->next;
                    count++;
                }
                Node* inPlaceNode = temp->next;
                temp->next = inPlaceNode->next;
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
    n.add(100);
    n.add(200);
    n.add(300);
    n.add(400);
    n.add(500);
    n.print();
    n.reverse();
    n.print();
    return 0;
}