#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    if (n == 2 || n == 3){
        cout << "NO SOLUTION";
    }

    else if (n == 1 || n == 0){
        cout << n;
    }
    else {
        for (ll i=1; i<=n; i++){
            if (i % 2 == 0) cout << i << " ";
        }

        for (ll i=1; i<=n; i++){
            if (i % 2 == 1) cout << i << " ";
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
