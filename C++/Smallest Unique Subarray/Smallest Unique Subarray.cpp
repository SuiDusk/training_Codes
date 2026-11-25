#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int MOD = 1e9 + 7;
const int base = 11451;
const int MAXN = 1e5 + 5;

class Solution
{
public:
    int smallestUniqueSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> h(n + 5);
        vector<int> powbase(n + 5);
        pre_pow(nums.size(), powbase);

        int i = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                h[i + 1] = nums[i] % MOD;
            else
                h[i + 1] = ((base * h[i]) % MOD + nums[i]) % MOD;
        }
        int l = 1, r = nums.size();
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, h, powbase))
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l - 1;
    }

    int check(int x, vector<int> &h, vector<int> &powbase)
    {
        int ans = 0;
        int n = h.size();
        map<int, int> mp;
        for (int i = x; i <= n; i++)
        {
            int t = (h[i] - (h[i - x] * powbase[x]) % MOD + MOD) % MOD;
            mp[t]++;
            if (mp[t] == 1)
                ans++;
            else
                ans--;
        }
        return ans;
    }

    void pre_pow(int x, vector<int> &powbase)
    {
        powbase[0] = 1;
        for (int i = 1; i <= x; i++)
        {
            powbase[i] = (powbase[i - 1] * base) % MOD;
        }
        return;
    }
};

int main()
{
    return 0;
}