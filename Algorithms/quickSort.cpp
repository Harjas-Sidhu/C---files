#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int startIndex, int endIndex){
    int pivot = arr[endIndex];
    int iterator = startIndex - 1;
    for(int j = startIndex; j < endIndex; j++){
        if(arr[j] <= pivot){
            iterator += 1;
            swap(arr[j], arr[iterator]);
        }
    }
    iterator += 1;
    swap(arr[iterator], arr[endIndex]);
    return iterator;
}

void quickSort(int arr[], int startIndex, int endIndex){
    while(startIndex < endIndex){
        int partitionedIndex = partition(arr, startIndex, endIndex);
        quickSort(arr, startIndex, partitionedIndex - 1);
        startIndex = partitionedIndex + 1;
    }
}

int main(){
    int n = 0;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}