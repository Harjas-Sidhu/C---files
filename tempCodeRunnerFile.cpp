//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    vector <string> v;
	    for(int i = 0; i < s.length(); i++){
	        ostringstream oss;
	        oss<<s[i];
	        if(find(v.begin(), v.end(), s[i]) != v.end()){
	            v.push_back(oss.str());
	        }
	        for(int j = i+1; j<s.length(); j++){
	            oss<<s[j];
	            if(find(v.begin(), v.end(), oss.str()) != v.end()){
	                v.push_back(oss.str());
	            }
	        }
	    }
	    return v.size();
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends