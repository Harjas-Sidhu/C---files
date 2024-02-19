//  Problem Link:- https://codeforces.com/contest/1926/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int mat[n][n];
        int startingI = 1000000, startingJ = 1000000, endingI = -1, endingJ = -1;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int k = 0;
            cin >> k;
            for (int j = n - 1; j >= 0; j--)
            {
                mat[i][j] = k % 10;
                k /= 10;
                if (mat[i][j] == 1)
                {
                    if (i > endingI)
                    {
                        endingI = i;
                    }
                    if (j > endingJ)
                    {
                        endingJ = j;
                    }
                    if (j < startingJ)
                    {
                        startingJ = j;
                    }
                    if (i < startingI)
                    {
                        startingI = i;
                    }
                }
            }
        }
        for (int i = startingI; i <= endingI; i++)
        {
            for (int j = startingJ; j <= endingJ; j++)
            {
                if (mat[i][j] != 1)
                {
                    cout << "TRIANGLE" << endl;
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            cout << "SQUARE" << endl;
        }
    }
    return 0;
}