#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
string s;
int cnt[15];
int main()
{
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            cnt[s[i] - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--)
    {
        while (cnt[i] > 0)
        {
            printf("%d", i);
            cnt[i]--;
        }
    }
    return 0;
}