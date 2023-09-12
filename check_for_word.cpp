#include <bits/stdc++.h>
using namespace std;


int main(){
    string s, word;
    getline(cin, s);
    getline(cin, word);
    ostringstream well;
    bool flag = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' || s[i] == ',' || s[i] == '.'){
            if(word == well.str()){
                flag = true;
                break;
            }
            well.str("");
            i++;
        }
        well<<s[i];
    }
    if(word == well.str()){
        flag = true;
    }
    
    cout<<flag<<endl;
    return 0;
}