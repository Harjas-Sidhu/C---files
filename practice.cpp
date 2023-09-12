#include <iostream>
#include <vector>
using namespace std;

vector <int> divisors_of(int n){
    vector <int> result = {-1};
    for (int i = 2; i < n; i++)
    {
        if(n%i == 0){
            result.pop_back();
            result.push_back(i);
        }
    }
    return result;
}
class Class1{
    private:
        int pass;
    public:
        void set_pass(int new_pass){
            pass = new_pass;
        }
        int get_pass(){
            return pass;
        }
};

int main(){
    Class1 Object1;
    Object1.set_pass(100);
    cout << Object1.get_pass() << endl;
    int n;
    cin >> n;
    vector <int> res = divisors_of(n);
    vector <int> :: iterator i;
    for (i = res.begin(); i != res.end(); i++)
    {
        cout << *i << endl;
    }
    
    return 0;
}