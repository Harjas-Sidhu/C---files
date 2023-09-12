#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int j = 0, current = arr[i];
        for(j = i-1; j >= 0; j--){
            if(arr[j] > current){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current;
    }
}

int main(){
    int n = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    insertionSort(arr, n);
    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}