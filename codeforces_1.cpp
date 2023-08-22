#include <iostream>
#include <math.h>
using namespace std;

bool sorted(int arr[], int t) {
    for (int i = 1; i < t; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int func(int arr[], int t){
    if(sorted(arr, t)){
        return 0;
    }
    int min = 1;
    for (int i = 0; i < t; i++)
    {
        if(arr[i] > 0){
            min = arr[i];
            break;
        }
    }
    for (int i = 0; i < t; i++)
    {
        if(arr[i] > 0 && min > arr[i]){
            min = max(1, arr[i]);
        }
    }
    for (int i = 0; i < t; i++)
    {
        arr[i] = max(0, arr[i]-min);
    }
    return min+func(arr, t);
}

int main(){
    int t;
    int count = 0;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int j = 0; j < n; j++){
            cin>>arr[j];
        }
        printf("%d\n", func(arr, n));
    }
    return 0;
}