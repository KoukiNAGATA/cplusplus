#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, ans;
    cin >> N;
    vector<int> Mon(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Mon[i];
    }
    int min = *std::min_element(Mon.begin(), Mon.end());
    ans = min;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (Mon[i] > Mon[j])
            {
                int tmp = Mon[i] % Mon[j];
                if (tmp == 1)
                {
                    cout << tmp << "\n";
                    return 0;
                }
                if (tmp < min && tmp > 0 && ans > tmp)
                {
                    ans = tmp;
                }
                tmp += Mon[j];
                for (int k = 0; k < N; k++)
                {
                    int tm = tmp % Mon[k];
                    if (tm == 1)
                    {
                        cout << tm << "\n";
                        return 0;
                    }
                    if (tm < min && tm > 0 && ans > tm)
                    {
                        ans = tm;
                    }
                }
            }
            else if (Mon[j] > Mon[i])
            {
                int tmp = Mon[j] % Mon[i];
                if (tmp == 1)
                {
                    cout << tmp << "\n";
                    return 0;
                }
                if (tmp < min && tmp > 0 && ans > tmp)
                {
                    ans = tmp;
                }
                tmp += Mon[i];
                for (int k = 0; k < N; k++)
                {
                    int tm = tmp % Mon[k];
                    if (tm == 1)
                    {
                        cout << tm << "\n";
                        return 0;
                    }
                    if (tm < min && tm > 0 && ans > tm)
                    {
                        ans = tm;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}