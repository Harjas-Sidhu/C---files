//  Problem Link:- https://codeforces.com/contest/1926/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t = 0;
    cin>>t;
    while(t--){
        int n = 0;
        string str;
        cin>>str;
        int a_count = 0, b_count = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'A'){
                a_count++;
            }
            else{
                b_count++;
            }
        }
        cout<<(a_count>b_count?"A":"B")<<endl;
    }
    return 0;
}