#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

ll compute(ll n){
    return 12*n*n - 44 + (n*n - 5)*(4*n - 12) + (n*n - 7)*(4*n - 16) + (n*n -9)*(n*n - 8*n + 16);
}
void solve() {
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++){

        if (i == 1) cout << 0 << endl;
        if (i == 2) cout << 6 << endl;
        if (i == 3) cout << 28 << endl;
        if (i == 4) cout << 96 << endl;
        if (i >= 5) {
            ll c = compute(i);
            cout << c/2 << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
