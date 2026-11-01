#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

const ll MOD = 1000000000 + 7;

#define pb push_back
#define fi first
#define se second


void solve() {
    ull x, y;
    cin >> x >> y;

    ull m = min(x, y);
    ull n = max(x, y);

    if ((2*m - n) % 3 == 0 && (2*n - m) % 3 == 0 && 2*m >= n) cout << "YES" << endl;
    else if (m == 0 && n == 0) cout << "YES" << endl;
    else cout << "NO" <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
