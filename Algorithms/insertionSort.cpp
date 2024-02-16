#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int keyValue = arr[i];
        int j = i - 1;

        while(j > -1 && arr[j] > keyValue){
            arr[j+1] = arr[j];
            j -= 1;
        }

        arr[j+1] = keyValue;
    }
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insertionSort(arr, n);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;

    return 0;
}