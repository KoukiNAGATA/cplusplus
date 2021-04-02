#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int tmp = int(x * 100 / 108);
    for (int i = tmp - 1; i <= tmp + 1; i++)
    { //近傍の値を調べる
        if (x == i * 108 / 100)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << ":("
         << "\n";
    return 0;
}
