#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcdll(ll a, ll b) { return b == 0 ? a : gcdll(b, a % b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;
        cout << gcdll(a[0], a[n - 1]) << '\n';
    }
    return 0;
}
