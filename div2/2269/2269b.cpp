#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

int f(int x){
    ll s = 0;
    while (x > 0){
        int d = x % 10;
        s+=d*d;
        x/=10;
    }
    return s;
}
void solve() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < 700; i++){
        for (int j = 0; j < n; j++){
            a[j] = f(a[j]);
        }
    }
    

    map<int, int> freq;

    for (int x : a) freq[x]++;

    int ans = 0;

    for (auto& [num, cnt] : freq){
        ans += cnt*(cnt-1)/2;
    }

    cout << ans << endl;
    
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
