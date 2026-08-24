#include <iostream>
#include <cstdio>
using namespace std;
char danwei[] = {"SBQWY"};
string s;
void zhengshu(string str)
{
    string c[10];
    int cnt = 1, len = str.length(), dw = 1;
    int index = len % 4;
    if (index == 0)
        index += 4;
    for (int i = 0; i < len; i++)
    {
        c[cnt] += str[i];
        index--;
        if (index == 0)
            index = 4, cnt++, dw++;
    }
    cnt--;
    // cout << "cnt=" << cnt << endl;
    // cout << c[1] << endl;
    // cout << c[2] << endl;
    for (int i = 1; i <= cnt; i++)
    {
        int len1 = c[i].length();
        // cout << len1 << endl;
        if (len1 == 1)
            cout << c[i];
        else if (len1 == 2)
        {
            cout << c[i][0] << "S";
            if (c[i][1] != '0')
                cout << c[i][1];
        }
        else if (len1 == 3)
        {
            cout << c[i][0] << "B";
            if (c[i][1] != '0')
            {
                cout << c[i][1] << "S";
                if (c[i][2] != '0')
                    cout << c[i][2];
            }
            else if (c[i][2] != '0')
                cout << "0" << c[i][2];
        }
        else
        {
            int p = 0;
            if (c[i][0] != '0')
            {
                cout << c[i][0] << "Q";
                if (c[i][1] != '0')
                {
                    cout << c[i][1] << "B";
                    if (c[i][2] != '0')
                    {
                        cout << c[i][2] << "S";
                        if (c[i][3] != '0')
                            cout << c[i][3];
                    }
                    else if (c[i][3] != '0')
                    {
                        cout << "0" << c[i][3];
                    }
                }
                else if (c[i][2] != '0')
                {
                    cout << "0" << c[i][2] << "S";
                    if (c[i][3] != '0')
                        cout << c[i][3];
                }
                else if (c[i][3] != '0')
                {
                    cout << "0" << c[i][3];
                }
            }
            else if (c[i][1] != '0')
            {
                cout << "0" << c[i][1] << "B";
                if (c[i][2] != '0')
                {
                    cout << c[i][2] << "S";
                    if (c[i][3] != '0')
                        cout << c[i][3];
                }
                else if (c[i][3] != '0')
                {
                    cout << "0" << c[i][3];
                }
            }
            else if (c[i][2] != '0')
            {
                cout << "0" << c[i][2] << "S";
                if (c[i][3] != '0')
                    cout << c[i][3];
            }
            else if (c[i][3] != '0')
            {
                cout << "0" << c[i][3];
            }
        }
        if (dw > 2)
        {
            if (len1 == 4 && c[i] != "0000")
                cout << danwei[dw];
            else if (len1 == 3 && c[i] != "000")
                cout << danwei[dw];
            else if (len1 == 2 && c[i] != "00")
                cout << danwei[dw];
            else if (len1 == 1 && c[i] != "0")
                cout << danwei[dw];
            dw--;
        }
    }
}
int main()
{
    cin >> s;
    int index = 0, len = s.length();
    if (s[index] == '-')
    {
        cout << "F";
        index++;
    }
    else if (s[index] == '+')
        index++;
    int D = len - 1;
    for (int i = 0; i < len; i++)
        if (s[i] == '.')
            D = i;
    long long sum = 0;
    for (int i = index; i < D; i++)
    {
        sum = (sum * 10 + s[i] - '0');
    }
    for (int i = index; i < D; i++)
    {
        if (s[i] == '0')
            index++;
        else
            break;
    }
    if (D == len - 1 && s[D] != '.')
        s += ".", D++, len++;
    string str = s.substr(index, D - index);
    // cout << str << endl;
    if (sum == 0)
    {
        cout << "0";
    }
    else
    {
        zhengshu(str);
    }
    if (D != len - 1)
    {
        cout << "D";
        cout << s.substr(D + 1, len - D);
    }
    return 0;
}