#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        bool isSwapped = false;
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j+1], arr[j]);
                isSwapped = true;
            }
        }
        if(!isSwapped){
            return;
        }
    }
}

int main(){
    int n = 0;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}