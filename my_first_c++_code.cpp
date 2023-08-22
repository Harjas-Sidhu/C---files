#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    int *ptr = arr;
    for(int i = 0; i < 8; i++){
        *(ptr + i) = i;
    }
    for(int i = 0; i < 8; i++){
        printf("%d\n", *(ptr + i));
    }
    return 0;
}