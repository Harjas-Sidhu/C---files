#include <iostream>
#include <string>
using namespace std;

int fancy_spending(int burles, int worth){
    int spendings = 0;
    if(burles == 0){
        return spendings;
    }
    while (burles > 0 && worth <= burles)
    {
        burles -= worth;
        spendings += 1;
    }
    if(burles == 0){
        return spendings;
    }
    while (burles > 0)
    {
        burles -= 1;
        spendings += 1;
    }
    return spendings;
}

int main(){
    int t = 0;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int burles = 0, worth = 0, reg_coins = 0, worth_coins = 0;
        cin>>burles>>worth>>reg_coins>>worth_coins;
        while(burles > 0 && worth_coins > 0 && worth <= burles){
            burles -= worth;
            worth_coins -= 1;
        }
        while(burles > 0 && reg_coins > 0){
            if(burles >= worth && reg_coins < worth && burles-reg_coins > 0){
                break;
            }
            if(burles - 1 < worth && burles-1 > 0 && reg_coins < worth){
                break;
            }
            burles -= 1;
            reg_coins -= 1;
        }
        cout<<fancy_spending(burles, worth)<<endl;
    }
    
    return 0;
}