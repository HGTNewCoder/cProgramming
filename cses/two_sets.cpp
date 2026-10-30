#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n;
    cin >> n;

    if (n % 4 == 0 || n % 4 == 3){
        cout << "YES" << endl;
        ll cnt[n];
        ll numberA = 0;
        for (int i = 0; i < n; i++) cnt[i] = 0;
        ll maxN = n;
        ull s = n*(n+1)/4;
        
        while (s>0){

            if (s >= maxN){
                s-=maxN;
                cnt[maxN - 1]+=1;
                maxN-=1;
                numberA+=1;
            }
            else {
                cnt[s-1]+=1;
                s = 0;
                numberA+=1;
            }


        }
        cout << n - numberA << endl;
        for (int i = 0; i < n; i++){
            if (cnt[i] == 0) cout << i + 1 << " ";
        }
        cout << endl;
        cout << numberA << endl;

        for (int i = 0; i < n; i++){
            if (cnt[i] == 1) cout << i + 1 << " ";
       }


    }
    else cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
