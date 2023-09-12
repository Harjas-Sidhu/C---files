#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = arr[i], key = 0;
        for(int j = i + 1; j < n; j++){
            if(min > arr[j]){
                min = arr[j];
                key = j;
            }
        }
        if(min < arr[i]){
            swap(arr[i], arr[key]);
        }
    }
}

int main(){
    int n = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    selectionSort(arr, n);
    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}