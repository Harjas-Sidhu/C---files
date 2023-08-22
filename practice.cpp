#include <iostream>
using namespace std;

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
    return 0;
}