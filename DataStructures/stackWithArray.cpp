#include <bits/stdc++.h>
using namespace std;

 struct stackParams{
    int size;
    int top;
};

bool isEmpty( stackParams &stack){
    if(stack.top == -1){
        return true;
    }
    return false;
}

void push( stackParams &stack, int arr[], int val){
    if(stack.top == stack.size){
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack.top += 1;
    arr[stack.top] = val;
    return;
}

void pop( stackParams &stack, int arr[]){
    if(isEmpty(stack)){
        cout << "Stack Underflow!" <<endl;
        return;
    }
    stack.top -= 1;
}

int main(){
     stackParams stack;
    int n = 0;
    cin >> n;
    int arr[n];
    stack.size = n;
    stack.top = -1;
    for(int i = 0; i < n; i++){
        int val = 0;
        cin >> val;
        push(stack, arr, val);
    }
    for(int i = 0; i <= stack.top; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    pop(stack, arr);
    for(int i = 0; i <= stack.top; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}