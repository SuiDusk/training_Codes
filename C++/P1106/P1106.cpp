#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define ll long long

using namespace std;

string s;

int k;
int len;

int main()
{
    cin >> s >> k;
    int i = 0;
    while (k--)
    {
        for (i = 0; s[i] <= s[i + 1]; i++)
            ;
        s.erase(i, 1);
    }
    while (s[0] == '0' && s.size() > 1)
        s.erase(0, 1);
    cout << s << endl;
    return 0;
}