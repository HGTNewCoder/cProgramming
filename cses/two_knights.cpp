#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

void ans(ll i){
    cout << (i-4)*(i-4)*8 + 16*(i-2) << endl;
}


void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) ans(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
