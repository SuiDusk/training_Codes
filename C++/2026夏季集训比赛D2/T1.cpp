#include <iostream>
#include <cstdio>
using namespace std;
int n;
string s;
string pi = "314159265358979323846264338327";
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == pi[i])
                ans++;
            else
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}