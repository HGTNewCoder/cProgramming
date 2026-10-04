#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    if (k > (y-2*x)){
        ll ans = (y-x) * (k-y+2*x-1);
        for (int i = 0; i < y - 2*x; i++){
            ans+= (y-x) % (x+i);
        }

        cout << ans << endl;
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    /* cin >> t; */
    while (t--) solve();
    return 0;
}
