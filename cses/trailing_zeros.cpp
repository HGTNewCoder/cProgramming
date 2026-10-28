#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    ll n;
    cin >> n;

    ll s=0;

    for (int i = 5; i <= n; i*=5){
        s+= n/i;
        if (n/i == 0) break;
    }

    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
