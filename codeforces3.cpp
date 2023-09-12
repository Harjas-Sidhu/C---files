#include <iostream>
using namespace std;

int main(){
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if (c%2 == 0)
        {
            if(a-1>=b){
                cout << "First" << endl;
            }
            else{
                cout << "Second" << endl;
            }
        }
        else{
            if(a>b-1){
                cout << "First" << endl;
            }
            else{
                cout << "Second" << endl;
            }
        }
    }
    
}