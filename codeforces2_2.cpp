#include <iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long int n = 0;
        cin >> n;
        long long int arr1[n], arr2[n], count = n;
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[j];
            if (arr1[j] - 1 > 0)
            {
                arr2[j] = arr1[j] - 1;
            }
            else
            {
                arr2[j] = arr1[j] + 1;
                count -= 2;
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (arr2[k] + count != arr1[k] && arr2[k] + count > 0)
            {
                arr2[k] += count;
                break;
            }
        }
        long long int sum1 = 0, sum2 = 0;
        for (int z = 0; z < n; z++)
        {
            sum1 += arr1[z];
            sum2 += arr2[z];
        }
        // cout<<"sum1: "<<sum1<<" sum2: "<<sum2<<endl;

        if (sum1 == sum2)
        {
            bool flag = true;
            for (int l = 0; l < n; l++)
            {
                if (arr2[l] == arr1[l])
                {
                    cout << "NO" << endl;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}