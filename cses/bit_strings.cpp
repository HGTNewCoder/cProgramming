#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const long long MOD = 1000000000 + 7;

ll binary_power(ll a, ll n){
    if (n == 0) return 1;
    
    ll res = binary_power(a, n/2) % MOD;

    if (n % 2 == 0){
        return res*res % MOD;
    }
    else {
        return res*res*a % MOD;
    }
}
void solve() {
    int n;
    cin >> n;

    ull ans = binary_power(2, n);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
