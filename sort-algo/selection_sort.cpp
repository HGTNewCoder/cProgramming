#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

using ll = long long;

void selection_sort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
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


