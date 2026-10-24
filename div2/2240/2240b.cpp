#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;
using ull = unsigned long long;

ll phi(ll n) {
    ll result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void solve() {
    int n, m, r, c;
    cin >> n;
    cin >> m;
    cin >> r;
    cin >> c;

    ll phi_max = phi(998244353);
    ll power = (m*n - (m-c+1)*(n-r+1)) % phi_max;
    ull ans = pow(2, power);

    cout <<  ans % 998244353<< endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
