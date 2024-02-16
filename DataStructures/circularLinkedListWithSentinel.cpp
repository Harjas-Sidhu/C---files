#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

struct linkedList{
    node* nil;
    node* tail;
};

node* search(linkedList l, int val){
    l.nil->data = val;
    node* temp = l.nil->next;
    while(temp->data != val){
        temp = temp->next;
    }
    if(temp == l.nil){
        cout << "Value not found in list!" << endl;
        return l.nil;
    }
    return temp;
}

void append(linkedList &l, int val){
    node* temp = new node;
    temp->data = val;
    temp->next = l.nil;
    temp->prev = l.tail;
    l.tail->next = temp;
    l.tail = temp;
}

void pop(linkedList l){
    if(l.tail == l.nil){
        cout << "Empty List!" << endl;
        return;
    }
    node* temp = l.tail;
    l.tail = l.tail->prev;
    l.tail->next = l.nil;
    delete temp;
}

void del(linkedList &l, int val){
    node* toDelete = search(l, val);
    if(toDelete == l.nil){
        cout << "Element cannot be deleted! Not found!" << endl;
        return;
    }
    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;
    delete toDelete;
}

int main(){
    linkedList l;
    l.nil = new node;
    l.nil->next = l.nil;
    l.nil->prev = l.nil;
    l.tail = l.nil;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int val = 0;
        cin >> val;
        append(l, val);
    }
    node* temp = l.nil->next;
    while(temp != l.nil){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    pop(l);
    temp = l.nil->next;
    while(temp != l.nil){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    int val = 0;
    cin >> val;
    del(l, val);
    temp = l.nil->next;
    while(temp != l.nil){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}