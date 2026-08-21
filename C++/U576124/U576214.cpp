#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

typedef unsigned long long ull;
const int base = 233;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string line;
    getline(cin, line); // 吃掉第一行后面的换行符

    unordered_map<ull, int> mp;
    mp.reserve(n * 2 + 1);
    mp.max_load_factor(0.7);

    while (n--) {
        getline(cin, line);
        if (line.empty()) continue;

        size_t pos = line.find(' ');
        string op = line.substr(0, pos);
        string str = (pos == string::npos) ? "" : line.substr(pos + 1);

        ull h = 0;
        for (char ch : str) {
            h = h * base + (unsigned char)ch;
        }
        if (op == "add") {
            mp[h]++;
        } else {
            cout << (mp.find(h) != mp.end() ? "yes\n" : "no\n");
        }
    }

    return 0;
}