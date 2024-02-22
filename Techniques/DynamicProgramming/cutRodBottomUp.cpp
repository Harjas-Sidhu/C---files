#include <bits/stdc++.h>
using namespace std;

int main(){
    int price[] = {0,1,5,8,9,10,17,17,20,24,30};
    int n = 7;
    int r[n+1], s[n+1];
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        int pri = INT_MIN;
        for(int j = 1; j <= min(i, 11); j++){
            if(pri < price[j]+r[i - j]){
                pri = price[j]+r[i - j];
                s[i] = j;
            }
        }
        r[i] = pri;
    }
    cout<<r[n]<<endl;
    while(n > 0){
        cout<<s[n]<<" ";
        n -= s[n];
    }
    cout<<endl;
    return 0;
}