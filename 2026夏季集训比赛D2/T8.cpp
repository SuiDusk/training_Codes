#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll count_factor(ll x, ll p) {
    ll res = 0;
    while (x % p == 0) {
        res++;
        x /= p;
    }
    return res;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll c2 = count_factor(n, 2);
        ll c5 = count_factor(n, 5);
        ll best_k = m;
        for (int target = 0; target <= 30; target++) {
            ll cur2 = c2, cur5 = c5;
            ll need = 1;
            while (min(cur2, cur5) < target) {
                if (cur2 < cur5) {
                    need *= 2;
                    cur2++;
                } else {
                    need *= 5;
                    cur5++;
                }
                if (need > m) break;
            }
            if (need > m) continue;
            ll rem = m / need;
            ll cand_k = need * rem;
            auto get_zero = [&](ll kk) {
                ll a2 = count_factor(kk, 2);
                ll a5 = count_factor(kk, 5);
                return min(c2 + a2, c5 + a5);
            };
            int z_cand = get_zero(cand_k);
            int z_best = get_zero(best_k);
            if (z_cand > z_best || (z_cand == z_best && cand_k > best_k)) {
                best_k = cand_k;
            }
        }
        cout << n * best_k << '\n';
    }
    return 0;
}