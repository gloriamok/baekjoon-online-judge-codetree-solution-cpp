#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int count0 = 1, count1 = 0;
        cin >> a;
        for (int j = 1; j <= a; j++)
        {
            int temp = count1; // ﻿f(k+1)의 count0은 f(k)의 count1이고,
            count1 = count0 + count1; // f(k+1)의 count1은 f(k)의 count0+count1
            count0 = temp;
        }
        cout << count0 << " " << count1 << "\n";
    }
}