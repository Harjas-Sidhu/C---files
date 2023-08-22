#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int counter = 0;

int round(int num){
    int k = num;
    int n = pow(10, counter);
    int r = num%n;
    if(r%10 > 4){
        counter++;
        if((num%(int)(pow(10, counter)))%10 < 9){
            num -= r;
            num += num%(int)(pow(10, counter));
            if (num%(int)(pow(10, counter))%10 > 4)
            {
                return round(num);
            }
            
        }
        else{
            while(num%(int)(pow(10, counter))%10 > 8){
                counter++;
            }
            num += num%(int)(pow(10, counter));
            if (num%(int)(pow(10, counter))%10 > 4)
            {
                return round(num);
            }
        }
    }
    return num;
}

int main(){
    int t = 0;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int n = 0;
        cin>>n;
        cout<<round(n)<<endl;
    }
    
    return 0;
}