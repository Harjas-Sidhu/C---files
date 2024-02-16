#include <bits/stdc++.h>
using namespace std;

struct queueParams{
    int size;
    int head;
    int tail;
};

bool isEmpty(queueParams queue){
    if(queue.head == queue.tail){
        return true;
    }
    return false;
}

void enqueue(queueParams &queue, int arr[], int value){
    if(queue.tail == queue.size){
        cout << "Queue Overflow!" << endl;
        return;
    }
    queue.tail += 1;
    arr[queue.tail] = value;
}

void dequeue(queueParams &queue, int arr[]){
    if(isEmpty(queue)){
        cout<< "Queue Overflow!" <<endl;
        return;
    }
    queue.head += 1;
}

int main(){
    queueParams queue;
    int n = 0;
    cin >> n;
    int arr[n];
    queue.size = n;
    queue.head = -1;
    queue.tail = -1;
    for(int i = 0; i < n; i++){
        int val = 0;
        cin >> val;
        enqueue(queue, arr, val);
    }
    for(int i = queue.head; i <= queue.tail; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    dequeue(queue, arr);
    for(int i = queue.head; i <= queue.tail; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}