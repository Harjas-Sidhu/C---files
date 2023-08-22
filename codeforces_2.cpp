#include <iostream>
using namespace std;

int main(){
    int t = 0;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n = 0;
        int sum = 0;
        int b = 0;
        cin>>n;
        for(int j = 0; j < n; j++){
            int k = 0;
            cin>>k;
            if(j == 0){
                b = k%2;
            }
            else{
                sum += k;
            }
        }
        if (b== sum%2)
        {
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}