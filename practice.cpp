#include <iostream>
#include <vector>
using namespace std;

vector <long long unsigned int> divisors_of(long long unsigned int n){
    vector <long long unsigned int> result = {0};
    for (long long unsigned int i = 2; i < n; i++)
    {
        if(n%i == 0){
            if(result[result.size()-1] == 0){
                result.pop_back();
            }
            result.push_back(i);
        }
    }
    return result;
}

void print(vector <long long unsigned int> res){
    vector <long long unsigned int> :: iterator i;
    for (i = res.begin(); i != res.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

int main(){
    long long unsigned int n;
    cin >> n;
    vector <long long unsigned int> res = divisors_of(n);
    print(res);
    return 0;
}