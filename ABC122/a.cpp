#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    string b;
    cin >> b;
    if (b == "A")
    {
        cout << "T"
             << "\n";
        return 0;
    }
    else if (b == "T")
    {
        cout << "A"
             << "\n";
        return 0;
    }
    else if (b == "G")
    {
        cout << "C"
             << "\n";
        return 0;
    }
    else if (b == "C")
    {
        cout << "G"
             << "\n";
        return 0;
    }
}