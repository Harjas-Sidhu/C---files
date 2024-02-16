#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int startIndex, int midIndex, int endIndex){
    int leftSize = midIndex - startIndex + 1;
    int rightSize = endIndex - midIndex;

    int leftArray[leftSize], rightArray[rightSize];

    for(int i = 0; i < leftSize; i++){
        leftArray[i] = arr[startIndex+i];
    }

    for(int i = 0; i < rightSize; i++){
        rightArray[i] = arr[midIndex+1+i];
    }

    int index = startIndex, leftIndex = 0, rightIndex = 0;

    while(leftIndex < leftSize && rightIndex < rightSize){
        if(leftArray[leftIndex] <= rightArray[rightIndex]){
            arr[index] = leftArray[leftIndex];
            leftIndex += 1;
        }
        else{
            arr[index] = rightArray[rightIndex];
            rightIndex += 1;
        }
        index += 1;
    }

    while(leftIndex < leftSize){
        arr[index] = leftArray[leftIndex];
        leftIndex += 1;
        index += 1;
    }

    while(rightIndex < rightSize){
        arr[index] = rightArray[rightIndex];
        rightIndex += 1;
        index += 1;
    }
}

void mergeSort(int arr[], int startIndex, int endIndex){
    if(startIndex >= endIndex){
        return;
    }
    int midIndex = ((endIndex-startIndex)/2) + startIndex;
    mergeSort(arr, startIndex, midIndex);
    mergeSort(arr, midIndex+1, endIndex);
    merge(arr, startIndex, midIndex, endIndex);
}

int main(){
    int n = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}