#include <iostream>
#include <algorithm>

#include <bits/stdc++.h>

using namespace std;

long long int talesOfSort(long long int arr[], int n)
{



    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[i] = arr[i] - 1;
        }
    }

    long long int flag = is_sorted(arr, arr + n);
    if (flag)
    {

        return 1;
    }
    else
    {
        return 1 + talesOfSort(arr, n);
    }
}

long long int checkSort(long long int arr[], int n)
{

    bool check = is_sorted(arr, arr + n);
    if (check)
        return true;
    else
        false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool flag = true;
        long long int ping = checkSort(arr, n);
        if (ping == 1)
        {
            cout << 0 << endl;
            flag = false;
        }

        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > 10000)
                {

                    long long int bong = *max_element(arr, arr + n);
                    cout << bong << endl;
                    return 0;
                }
            }
            ping = checkSort(arr, n);
            if (ping == 1)
            {
                cout << 0 << endl;
            }
            else
            {
                long long int bong = talesOfSort(arr, n);
                cout << bong << endl;
            }
        }
    }
}