#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    ll a[n];
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }

    ll sum = 0;
    for (ll i = 1; i < n; i++){
        if (a[i] < a[i-1]){
            sum += (a[i-1] - a[i]);
            a[i] = a[i-1];

        }
    }

    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
