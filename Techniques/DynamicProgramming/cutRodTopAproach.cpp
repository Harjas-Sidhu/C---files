#include <bits/stdc++.h>
using namespace std;

int cutRod(int p[], int n, int r[]){
    if(r[n] >= 0){
        return r[n];
    }
    int price = 0;
    if(n > 0){
        price = INT_MIN;
        for(int i = 1; i <= min(n, 11); i++){
            if(i <= n){
                price = max(price, p[i]+cutRod(p, n-i, r));
            }
        }
    }
    r[n] = price;
    return price;
}


int initializeArray(int p[], int n){
    int r[n+1];
    for(int i = 0; i <= n; i++){
        r[i] = INT_MIN;
    }
    return cutRod(p, n, r);
}

int main(){
    int price[] = {0,1,5,8,9,10,17,17,20,24,30};
    cout<<initializeArray(price, 40)<<endl;
    return 0;
}