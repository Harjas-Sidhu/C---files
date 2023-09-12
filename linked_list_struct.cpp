#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void add(struct Node** head, int data){
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        struct Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print(struct Node* head){
    struct Node* temp = head;
    if(head == NULL){
        cout<<"List is empty!!"<<endl;
    }
    int count = 1;
    while(temp->next != NULL){
        cout<<count<<". "<<temp->data<<endl;
        temp = temp->next;
        count++;
    }
    cout<<count<<". "<<temp->data<<endl;
}

int main(){
    struct Node* head = NULL;
    print(head);
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        delete current;
        current = next;
    }
    return 0;
}