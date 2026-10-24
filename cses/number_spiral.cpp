#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    ull y, x;
    cin >> y;
    cin >> x;

    if (x > y){
        if (x%2 ==1){
            cout << x*x - y + 1 << endl;
        }
        else if (x%2 ==0){
            cout << (x-1)*(x-1) + y << endl;
        }
    }

    else if (x < y){
        if (y%2 == 1){
            cout << (y-1)*(y-1) + x << endl;
        }
        else if (y%2 == 0){
            cout << y*y - x + 1 << endl;
        }
    }
    else {
        if (x % 2 == 1){
            cout << x*x - y + 1 << endl;
        }
        else{
            cout << y*y - x + 1 << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
