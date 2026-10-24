#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    ll ans = 0;
    for (ll i = 0; i < k; i++){

        if (y-x < x + i){
            ans+= (y-x) * (k-i);
            break;
        }
        else{
            ans+= (y-x) % (x+i);
        }
    }

    cout << ans << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
