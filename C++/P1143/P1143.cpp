#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
string s;

int main()
{
    cin >> n >> s >> m;
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum *= n;
        if (isalpha(s[i]))
            sum += s[i] - 'A' + 10;
        else
            sum += s[i] - '0';
    }
    s = "";
    if (sum == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    while (sum != 0)
    {
        if (sum % m >= 10)
        {
            s += sum % m - 10 + 'A';
        }
        else
        {
            s += sum % m + '0';
        }
        sum /= m;
    }
    len = s.length();
    for (int i = len - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    cout << endl;
    return 0;
}