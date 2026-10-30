#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define fi first
#define se second


void solve() {
    int n, k;
    cin >> n;
    cin >> k;
    int a[n];
    int max = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > max) max = a[i];
    }

    int cnt[max+2];
    for (int i = 0; i < max+2; i++) cnt[i] = 0; // init
    
    int s = 0;
    for (int i = 0; i < n; i++){
        if (cnt[a[i]] < k) cnt[a[i]] +=1;
        else s+=1;
    } 

    for (int i = 0; i < max+2; i++){
        if (s == 0) break;
        else {
            if (cnt[i] < k && cnt[i] > 0){
                cnt[i] += 1;
                s-=1;
            }
        }
    }

    for (int i = 0; i < max+2; i++){
        if (cnt[i] < k){
            cout << i << endl;
            break;
        }
    }
}
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int t = 1;
        cin >> t;
        while (t--) solve();
        return 0;
    }
