#include <bits/stdc++.h>
using namespace std;

int cutRod(int p[], int n){
    if(n == 0){
        return 0;
    }
    int price = INT_MIN;
    for(int i = 1; i <= n; i++){
        price = max(price, p[i]+cutRod(p, n-i));
    }
    return price;
}

int main(){
    int price[] = {0,1,5,8,9,10,17,17,20,24,30};
    cout<<cutRod(price, 40)<<endl;
    return 0;
}