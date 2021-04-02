#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A != C)
    {
        cout << 1 << "\n";
        return 0;
    }
    cout << 0 << "\n";
    return 0;
}
