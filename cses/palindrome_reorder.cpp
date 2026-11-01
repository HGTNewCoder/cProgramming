#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll MOD = 1000000000 + 7;

void solve() {
    string s;
    cin >> s;

    int cnt[26];

    for (int i = 0; i < 26; i++) cnt[i] = 0;

    // Count alphabets
    for (int i = 0; i < s.size(); i++){
        cnt[int(s[i]) - 65] += 1; // 65 for 'A' and 90 for 'Z'
    }

    // Validation
    int stopCnt = 0;
    int midIndex = -1;
    for (int i=0; i < 26; i++){
        if (stopCnt > 1){
            break;
        }
        else{
            if (cnt[i]%2 == 1){
                midIndex = i;
                stopCnt += 1;
            }
        }
    }
    /* for (int i =0; i < 26; i++){ */
    /*     cout << char(i) << " " << cnt[i] << endl; */
    /* } */


    // Construct
    if (stopCnt <= 1){
        char o[s.size()];

        ll k = 0;
        for (int i = 0; i < 26; i++){
            if (i != midIndex){
                for (int j = 0; j < cnt[i]/2; j++){
                    o[k] = char(i + 65);
                    o[s.size() - k - 1] = char(i + 65);
                    k+=1;
                }
            }

            else{
            }
        }

        if (midIndex != -1){
            for (int i = 0; i < cnt[midIndex]; i++){
                o[k] = char(midIndex + 65);
                k+=1;
            }
        }


        for (int i = 0; i < s.size(); i++){
            cout << o[i];
        }
    }
    else {
        cout << "NO SOLUTION" << endl;
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
