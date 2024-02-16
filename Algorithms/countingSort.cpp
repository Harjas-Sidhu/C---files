#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n, int k){
    int countArr[k+1], sortedArr[n];
    for(int i = 0; i <= k; i++){
        countArr[i] = 0;
    }
    for(int i = 0; i < n; i++){
        countArr[arr[i]] += 1;
    }
    for(int i = 1; i <= k; i++){
        countArr[i] += countArr[i - 1];
    }
    for(int j = n-1; j >= 0; j--){
        sortedArr[countArr[arr[j]] - 1] = arr[j];
        countArr[arr[j]] -= 1;
    }
    for(int i = 0; i < n; i++){
        arr[i] = sortedArr[i];
    }
}

int main(){
    int n = 0, k = 0;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    countingSort(arr, n, k);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}