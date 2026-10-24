#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll binpow(ll a, ll n) {
    if (n == 0) return 1;
    
    ll res = binpow(a, n/2);

    if (n % 2 == 0){
        return res * res;
    }

    else{
        return a * res * res;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* cin >> a >> n; */
    ll a = 3;
    ll n = 13;

    int ans = binpow(a, n);

    cout << ans;
    return 0;
}
