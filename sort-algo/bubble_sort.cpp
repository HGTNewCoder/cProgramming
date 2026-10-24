#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void bubble_sort(int a[], int n){
    for (int i = 0; i < n-1; i++){
        if (a[i+1] < a[i]){
            int temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    bubble_sort(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    cout << endl;

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

