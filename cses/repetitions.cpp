#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    getline(cin, s);

    ll max = 1;
    ll cnt = 1;
    for (ll i = 1; i < s.size(); i++){
        if (s[i] == s[i-1]){
            cnt+=1;
            if (cnt > max) max = cnt;
        }
        else cnt = 1;
    }

    cout << max;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
