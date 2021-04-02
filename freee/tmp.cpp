#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        reverse(s.begin(), s.end());
        if (s[0] == 's' || s[0] == 'o' || s[0] == 'x')
        {
            reverse(s.begin(), s.end());
            cout << s << "es"
                 << "\n";
        }
        else if ((s[0] == 'h' && s[1] == 's') || (s[0] == 'h' && s[1] == 'c'))
        {
            reverse(s.begin(), s.end());
            cout << s << "es"
                 << "\n";
        }
        else if (s[0] == 'f')
        {
            reverse(s.begin(), s.end());
            s.pop_back();
            cout << s << "ves"
                 << "\n";
        }
        else if (s[0] == 'e' && s[1] == 'f')
        {
            reverse(s.begin(), s.end());
            s.pop_back();
            s.pop_back();
            cout << s << "ves"
                 << "\n";
        }
        else if (s[0] == 'y' && s[1] != 'a' && s[1] != 'i' && s[1] != 'u' && s[1] != 'e' && s[1] != 'o')
        {
            reverse(s.begin(), s.end());
            s.pop_back();
            cout << s << "ies"
                 << "\n";
        }
        else
        {
            reverse(s.begin(), s.end());
            cout << s << "s"
                 << "\n";
        }
    }
    return 0;
}