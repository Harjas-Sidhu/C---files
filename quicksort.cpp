#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[], int start, int end, int size){
    int pivot = arr[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++){
        if(arr[i] < pivot){
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);
    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    print(arr, size);
    return pivotIndex;
}

void quicksort(int arr[], int start, int end){
    static int size = end+1;
    if(start >= end){
        return;
    }
    int p = partition(arr, start, end, size);
    quicksort(arr, start, p-1);
    quicksort(arr, p+1, end);
}

int main(){
    int n = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    print(arr, n);
    quicksort(arr, 0, n-1);
    print(arr, n);
    return 0;
}