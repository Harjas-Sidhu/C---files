#include <bits/stdc++.h>
using namespace std;

int main(){
    int price[] = {0,1,5,8,9,10,17,17,20,24,30};
    int n = 4;
    int r[n+1];
    r[0] = 0;
    for(int i = 1; i <= n; i++){
        int pri = INT_MIN;
        for(int j = 1; j <= i; j++){
            pri = max(pri, price[j]+r[i-j]);
        }
        r[i] = pri;
        cout<<"r["<<i<<"]: "<<r[i]<<endl;
    }
    cout<<r[n]<<endl;
    return 0;
}