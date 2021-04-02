#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int cnt = 0;
    int tmp = 0;
    cin >> N;
    std::vector<int> x(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
        if (x[i] >= tmp)
        {
            cnt++;
            tmp = x[i];
        }
    }

    cout << cnt << "\n";
    return 0;
}