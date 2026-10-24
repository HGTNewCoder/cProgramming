#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    ll e_sum = n*(n+1)/2;
    ll sum = 0;
    ll a = 0;
    
    for (ll i = 0; i < n-1; i++){
        cin >> a;
        sum += a;
    }

    cout << e_sum - sum;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
