#include <bits/stdc++.h>
using namespace std;

bool splitArray(int *arr, int size) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < size; i++)
    {
        if(arr[i]%5 == 0){
            sum1 += arr[i];
        }
        else if(arr[i]%3 == 0){
            sum2+=arr[i];
        }
        else{
            sum3+=arr[i];
        }
    }
    return ((sum1 == sum2 && (abs(sum3 - abs(sum2-sum1))%2 == 0))?true:false);
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete[] input;
	return 0;

}