#include <bits/stdc++.h>
using namespace std;

int parent(int index){
    return index/2;
}
int left(int index){
    return index*2;
}
int right(int index){
    return (index*2)+1;
}

void maxHeapify(int arr[], int n, int index){
    int largest = index;
    int l = left(index);
    int r = right(index);
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != index){
        swap(arr[largest], arr[index]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n){
    for(int i = (n/2); i >= 0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        n -= 1;
        maxHeapify(arr, n, 0);
    }
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    heapSort(arr, n);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}