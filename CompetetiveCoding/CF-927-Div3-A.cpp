//  Problem Link:- https://codeforces.com/contest/1932/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t = 0;
    cin>>t;
    while(t--){
        int n = 0;
        cin>>n;
        char arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int coinCount = 0;
        for(int i = 1; i < n; i++){
            if(arr[i] == '*' && arr[i-1] == '*'){
                break;
            }
            else if(arr[i] == '@'){
                coinCount += 1;
            }
        }
        cout<<coinCount<<endl;
    }
    return 0;
}